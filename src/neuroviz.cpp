#include <ros/ros.h>
#include "rosneuro_visualizer/MainWindow.hpp"


int main(int argc, char** argv) {

	// QT initialization
	QApplication app(argc, argv);

	// ros initialization
	ros::init(argc, argv, "neuroviz");

	qRegisterMetaType<QList<QString>>();
	MainWindow window;


	window.show();

	int retcod = app.exec();

	return retcod;

}

