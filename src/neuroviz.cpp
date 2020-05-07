#include <ros/ros.h>
#include "rosneuro_data/NeuroData.hpp"
#include "rosneuro_data/NeuroDataTools.hpp"
#include "rosneuro_msgs/NeuroFrame.h"
#include "rosneuro_msgs/GetAcquisitionInfo.h"

#include <pthread.h>

extern "C" {
#include <mcpanel.h>
}

#if HAVE_CONFIG_H
# include <config.h>
#endif

#define PACKAGE_NAME "neuroviz"
#define PACKAGE_VERSION "0.0.1"

#define NSAMPLES	32
#define NSCALE 2
#define NTAB 1
#define MAX_UPDATE_RATE 4096
/**************************************************************************
 *                                                                        *
 *              Global variables                                          *
 *                                                                        * 
 **************************************************************************/
static const char* uifilename = nullptr;

pthread_t thread_id;
pthread_mutex_t sync_mtx = PTHREAD_MUTEX_INITIALIZER;
int run_eeg = 0;

ros::NodeHandle* p_nh;
ros::AsyncSpinner* p_spinner; 

static const char* scale_labels[NSCALE] = {"25.0mV", "50.0mV"};
static const float scale_values[NSCALE] = {25.0e3, 50.0e3};

static struct panel_tabconf tabconf[NTAB] = {
	{.type = TABTYPE_SCOPE, .name = "EEG"}
};

struct DeviceInfo {
	std::string model;
	std::string id;
};

DeviceInfo devinfo;

rosneuro_msgs::NeuroFrame neuroframe;
bool is_new_frame = false;

static int device_disconnection(void) { return 0; }
static int SetupRecording(void *user_data) { return 1; }
static int StopRecording(void* user_data) { return 1; }
static int ToggleRecording(int start, void* user_data) { return 1; }
static int ClosePanel(void* user_data) { return 1; }

static int device_connection(ros::NodeHandle* p_nh, rosneuro_msgs::NeuroFrame& neuroframe, DeviceInfo& devinfo) {

	ros::ServiceClient srv;
	rosneuro_msgs::GetAcquisitionInfo info;

	srv = p_nh->serviceClient<rosneuro_msgs::GetAcquisitionInfo>("/acquisition/get_info");

	if (srv.call(info) == false) {
		ROS_WARN("No data info from acquisition...");
		return 1;
	}

	neuroframe = info.response.frame;
	devinfo.model = info.response.device_model;
	devinfo.id    = info.response.device_id;
	return 0;

}

// EEG acquisition thread
static void* reading_thread(void* arg)
{

	mcpanel* panel = (mcpanel*) arg;
	int run_acq;

	ros::Rate r(MAX_UPDATE_RATE);

	while (ros::ok()) {
		
		// update control flags
		pthread_mutex_lock(&sync_mtx);
		run_acq = run_eeg;
		pthread_mutex_unlock(&sync_mtx);

		// Check the stop acquisition flag
		if (!run_acq)
			break;

		if (is_new_frame == true) {
			mcp_add_samples(panel, 0, neuroframe.eeg.info.nsamples, neuroframe.eeg.data.data());
			mcp_add_triggers(panel, neuroframe.tri.info.nsamples, (const uint32_t*)neuroframe.tri.data.data());
			is_new_frame = false;
		}

		r.sleep();
	}

	return 0;
}

// Connection to the system 
static int Connect(mcpanel* panel) {
	int retval;
	std::vector<char*> clabels_str;   
	float fs;

	retval = device_connection(p_nh, neuroframe, devinfo);
	if (retval)
		return retval;

    clabels_str.reserve(neuroframe.eeg.info.labels.size());

    for(auto& s: neuroframe.eeg.info.labels)
        clabels_str.push_back(&s[0]);
	
	mcp_define_tab_input(panel, 0, neuroframe.eeg.info.nchannels, neuroframe.sr, (const char**)clabels_str.data());
	mcp_define_triggers(panel, 1,  neuroframe.sr);

	pthread_mutex_lock(&sync_mtx);
	run_eeg = 1;
	pthread_mutex_unlock(&sync_mtx);
	pthread_create(&thread_id, NULL, reading_thread, panel);
	p_spinner->start();
	return 0;
}


static int Disconnect(mcpanel* panel) {
	(void)panel;

	pthread_mutex_lock(&sync_mtx);
	run_eeg = 0;
	pthread_mutex_unlock(&sync_mtx);
	p_spinner->stop();

	pthread_join(thread_id, NULL);
	device_disconnection();
	return 0;
}


static int SystemConnection(int start, void* user_data) {
	mcpanel* panel = (mcpanel*)user_data;
	int retval;

	retval = start ? Connect(panel) : Disconnect(panel);
	if (retval) {
		mcp_popup_message(panel, "No data info from acquisition");
		return 0;
	}

	return 1;
}


static char device_info[1024];
static void on_device_info(int id, void* data) {
	(void)id;
	unsigned int sampling_freq = 0, eeg_nmax = 0, trigger_nmax = 0;
	char prefiltering[128];
	mcpanel* panel = (mcpanel*) data;

	if (!run_eeg)
		return;

	snprintf(device_info, sizeof(device_info)-1,
	       "system info:\n\n"
	       "device type: %s\n"
	       "device model: %s\n"
	       "sampling frequency: %u Hz\n"
	       "num EEG channels: %u\n"
	       "num trigger channels: %u\n"
	       "prefiltering: %s\n",
	       devinfo.model.c_str(), devinfo.id.c_str(), neuroframe.sr,
	       neuroframe.eeg.info.nchannels, neuroframe.tri.info.nchannels, 
		   neuroframe.eeg.info.prefiltering.c_str());
	
	mcp_popup_message(panel, device_info);	
}

void on_received_data(const rosneuro_msgs::NeuroFrame& msg) {
	neuroframe = msg;
	is_new_frame = true;
}
/**************************************************************************
 *                                                                        *
 *              Initialization of the application                         *
 *                                                                        * 
 **************************************************************************/


int main(int argc, char* argv[])
{
	ros::init(argc, argv, "visualizer");
	ros::NodeHandle nh;
	ros::Subscriber sub;

	ros::AsyncSpinner spinner(4);
	p_nh = &nh;
	p_spinner = &spinner;
	

	sub = p_nh->subscribe("/neurodata", 1, on_received_data);


	mcpanel* panel = NULL;
	int retval = 0, retcode = EXIT_FAILURE;
	struct panel_button custom_button;
	custom_button.label    = "device info";
	custom_button.id	   = 0;
	custom_button.callback = on_device_info;

	struct PanelCb cb;
	cb.user_data	     = nullptr;
	cb.system_connection = SystemConnection;
	cb.setup_recording   = SetupRecording;
	cb.stop_recording    = StopRecording;
	cb.toggle_recording  = ToggleRecording;
	cb.close_panel		 = ClosePanel;
	cb.nbutton		     = 1;
	cb.custom_button	 = &custom_button;
	cb.confname			 = PACKAGE_NAME;

	// Process command line options
	mcp_init_lib(&argc, &argv);
	
	panel = mcp_create(uifilename, &cb, NTAB, tabconf);
	if (!panel) {
		fprintf(stderr,"error at the creation of the panel\n");
		return retcode;
	}

	// Run the panel
	mcp_show(panel, 1);
	mcp_run(panel, 0);

	if (run_eeg)
		Disconnect(panel);

	mcp_destroy(panel);
	retcode = EXIT_SUCCESS;
	ros::shutdown();

exit:
	return retcode;
}






