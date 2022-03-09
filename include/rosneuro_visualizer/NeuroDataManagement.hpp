#ifndef NEURODATA_MANAGEMENT_HPP
#define NEURODATA_MANAGEMENT_HPP

#include <mutex>
#include <thread>
#include <ros/ros.h>

#include "rosneuro_msgs/NeuroFrame.h"



class NeuroDataManagement {

	public:
		NeuroDataManagement(void);
		virtual ~NeuroDataManagement(void);

		bool configure(void);
		void SetTopic(const std::string& topic);
		unsigned int GetSampleRate(void);

		void Start(void);
		void Stop(void);
		void Join(void);
		void Run(void);

		bool IsRunning(void);

	private:
		void on_received_data(const rosneuro_msgs::NeuroFrame& msg);
	
	private:
		ros::NodeHandle		nh_;
		ros::NodeHandle		p_nh_;
		ros::Subscriber		sub_;
		std::string 		topic_;
		unsigned int 		native_samplerate_;


		std::mutex 	mutex_;
		std::thread thread_;
		bool run_;
		
};


#endif
