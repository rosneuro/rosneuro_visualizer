#include <ros/ros.h>
#include "rosneuro_visualizer/MainWindow.hpp"
#include "rosneuro_msgs/NeuroDataFloat.h"
#include "rosneuro_msgs/NeuroFrame.h"


int main(int argc, char** argv) {
	QApplication app(argc, argv);

	ros::init(argc, argv, "neuroviz");

	qRegisterMetaType<rosneuro_msgs::NeuroFrame>();
	qRegisterMetaType<std::vector<float>>();
	qRegisterMetaType<QList<QString>>();
	MainWindow window;

	window.show();
	int retcod = app.exec();
	return retcod;
}

