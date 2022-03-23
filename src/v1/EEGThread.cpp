#include "rosneuro_visualizer/EEGThread.hpp"
#include "rosneuro_visualizer/MainWindow.hpp"

EEGThread::EEGThread(Ui::NeuroVizPanel* ui, QObject* parent) : NeuroThread(parent) {
	
	QObject::connect(ui->EEGScaleValue, SIGNAL(currentIndexChanged(int)), SLOT(on_ScaleChanged(int)));

}

EEGThread::~EEGThread(void) {}

void EEGThread::run(void) {

	ros::Rate r(2);
	while(true) {

		printf("[EEGThread] Running...\n");

		// Checking control flow
		this->mutex_.lock();
		
		if(this->restart_ == true) {
			this->restart_ 		= false;
			this->mutex_.unlock();
			continue;
		}
		
		if (this->abort_ == true) {
			this->abort_ = false;
			this->mutex_.unlock();
            return;
        }
		this->mutex_.unlock();
	
		r.sleep();
	}

}

void EEGThread::on_ScaleChanged(int index) {
	this->scale_ = this->scales_.at(index);;
	printf("[EEGThread] Scale changed: %f\n", this->scale_);
}
