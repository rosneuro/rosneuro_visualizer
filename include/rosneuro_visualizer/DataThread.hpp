#ifndef ROSNEURO_VISUALIZER_DATATHREAD_HPP
#define ROSNEURO_VISUALIZER_DATATHREAD_HPP

#include <deque>
#include <QMutex>
#include <QThread>
#include <QWaitCondition>
#include <ros/ros.h>
#include <gtest/gtest_prod.h>
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
		void sig_first_message(rosneuro_msgs::NeuroFrame msg);
		void sig_message_info(unsigned int sequence, float rate);	
		void sig_data_available(rosneuro_msgs::NeuroFrame msg);

	private:


		void on_received_data(const rosneuro_msgs::NeuroFrame& msg);
		float estimate_message_rate(double nsecs);
		
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

	FRIEND_TEST(DataThreadTestSuite, Constructor);
    FRIEND_TEST(DataThreadTestSuite, Destructor);
    FRIEND_TEST(DataThreadTestSuite, StartThread);
    FRIEND_TEST(DataThreadTestSuite, Run);
    FRIEND_TEST(DataThreadTestSuite, OnReceivedData);
    FRIEND_TEST(DataThreadTestSuite, ToString);
    FRIEND_TEST(DataThreadTestSuite, EstimateMessageRate);
};
		
Q_DECLARE_METATYPE(rosneuro_msgs::NeuroFrame);

#endif
