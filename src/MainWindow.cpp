#include "rosneuro_visualizer/MainWindow.hpp"


MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), 
										   ui_(new Ui::NeuroVizPanel) {

	this->ui_->setupUi(this);
	this->NumChannels_shown_ = 0;
	this->LbChannels_shown_  = QList<QString>();

	this->data_plot_.setup(this->ui_->eegScope);

	this->ui_->TopicButton->setDisabled(true);
	this->ui_->infoButton->setDisabled(true);

	
	QObject::connect(this->ui_->TopicButton, SIGNAL(clicked()), SLOT(on_TopicButton()));
	QObject::connect(this->ui_->infoButton, SIGNAL(clicked()), SLOT(on_InfoButton()));
	QObject::connect(this->ui_->TopicValue, SIGNAL(returnPressed()), SLOT(on_TopicValueChanged()));
	QObject::connect(this->ui_->ChannelsList, SIGNAL(itemSelectionChanged()), SLOT(on_ChannelsChanged()));
	QObject::connect(&(this->thread_),&DataThread::sig_info_samplerate,this,&MainWindow::on_InfoSamplerate);
	QObject::connect(&(this->thread_),&DataThread::sig_info_channels,this,&MainWindow::on_InfoChannels);
	QObject::connect(&(this->thread_),&DataThread::sig_info_data,this,&MainWindow::on_InfoData);
	QObject::connect(&(this->thread_),&DataThread::sig_info_message_sequence,this, &MainWindow::on_InfoMessageSequence);
	QObject::connect(&(this->thread_),&DataThread::sig_info_message_rate,this, &MainWindow::on_InfoMessageRate);
	QObject::connect(&(this->thread_),&DataThread::sig_data_available,this, &MainWindow::on_DataAvailable);
}

MainWindow::~MainWindow(void) {
	delete this->ui_;
}

void MainWindow::on_TopicButton(void) {
	this->ui_->TopicStatus->setText("Idle");
	this->ui_->TopicButton->setDisabled(true);
	this->ui_->infoButton->setDisabled(true);

	// and stop thread
	this->thread_.stopThread();
}

void MainWindow::on_InfoButton(void) {

	QMessageBox msgBox(this);
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setWindowTitle("neuroviz | data information");
	msgBox.setText(this->data_info_);
	msgBox.exec();
}

void MainWindow::on_TopicValueChanged(void) {

	if(this->ui_->TopicValue->text().isEmpty() == false) {
		this->ui_->TopicButton->setEnabled(true);
		this->ui_->infoButton->setEnabled(true);
		this->data_info_.clear();
		this->ui_->TopicStatus->setText("Running");
		this->thread_.setTopic(this->ui_->TopicValue->text().toStdString());
		this->thread_.startThread();
	}

}

void MainWindow::on_InfoSamplerate(unsigned int samplerate) {
	QString qsamplerate = "~";
	if (samplerate != 0)
		qsamplerate = QString::number(samplerate);

	this->ui_->NativeRateLabel->setText(qsamplerate + " Hz");
	this->max_buffer_size_ = samplerate * this->max_time_window_;
	this->samplerate_ = samplerate;
}

void MainWindow::on_InfoMessageSequence(unsigned int sequence) {
	this->ui_->MessageSeqLabel->setText(QString::number(sequence));
}

void MainWindow::on_InfoMessageRate(float rate) {
	QString qrate = "~";
	if (rate != 0)
		qrate = QString::number(rate, 'G', 3);
	this->ui_->MessageRateLabel->setText(qrate + " Hz");
}

void MainWindow::on_InfoChannels(QList<QString> labels) {

	this->LbChannels_ = labels;
	this->ui_->ChannelsList->clear();

	for(auto it = labels.begin(); it != labels.end(); ++it) {
		this->ui_->ChannelsList->addItem(*it);
	}
	this->ui_->ChannelsList->selectAll();

	this->NumChannels_shown_ = this->LbChannels_.size();
	this->LbChannels_shown_  = labels;

	// TEMP
	this->buffer_.reset(this->max_buffer_size_, this->LbChannels_.size());
}

void MainWindow::on_InfoData(QString info) {
	this->data_info_ = info;
}

void MainWindow::on_DataAvailable(std::vector<float> data) {

	//unsigned int nchannels = this->LbChannels_.size();
	//unsigned int nsamples  = data.size()/nchannels;

	//// Update internal buffer

	//printf("Data size: %d\n", data.size());
	//printf("NumChannels: %d\n", nchannels);
	//printf("Samples: %d\n", nsamples);
	//unsigned int cstart, cstop;
	//for(auto i=0; i<data.size(); i=i+nchannels) {
	//	cstart = i;
	//	cstop  = i+ nchannels - 1;
	//	printf("[%d %d]\n", cstart, cstop); 
	//	std::vector<float> tvect = {data.begin() + cstart, data.begin() + cstop}; 
	//	this->buffer_.push_back(tvect);
	//}

	//printf("Buffer size: %d\n", this->buffer_.size());
	//while(this->buffer_.size() > this->max_buffer_size_)
	//	this->buffer_.pop_front();

	////this->buffer_.push_back(data.data);
	
	this->buffer_.add(data);	



	//this->data_plot_.draw(this->NumChannels_shown_, this->LbChannels_shown_);
	this->data_plot_.draw2(this->buffer_, this->NumChannels_shown_, this->LbChannels_shown_);
}

void MainWindow::on_ChannelsChanged(void) {
	this->LbChannels_shown_.clear();
	QList<QListWidgetItem *> itemList = this->ui_->ChannelsList->selectedItems();
	
	for(auto it=itemList.begin(); it!=itemList.end(); ++it) {
		this->LbChannels_shown_.push_back((*it)->text());
	}
	this->NumChannels_shown_ = this->LbChannels_shown_.size();
}


