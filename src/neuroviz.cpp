#include <ros/ros.h>
#include "rosneuro_visualizer/MainWindow.hpp"
#include "rosneuro_visualizer/NeuroDataManagement.hpp"


int main(int argc, char** argv) {

	// QT initialization
	QApplication app(argc, argv);

	// ros initialization
	ros::init(argc, argv, "neuroviz");

	NeuroDataManagement system;

	MainWindow window(&system);

	system.Start();

	window.show();

	int retcod = app.exec();

	system.Stop();
	system.Join();

	return retcod;

}

