#include "rosneuro_visualizer/MainWindow.hpp"


MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), 
										   ui_(new Ui::NeuroVizPanel) {

	this->ui_->setupUi(this);

	this->addPanel(new EEGPanel("EEG", parent));
	this->addPanel(new EXGPanel("EXG", parent));

	this->set_current_panel();


	// UI callbacks
	QObject::connect(this->ui_->NeuroTab, SIGNAL(currentChanged(int)),this, SLOT(on_TabChanged(int)));
	QObject::connect(this->ui_->InfoButton, SIGNAL(clicked()), SLOT(on_InfoEvent()));
	QObject::connect(this->ui_->TopicValue, SIGNAL(returnPressed()), SLOT(on_StartEvent()));
	QObject::connect(this->ui_->StopButton, SIGNAL(clicked()), SLOT(on_StopEvent()));

	// DataThread callbacks
	QObject::connect(&(this->thread_data_),&DataThread::sig_first_message, this, &MainWindow::on_FirstMessage);
	QObject::connect(&(this->thread_data_),&DataThread::sig_message_info, this, &MainWindow::on_MessageInfo);
	QObject::connect(&(this->thread_data_),&DataThread::sig_data_available, this, &MainWindow::on_DataAvailable);


	
}

MainWindow::~MainWindow(void) {
	this->destroy_panel_widgets();
	delete this->ui_;
}

void MainWindow::addPanel(NeuroPanel* panel) {
	this->ui_->NeuroTab->addTab(panel, panel->name());
}

void MainWindow::set_current_panel(void) {
	
	int panelIdx = this->ui_->NeuroTab->currentIndex();	
	int ntabs = this->ui_->NeuroTab->count();
	
	for(auto i=0; i<ntabs; ++i) {
		dynamic_cast<NeuroPanel*>(this->ui_->NeuroTab->widget(i))->reset();
	}

	this->current_panel_ = dynamic_cast<NeuroPanel*>(this->ui_->NeuroTab->widget(panelIdx));
}

void MainWindow::destroy_panel_widgets(void) {
	int ntabs = this->ui_->NeuroTab->count();

	for(auto i=0; i<ntabs; ++i) {
		QWidget* w = this->ui_->NeuroTab->widget(i);
		delete w;
	}
}

void MainWindow::on_StartEvent(void) {

	// If the topic is empty, then return
	if(this->ui_->TopicValue->text().isEmpty() == true)
		return;

	// Setup the GUI (StopButton enabled, Status Running, InfoButton disabled)
	this->ui_->StopButton->setEnabled(true);
	this->ui_->AcquisitionStatus->setText("Running");
	this->ui_->InfoButton->setDisabled(true);

	// Reset data information (sampling rate, message rate and sequence number)
	this->set_samplerate(0);
	this->set_messagerate(0);
	this->set_messagesequence(0);

	// Reset channel labels (EEG, EMG, TRI)
	this->reset_channel_labels();

	// Restart acquisition thread
	this->thread_data_.stop_thread();
	this->thread_data_.set_topic(this->ui_->TopicValue->text().toStdString());
	this->thread_data_.start_thread();            
}

void MainWindow::on_StopEvent(void) {
	
	// Setup the GUI (StopButton disabled, Status Idle)
	this->ui_->StopButton->setDisabled(true);
	this->ui_->AcquisitionStatus->setText("Idle");

	// Stop acquisition thread
	this->thread_data_.stop_thread();
}

void MainWindow::on_FirstMessage(rosneuro_msgs::NeuroFrame frame) {
	
	// Setup data information (sampling rate, data info)
	this->set_samplerate(frame.sr);
	this->set_info(frame);

	// Store channel labels (EEM, EMG, TRI)
	this->store_channel_labels(frame);

	// Setup the GUI (info button enabled)
	this->ui_->InfoButton->setEnabled(true);

	this->current_panel_->setup(frame);

}

void MainWindow::on_MessageInfo(unsigned int sequence, float rate) {

	// Setup message informatio (message rate and sequence)
	this->set_messagerate(rate);
	this->set_messagesequence(sequence);
}

void MainWindow::on_InfoEvent(void) {

	QMessageBox msgBox(this);
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setWindowTitle("neuroviz | data information");
	msgBox.setText(this->info_);
	msgBox.exec();
}

void MainWindow::set_samplerate(float rate) {
	this->samplerate_ = rate;
	
	QString qsamplerate = "~";
	if (rate != 0)
		qsamplerate = QString::number(rate);

	this->ui_->NativeRateLabel->setText(qsamplerate + " Hz");
}

void MainWindow::set_messagerate(float rate) {
	this->messagerate_ = rate;

	QString qrate = "~";
	if (rate != 0)
		qrate = QString::number(rate, 'G', 3);
                                
	this->ui_->MessageRateLabel->setText(qrate + " Hz");
}

void MainWindow::set_messagesequence(unsigned int sequence) {
	this->sequence_ = sequence;
	this->ui_->MessageSeqLabel->setText(QString::number(sequence));
}

void MainWindow::store_channel_labels(const rosneuro_msgs::NeuroFrame& frame) {

	for(auto it = frame.eeg.info.labels.begin(); it != frame.eeg.info.labels.end(); ++it)
		this->eeg_labels_.push_back(QString::fromStdString(*it));
	
	for(auto it = frame.exg.info.labels.begin(); it != frame.exg.info.labels.end(); ++it)
		this->exg_labels_.push_back(QString::fromStdString(*it));
	
	for(auto it = frame.tri.info.labels.begin(); it != frame.tri.info.labels.end(); ++it)
		this->tri_labels_.push_back(QString::fromStdString(*it));
}

void MainWindow::reset_channel_labels(void) {
	this->eeg_labels_.clear();
	this->exg_labels_.clear();
	this->tri_labels_.clear();
}

void MainWindow::set_info(const rosneuro_msgs::NeuroFrame& frame) {

	this->info_ = "EEG info:\n" + 
				  QString::fromStdString(this->to_string(frame.eeg.info)) +
				  "\nEXG info:\n" +
				  QString::fromStdString(this->to_string(frame.exg.info)) +
				  "\nTRI info:\n" +
				  QString::fromStdString(this->to_string(frame.tri.info));
}

std::string MainWindow::to_string(const rosneuro_msgs::NeuroDataInfo& info) {
	std::string str_info =	"Number of channels: " + std::to_string(info.nchannels) + "\n" + 
							"Unit: " + info.unit + "\n" +
							"Transducter: " + info.transducter + "\n" +
							"Prefiltering: " + info.prefiltering + "\n";

	str_info += "Min/max values: [ ";
	for (auto it = info.minmax.begin(); it != info.minmax.end(); ++it)
		str_info += std::to_string(*it) + " ";
	str_info += "]\n";

	return str_info;
}


/******************************************************************************/
// UI Callbacks
/******************************************************************************/

void MainWindow::on_TabChanged(int index) {
	this->set_current_panel();
}

/******************************************************************************/
// DataThread Callbacks
/******************************************************************************/



void MainWindow::on_DataAvailable(rosneuro_msgs::NeuroFrame frame) {


	// Setup the current widget
	if(this->current_panel_->isset() == false) {
		this->current_panel_->setup(frame);
	}


	if(this->current_panel_->isset() == true) {
		this->current_panel_->draw();
	}
}





