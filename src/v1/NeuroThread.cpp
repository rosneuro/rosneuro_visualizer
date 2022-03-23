#include "rosneuro_visualizer/NeuroThread.hpp"

NeuroThread::NeuroThread(QObject* parent) : QThread(parent) {}

NeuroThread::~NeuroThread(void) {
	this->mutex_.lock();
	this->abort_ = true;
	this->mutex_.unlock();
	wait();
}

void NeuroThread::start_thread(void) {

	this->mutex_.lock();
	if (!this->isRunning()) {
		this->start(LowPriority);
		this->restart_ 	= false;
		this->abort_ 	= false;
	} else {
		this->restart_ 	= true;
		this->abort_ 	= false;
	}
	this->mutex_.unlock();

}

void NeuroThread::stop_thread(void) {

	this->mutex_.lock();
	this->abort_ = true;
	this->mutex_.unlock();

	wait();
}
