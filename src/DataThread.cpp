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
		this->restart_ 	 = false;
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
			this->samplerate_ 	= 0;
			this->nchannels_ 	= 0;
			this->labels_ 		= QList<QString>();
			this->set_message_info(0, 0.0);
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
		ROS_INFO("First message received");	
		this->set_data_info(msg.sr, msg.eeg.info);
		this->first_msg_ = false;
	}

	// Estimate and set message rate and sequence signal
	float msg_rate;
	msg_rate = this->estimate_message_rate(ros::Time::now().toSec());
	this->set_message_info(msg.header.seq, msg_rate);
	

	//// Set sequence signal
	//this->set_message_sequence(msg.header.seq);

	//// Estimate and set message rate signal
	//float msg_rate;
	//msg_rate = this->estimate_message_rate(ros::Time::now().toSec());
	//this->set_message_rate(msg_rate);

	// Emit signal new data
	emit sig_data_available(msg.eeg.data);
}

void DataThread::set_data_info(float samplerate, const rosneuro_msgs::NeuroDataInfo& info) {

	// Sampling rate
	this->samplerate_ = samplerate;

	// Channels and labels
	this->nchannels_  = info.nchannels;
	this->labels_.clear();
	for(auto it=info.labels.begin(); it!=info.labels.end(); ++it) {
		this->labels_.push_back(QString::fromStdString(*it));
	}

	// Info string
	this->info_ = QString::fromStdString(this->to_string(info));	

	// Emit signal for data info
	emit sig_data_info(this->samplerate_, this->nchannels_, this->labels_, this->info_);

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

void DataThread::set_message_info(unsigned int sequence, float rate) {
	emit sig_message_info(sequence, rate);
}

//void DataThread::set_message_sequence(unsigned int sequence) {
//	this->sequence_ = sequence;
//	emit sig_info_message_sequence(this->sequence_);
//}
//
//void DataThread::set_message_rate(float rate) {
//	emit sig_info_message_rate(rate);
//}

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
