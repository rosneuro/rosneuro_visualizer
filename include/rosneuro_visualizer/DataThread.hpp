#ifndef DATA_THREAD_HPP
#define DATA_THREAD_HPP

#include <deque>
#include <QMutex>
#include <QThread>
#include <QWaitCondition>
#include <ros/ros.h>

#include "rosneuro_msgs/NeuroFrame.h"



class DataThread : public QThread {

	Q_OBJECT

	public:
		DataThread(QObject *parent = nullptr);
		virtual ~DataThread(void);

		void setTopic(const std::string& topic);
		void startThread(void);
		void stopThread(void);


	protected:
		void run(void) override;

	signals:
		void sig_info_samplerate(unsigned int samplerate);
		void sig_info_channels(QList<QString> labels);
		void sig_info_data(QString info);
		void sig_info_message_sequence(unsigned int sequence);
		void sig_info_message_rate(float rate);
		void sig_data_new(void);

	private:
		void on_received_data(const rosneuro_msgs::NeuroFrame& msg);
		void set_samplerate(unsigned int samplerate);
		void set_message_sequence(unsigned int sequence);
		void set_message_rate(float rate);
		void set_channels(std::vector<std::string> labels);
		void set_data_info(const rosneuro_msgs::NeuroDataInfo& info);
		float estimate_message_rate(int nsecs);
	
	private:
		ros::NodeHandle		nh_;
		ros::NodeHandle		p_nh_;
		ros::Subscriber		sub_;
		std::string 		topic_;
		unsigned int 		samplerate_;
		unsigned int 		sequence_;
		const int 			mr_queue_length_ = 100;
		std::deque<int> 	mr_nsecs_;
		QList<QString>		channels_labels_;
		QString 			data_info_;
		QMutex 			mutex_;

    	bool restart_ 	= false;
    	bool abort_   	= false;
		bool first_msg_ = true;

		
};


#endif
