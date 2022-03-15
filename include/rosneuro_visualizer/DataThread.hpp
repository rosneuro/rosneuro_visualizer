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

		void set_topic(const std::string& topic);
		void start_thread(void);
		void stop_thread(void);


	protected:
		void run(void) override;

	signals:
		void sig_data_info(float samplerate, unsigned int nchannels, QList<QString> labels, QString info); 
		void sig_data_available(std::vector<float> data);
		void sig_message_info(unsigned int sequence, float rate);	
		//void sig_info_message_sequence(unsigned int sequence);
		//void sig_info_message_rate(float rate);

	private:
		void on_received_data(const rosneuro_msgs::NeuroFrame& msg);
		void set_data_info(float samplerate, const rosneuro_msgs::NeuroDataInfo& info);
		void set_message_info(unsigned int sequence, float rate);
		float estimate_message_rate(double nsecs);
		//void set_message_sequence(unsigned int sequence);
		//void set_message_rate(float rate);
		
		std::string to_string(const rosneuro_msgs::NeuroDataInfo& info);

	private:
		ros::NodeHandle		nh_;
		ros::NodeHandle		p_nh_;
		ros::Subscriber		sub_;
		std::string 		topic_;
		
		float 				samplerate_;
		unsigned int 		nchannels_;
		QList<QString>		labels_;
		QString				info_;

		//unsigned int 		sequence_;
		const int 			mr_queue_length_ = 100;
		std::deque<double> 	mr_nsecs_;
		
		QMutex 			mutex_;

    	bool restart_ 	= false;
    	bool abort_   	= false;
		bool first_msg_ = true;

		
};

#endif
