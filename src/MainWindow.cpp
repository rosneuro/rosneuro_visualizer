#include "rosneuro_visualizer/MainWindow.hpp"


MainWindow::MainWindow(NeuroDataManagement* system, QWidget *parent) : system_(system),
																	   QMainWindow(parent), 
										  							   ui_(new Ui::NeuroVizPanel) {

	this->ui_->setupUi(this);

	this->is_scope_running_ = false;
	QObject::connect(this->ui_->TopicButton, SIGNAL(clicked()), SLOT(on_TopicButtonToggled()));
	QObject::connect(this->ui_->TopicValue, SIGNAL(returnPressed()), SLOT(on_TopicValueChanged()));

}

MainWindow::~MainWindow(void) {
	delete this->ui_;
}

void MainWindow::on_TopicButtonToggled(void) {
	this->toggle_running_state();
}

void MainWindow::on_TopicValueChanged(void) {

	if(this->ui_->TopicValue->text().isEmpty() == false) {
		this->toggle_running_state();
	}

}

void MainWindow::toggle_running_state(void) {
	if(this->is_scope_running_ == true) {
		this->is_scope_running_ = false;
		this->ui_->TopicButton->setText("Run");
	} else {
		this->is_scope_running_ = true;
		this->ui_->TopicButton->setText("Stop");
	}
}


