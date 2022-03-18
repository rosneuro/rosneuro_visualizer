#include "rosneuro_visualizer/MainWindow.hpp"


MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), 
										   ui_(new Ui::NeuroVizPanel) {

	this->ui_->setupUi(this);
	
	this->scope_ = this->ui_->eegScope;

	this->ui_->TopicButton->setDisabled(true);
	this->ui_->InfoButton->setDisabled(true);
	this->ui_->ReferenceOpt->setDisabled(true);

	this->filter_lp_.set_type(0);
	this->filter_hp_.set_type(1);

	// UI Signals
	QObject::connect(this->ui_->TopicButton, SIGNAL(clicked()), SLOT(on_TopicButton()));
	QObject::connect(this->ui_->InfoButton, SIGNAL(clicked()), SLOT(on_InfoButton()));
	QObject::connect(this->ui_->TopicValue, SIGNAL(returnPressed()), SLOT(on_TopicValueChanged()));
	QObject::connect(this->ui_->ChannelsList, SIGNAL(itemSelectionChanged()), SLOT(on_ChannelsChanged()));
	QObject::connect(this->ui_->ScaleValue, SIGNAL(currentIndexChanged(int)), SLOT(on_ScaleChanged()));
	QObject::connect(this->ui_->TimeWindowValue, SIGNAL(currentIndexChanged(int)), SLOT(on_WindowChanged()));
	QObject::connect(this->ui_->ReferenceValue, SIGNAL(currentIndexChanged(int)), SLOT(on_ReferenceChanged()));
	QObject::connect(this->ui_->ReferenceOpt, SIGNAL(currentIndexChanged(int)), SLOT(on_RefElectrodeChanged()));
	QObject::connect(this->ui_->LowPassCheck, SIGNAL(stateChanged(int)), SLOT(on_LowPassCheckChanged()));
	QObject::connect(this->ui_->LowPassValue, SIGNAL(valueChanged(double)), SLOT(on_LowPassValueChanged()));
	QObject::connect(this->ui_->HighPassCheck, SIGNAL(stateChanged(int)), SLOT(on_HighPassCheckChanged()));
	QObject::connect(this->ui_->HighPassValue, SIGNAL(valueChanged(double)), SLOT(on_HighPassValueChanged()));

	// Thread signals
	QObject::connect(&(this->thread_),&DataThread::sig_data_info,this,&MainWindow::on_DataInfo);
	QObject::connect(&(this->thread_),&DataThread::sig_message_info,this, &MainWindow::on_MessageInfo);
	QObject::connect(&(this->thread_),&DataThread::sig_data_available,this, &MainWindow::on_DataAvailable);
}

MainWindow::~MainWindow(void) {
	delete this->ui_;
}

void MainWindow::on_TopicButton(void) {
	this->ui_->TopicStatus->setText("Idle");
	this->ui_->TopicButton->setDisabled(true);
	this->ui_->InfoButton->setDisabled(true);

	// and stop thread
	this->thread_.stop_thread();
}

void MainWindow::on_InfoButton(void) {

	QMessageBox msgBox(this);
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setWindowTitle("neuroviz | data information");
	msgBox.setText(this->info_);
	msgBox.exec();
}

void MainWindow::on_TopicValueChanged(void) {

	if(this->ui_->TopicValue->text().isEmpty() == false) {
		// UI callbacks
		this->ui_->TopicButton->setEnabled(true);
		this->ui_->InfoButton->setEnabled(true);
		this->ui_->TopicStatus->setText("Running");
	
		// Thread restart
		this->thread_.stop_thread();
		this->thread_.set_topic(this->ui_->TopicValue->text().toStdString());
		this->thread_.start_thread();            
	}                                            
}                                                
                                                
void MainWindow::on_DataInfo(float samplerate, unsigned int nchannels, 
							QList<QString> labels, QString info) {

	// Setting UI interface
	this->ui_set_samplerate(samplerate);
	this->ui_set_channels(labels);
	this->ui_set_info(info);

	// Setting internal buffer
	this->samplerate_ = samplerate;
	unsigned int nsamples = this->samplerate_ * this->window_size_;
	this->buffer_.reset(nsamples, nchannels);

	// Setting Scope panel
	this->scope_->setup(nsamples, nchannels);
	this->scope_->set_channel_labels(labels);
}

void MainWindow::on_ChannelsChanged(void) {

	this->channel_index_selected_.clear();

	for(QListWidgetItem *item: this->ui_->ChannelsList->selectedItems()){
    	this->channel_index_selected_.push_back(this->ui_->ChannelsList->row(item));
	}
}

void MainWindow::on_ScaleChanged(void) {
	int currentIdx = this->ui_->ScaleValue->currentIndex();
	
	// Setting scale on the scope
	this->scope_->set_scale(this->scales_.at(currentIdx));
}

void MainWindow::on_WindowChanged(void) {
	
	int currentIdx = this->ui_->TimeWindowValue->currentIndex();
	this->window_size_ = this->windows_.at(currentIdx);
	// Reset buffer and scope
	
	unsigned int nchannels = this->buffer_.channels();
	unsigned int nsamples  = this->window_size_ * this->samplerate_;

	this->buffer_.reset(nsamples, nchannels);
	this->scope_->setup(nsamples, this->channel_index_selected_.size());
}

void MainWindow::on_ReferenceChanged(void) {
	this->reference_ = this->ui_->ReferenceValue->currentIndex();
	if(this->reference_ == References::ELECTRODE) {
		this->ui_->ReferenceOpt->setEnabled(true);
	} else {
		this->ui_->ReferenceOpt->setDisabled(true);
	}
}

void MainWindow::on_RefElectrodeChanged(void) {

	this->ref_electrode_ = this->ui_->ReferenceOpt->currentIndex();
}

void MainWindow::ui_set_samplerate(float samplerate) {
	QString qsamplerate = "~";
	if (samplerate != 0)
		qsamplerate = QString::number(samplerate);

	this->ui_->NativeRateLabel->setText(qsamplerate + " Hz");
}

void MainWindow::on_LowPassCheckChanged(void) {

	this->is_lowpass_enabled_ = this->ui_->LowPassCheck->isChecked();

	int order = 2;
	if (this->is_lowpass_enabled_ == true) {
		this->lowpass_cutoff_ = this->ui_->LowPassValue->value();
		this->filter_lp_.setup(order, this->samplerate_, this->lowpass_cutoff_, this->buffer_.channels());
	}
}

void MainWindow::on_LowPassValueChanged(void) {

	int order = 2;
	this->lowpass_cutoff_ = this->ui_->LowPassValue->value();
	if (this->is_lowpass_enabled_ == true) {
		this->filter_lp_.setup(order, this->samplerate_, this->lowpass_cutoff_, this->buffer_.channels());
	}
}
void MainWindow::on_HighPassCheckChanged(void) {

	this->is_highpass_enabled_ = this->ui_->HighPassCheck->isChecked();

	int order = 2;
	if (this->is_highpass_enabled_ == true) {
		this->highpass_cutoff_ = this->ui_->HighPassValue->value();
		this->filter_hp_.setup(order, this->samplerate_, this->highpass_cutoff_, this->buffer_.channels());
	}
}

void MainWindow::on_HighPassValueChanged(void) {

	int order = 2;
	this->highpass_cutoff_ = this->ui_->HighPassValue->value();
	if (this->is_highpass_enabled_ == true) {
		this->filter_hp_.setup(order, this->samplerate_, this->highpass_cutoff_, this->buffer_.channels());
	}
}

void MainWindow::ui_set_channels(const QList<QString>& labels) {

	for(auto it = labels.begin(); it != labels.end(); ++it) {
		this->ui_->ChannelsList->addItem(*it);
	}
	this->ui_->ChannelsList->selectAll();
	
	for(auto it = labels.begin(); it != labels.end(); ++it) {
		this->ui_->ReferenceOpt->addItem(*it);
	}
}


void MainWindow::ui_set_info(const QString& info) {
	this->info_ = info;
}



void MainWindow::on_MessageInfo(unsigned int sequence, float rate) {
	QString qrate = "~";
	if (rate != 0)
		qrate = QString::number(rate, 'G', 3);
                                
	// Setting message rate
	this->ui_->MessageRateLabel->setText(qrate + " Hz");

	// Setting message sequence
	this->ui_->MessageSeqLabel->setText(QString::number(sequence));
}

void MainWindow::on_DataAvailable(std::vector<float> data) {

	if(this->is_lowpass_enabled_ == true) {
		this->filter_lp_.apply(data);
	}
	
	if(this->is_highpass_enabled_ == true) {
		this->filter_hp_.apply(data);
	}



	switch(this->reference_) {
		case References::AVERAGE:
			FilterCar::apply(data, this->buffer_.channels());
			break;
		case References::ELECTRODE:
			FilterReference::apply(data, this->buffer_.channels(), this->ref_electrode_);
			break;
		default:
			break;
	}
	
	this->buffer_.add(data);	

	this->scope_->draw(this->buffer_, this->channel_index_selected_);
}




