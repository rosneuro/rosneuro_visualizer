#include "rosneuro_visualizer/NeuroDataManagement.hpp"


NeuroDataManagement::NeuroDataManagement(void) : p_nh_("~") {

	this->mutex_.lock();
	this->run_   = false;
	this->topic_ = "/neurodata";
	this->native_samplerate_ = 0;
	this->mutex_.unlock();
}

NeuroDataManagement::~NeuroDataManagement(void) {
}

bool NeuroDataManagement::configure(void) {

	this->SetTopic(this->topic_);

	return true;
}

void NeuroDataManagement::SetTopic(const std::string& topic) {

	this->mutex_.lock();
	this->topic_ = topic;
	this->sub_ = this->nh_.subscribe(this->topic_, 1000, &NeuroDataManagement::on_received_data, this);
	this->mutex_.unlock();
}

void NeuroDataManagement::Start(void) {

	if(this->IsRunning() == true) {
		this->Stop();
		this->Join();
	}

	ROS_INFO("NeuroDataManagement is requested to start");
	this->mutex_.lock();
	this->thread_ = std::thread(&NeuroDataManagement::Run, this);
	this->run_ = true;
	this->mutex_.unlock();
}

void NeuroDataManagement::Stop(void) {
	ROS_INFO("NeuroDataManagement is requested to stop");
	this->mutex_.lock();
	this->run_ = false;
	this->mutex_.unlock();
}

void NeuroDataManagement::Join(void) {
	ROS_INFO("NeuroDataManagement is requested to join");
	this->mutex_.lock();
	this->thread_.join();
	this->mutex_.unlock();
}


bool NeuroDataManagement::IsRunning(void) {
	bool ret = false;
	this->mutex_.lock();
	ret = this->run_;
	this->mutex_.unlock();
	return ret;
}

void NeuroDataManagement::Run(void) {

	while(this->nh_.ok() && this->IsRunning()) {
		ros::spinOnce();


	}
}


void NeuroDataManagement::on_received_data(const rosneuro_msgs::NeuroFrame& msg) {

	this->mutex_.lock();
	this->native_samplerate_ = msg.sr;
	this->mutex_.unlock();

}

unsigned int NeuroDataManagement::GetSampleRate(void) {
	unsigned int sr;
	this->mutex_.lock();
	sr = this->native_samplerate_;
	this->mutex_.unlock();
	return sr;
}
