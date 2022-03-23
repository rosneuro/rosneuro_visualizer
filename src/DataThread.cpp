#include "rosneuro_visualizer/DataThread.hpp"


DataThread::DataThread(QObject* parent) : p_nh_("~"), QThread(parent) {

	this->topic_ = "/neurodata";
	this->samplerate_ = 0;

	this->set_topic(this->topic_);
}

DataThread::~DataThread(void) {
	this->mutex_.lock();
    this->abort_ = true;
    this->mutex_.unlock();

    wait();
}

void DataThread::set_topic(const std::string& topic) {
	this->mutex_.lock();
	this->topic_ = topic;
	this->sub_ = this->nh_.subscribe(this->topic_, 1, &DataThread::on_received_data, this);
	this->mutex_.unlock();

}

void DataThread::start_thread(void) {

	this->mutex_.lock();
	if (!this->isRunning()) {
		this->start(LowPriority);
		this->restart_ 	 = true;
		this->abort_ = false;
	} else {
		this->restart_ 	 = true;
		this->abort_ = false;
	}
	this->mutex_.unlock();

}

void DataThread::stop_thread(void) {

	this->mutex_.lock();
	this->abort_ = true;
	this->mutex_.unlock();

	wait();
}


void DataThread::run(void) {

	ros::Rate r(4096);
	while(this->nh_.ok()) {

		// Checking control flow
		this->mutex_.lock();
		
		if(this->restart_ == true) {
			this->restart_ 		= false;
			this->first_msg_ 	= true;
			this->mr_nsecs_.clear();
			this->mutex_.unlock();
			continue;
		}
		
		if (this->abort_ == true) {
			this->abort_ = false;
			this->mutex_.unlock();
            return;
        }
		this->mutex_.unlock();


		// ROS spin
		ros::spinOnce();
		r.sleep();

	}
}


void DataThread::on_received_data(const rosneuro_msgs::NeuroFrame& msg) {

	if(this->first_msg_ == true) {
		ROS_DEBUG("[DataThread] First message received");	
		this->samplerate_ = msg.sr;
		this->first_msg_ = false;
		emit sig_first_message(msg);
	}

	// Estimate and set message rate and sequence signal
	float msg_rate;
	msg_rate = this->estimate_message_rate(ros::Time::now().toSec());
	emit sig_message_info(msg.header.seq, msg_rate);
	
	// Emit signal new frame
	emit sig_data_available(msg);
}




std::string DataThread::to_string(const rosneuro_msgs::NeuroDataInfo& info) {
	std::string str_info =	"Number of channels: " + std::to_string(info.nchannels) + "\n" + 
							"Unit: " + info.unit + "\n" +
							"Transducter: " + info.transducter + "\n" +
							"Prefiltering: " + info.prefiltering + "\n";

	str_info += "Min/max values: [ ";
	for (auto it = info.minmax.begin(); it != info.minmax.end(); ++it)
		str_info += std::to_string(*it) + " ";
	str_info += "]\n";
	
	return str_info;
}


float DataThread::estimate_message_rate(double nsecs) {

	if(this->mr_nsecs_.size() >= this->mr_queue_length_) {
		this->mr_nsecs_.pop_front();
	}

	this->mr_nsecs_.push_back(nsecs);

	if(mr_nsecs_.size() < this->mr_queue_length_) {
		return 0;
	}

	float rate;
	double difference  = 0;
	double mdifference;

	for(auto i = 1; i<this->mr_nsecs_.size(); i++) {
		difference += (this->mr_nsecs_.at(i) - this->mr_nsecs_.at(i-1));
	}
	mdifference = difference/(this->mr_nsecs_.size() - 1);

	rate = 1.0/mdifference;
	return rate;
}
