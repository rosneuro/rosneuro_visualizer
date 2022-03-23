#include "rosneuro_visualizer/EXGThread.hpp"

EXGThread::EXGThread(Ui::NeuroVizPanel* ui, QObject* parent) : NeuroThread(parent) {


	QObject::connect(ui->EXGScaleValue, SIGNAL(currentIndexChanged(int)), SLOT(on_ScaleChanged(int)));
}

EXGThread::~EXGThread(void) {}

void EXGThread::run(void) {

	ros::Rate r(2);
	while(true) {

		printf("[EXGThread] Running...\n");

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

void EXGThread::on_ScaleChanged(int index) {
	this->scale_ = this->scales_.at(index);;
	printf("[EXGThread] Scale changed: %f\n", this->scale_);
}
