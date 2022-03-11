#include "rosneuro_visualizer/DataThread.hpp"


DataThread::DataThread(QObject* parent) : p_nh_("~"), QThread(parent) {

	this->topic_ = "/neurodata";
	this->samplerate_ = 0;

	this->setTopic(this->topic_);
}

DataThread::~DataThread(void) {
	this->mutex_.lock();
    this->abort_ = true;
    this->mutex_.unlock();

    wait();
}

void DataThread::setTopic(const std::string& topic) {
	this->mutex_.lock();
	this->topic_ = topic;
	this->sub_ = this->nh_.subscribe(this->topic_, 1, &DataThread::on_received_data, this);
	this->mutex_.unlock();

}

void DataThread::startThread(void) {

	this->mutex_.lock();
	if (!this->isRunning()) {
		this->start(LowPriority);
	} else {
		this->restart_ 	 = true;
	}
	this->mutex_.unlock();

}

void DataThread::stopThread(void) {

	this->mutex_.lock();
	this->abort_ = true;
	this->mutex_.unlock();
}


void DataThread::run(void) {

	ros::Rate r(4096);
	while(this->nh_.ok()) {

		//printf("Thread running...\n");



		// Checking control flow
		this->mutex_.lock();
		
		if(this->restart_ == true) {
			printf("Restarting thread\n");
			this->restart_ = false;
			this->first_msg_ = true;
			this->set_samplerate(0);
			this->set_message_sequence(0);
			this->set_message_rate(0);
			this->set_channels(std::vector<std::string>());
			this->mr_nsecs_.clear();
			this->mutex_.unlock();
			continue;
		}
		
		if (this->abort_ == true) {
			printf("Stopping thread\n");
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
		this->set_samplerate(msg.sr);
		this->set_channels(msg.eeg.info.labels);
		this->set_data_info(msg.eeg.info);
		this->first_msg_ = false;
	}

	// Set sequence signal
	this->set_message_sequence(msg.header.seq);

	// Estimate and set message rate signal
	float msg_rate;
	msg_rate = this->estimate_message_rate(ros::Time::now().toSec());
	this->set_message_rate(msg_rate);

	// Emit signal new data
	emit sig_data_available(msg.eeg.data);
}

void DataThread::set_samplerate(unsigned int samplerate) {
	this->samplerate_ = samplerate;
	emit sig_info_samplerate(this->samplerate_);
}

void DataThread::set_message_sequence(unsigned int sequence) {
	this->sequence_ = sequence;
	emit sig_info_message_sequence(this->sequence_);
}

void DataThread::set_message_rate(float rate) {
	emit sig_info_message_rate(rate);
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
	
	//for(auto it = this->mr_nsecs_.begin(); it != std::prev(this->mr_nsecs_.end()); ++it) {
	//	//difference += std::abs(*it - *std::next(it));
	//	difference += *(std::next(it)) - *it;
	//}

	for(auto i = 1; i<this->mr_nsecs_.size(); i++) {
		difference += (this->mr_nsecs_.at(i) - this->mr_nsecs_.at(i-1));
	}
	mdifference = difference/(this->mr_nsecs_.size() - 1);

	rate = 1.0/mdifference;
	return rate;
}

void DataThread::set_channels(std::vector<std::string> labels) {

	this->channels_labels_.clear();
	for(auto it=labels.begin(); it!=labels.end(); ++it) {
		this->channels_labels_.push_back(QString::fromStdString(*it));
	}
	
	emit sig_info_channels(this->channels_labels_);
}

void DataThread::set_data_info(const rosneuro_msgs::NeuroDataInfo& info) {

	QString qinfo = "Number of channels: " + QString::number(info.nchannels) + "\n" + 
					"Unit: " + QString::fromStdString(info.unit) + "\n" +
					"Transducter: " + QString::fromStdString(info.transducter) + "\n" +
					"Prefiltering: " + QString::fromStdString(info.prefiltering) + "\n";

	qinfo += "Min/max values: [ ";
	for (auto it = info.minmax.begin(); it != info.minmax.end(); ++it)
		qinfo += QString::number(*it) + QString::fromStdString(" ");
	qinfo += "]\n";

	this->data_info_ = qinfo;
	
	emit sig_info_data(this->data_info_);
}


