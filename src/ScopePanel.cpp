#include "rosneuro_visualizer/ScopePanel.hpp"

ScopePanel::ScopePanel(QString name, QWidget* parent) : NeuroPanel(name, parent),
										  				ui_(new Ui::TimeScope) {

	this->ui_->setupUi(this);
	this->scope_ = this->ui_->eegScope;

	this->buffer_ 			= nullptr;
	this->FilterOrder_  	= 2;
	this->LowPassCutoff_  	= 100.0f;
	this->HighPassCutoff_ 	= 1.0f;
	this->window_length_  	= 10.0f;
	this->filter_lp_.set_type(FilterType::LOWPASS);
	this->filter_hp_.set_type(FilterType::HIGHPASS);

	this->ui_->ScaleValue->setEnabled(false);
	this->ui_->HighPassCheck->setEnabled(false);
	this->ui_->HighPassValue->setEnabled(false);
	this->ui_->LowPassCheck->setEnabled(false);
	this->ui_->LowPassValue->setEnabled(false);
	this->ui_->ReferenceValue->setEnabled(false);
	this->ui_->ReferenceOpt->setEnabled(false);
	this->ui_->ChannelsList->setEnabled(false);
	this->ui_->TimeWindowValue->setEnabled(false);
	
	QObject::connect(this->ui_->ChannelsList, SIGNAL(itemSelectionChanged()), SLOT(on_ChannelSelection()));
	QObject::connect(this->ui_->ScaleValue, SIGNAL(currentIndexChanged(int)), SLOT(on_ScaleChanged(int)));
	QObject::connect(this->ui_->TimeWindowValue, SIGNAL(currentIndexChanged(int)), SLOT(on_TimeWindowChanged(int)));
	QObject::connect(this->ui_->ReferenceValue, SIGNAL(currentIndexChanged(int)), SLOT(on_SpatialFilterChanged(int)));
	QObject::connect(this->ui_->ReferenceOpt, SIGNAL(currentIndexChanged(int)), SLOT(on_RefElectrodeChanged(int)));
	QObject::connect(this->ui_->LowPassCheck, SIGNAL(stateChanged(int)), SLOT(on_LowPassCheckChanged(int)));
	QObject::connect(this->ui_->LowPassValue, SIGNAL(valueChanged(double)), SLOT(on_LowPassValueChanged(double)));
	QObject::connect(this->ui_->HighPassCheck, SIGNAL(stateChanged(int)), SLOT(on_HighPassCheckChanged(int)));
	QObject::connect(this->ui_->HighPassValue, SIGNAL(valueChanged(double)), SLOT(on_HighPassValueChanged(double)));

	QObject::connect(&(this->plotter_), SIGNAL(timeout()), this, SLOT(draw()));
	this->plotter_.start(80);

}

ScopePanel::~ScopePanel(void) {

	if(this->scope_ != nullptr)
		delete this->scope_;

	if(this->buffer_ != nullptr)
		delete this->buffer_;
}

bool ScopePanel::setup(const rosneuro_msgs::NeuroFrame& frame) {

	bool retcode = true;

	this->samplerate_ = frame.sr;
	rosneuro_msgs::NeuroDataInfo datainfo;

	switch(this->getDataType()) {
		case DataType::EEG:
			datainfo = frame.eeg.info;
			break;
		case DataType::EXG:
			datainfo = frame.exg.info;
			break;
		case DataType::TRI:
			datainfo = frame.tri.info;
			break;
		default:
			retcode = false;
			break;
	}

	if(retcode == false)
		return retcode;

	// Setup samples
	this->nsamples_ = (unsigned int)(this->samplerate_ * this->window_length_); 

	// Setup channels (and channel labels)
	this->reset_channels();
	

	this->nchannels_ = datainfo.nchannels;
	for(auto it=datainfo.labels.begin(); it!=datainfo.labels.end(); ++it) {
		this->channel_labels_.push_back(QString::fromStdString((*it)));
	}

	for(auto it = this->channel_labels_.begin(); it != this->channel_labels_.end(); ++it) {
		this->ui_->ChannelsList->addItem((*it));
		this->ui_->ReferenceOpt->addItem(*it);
	}

	std::iota(this->channel_selected_index_.begin(), this->channel_selected_index_.end(), 0);

	// Setup buffer
	if(this->buffer_ != nullptr)
		delete this->buffer_;
	this->buffer_ = new EigenBuffer(this->nsamples_, this->nchannels_);


	// Enable GUI buttons
	this->ui_->ScaleValue->setEnabled(true);
	this->ui_->HighPassCheck->setEnabled(true);
	this->ui_->HighPassValue->setEnabled(true);
	this->ui_->LowPassCheck->setEnabled(true);
	this->ui_->LowPassValue->setEnabled(true);
	this->ui_->ReferenceValue->setEnabled(true);
	this->ui_->ChannelsList->setEnabled(true);
	this->ui_->TimeWindowValue->setEnabled(true);
	
	// Setup temporal scope
	this->scope_->set_time_window(this->window_length_);
	this->scope_->set_channel_labels(this->channel_labels_);
	this->scope_->setup(this->nsamples_, this->channel_selected_index_);

	this->isset_ = true;

	// Select all channels
	this->ui_->ChannelsList->selectAll();

	return retcode;
}

void ScopePanel::reset(void) {
	this->samplerate_ = 0;
	this->nsamples_ = 0;
	this->reset_channels();

	if(this->buffer_ != nullptr) 
		this->buffer_->reset(this->nsamples_, this->nchannels_);

	this->isset_ = false;
}

void ScopePanel::update(const rosneuro_msgs::NeuroFrame& frame) {

	std::vector<float>* data;

	switch(this->getDataType()) {
		case DataType::EEG:
			data = const_cast<std::vector<float>*>(&frame.eeg.data);
			break;
		case DataType::EXG:
			data = const_cast<std::vector<float>*>(&frame.exg.data);
			break;
		default:
			break;
	}

	if(data->size() == 0)
		return;

	if(this->IsLowPassActive_ == true)
		this->filter_lp_.apply((*data));
	
	if(this->IsHighPassActive_ == true)
		this->filter_hp_.apply((*data));

	switch(this->SpatialFilterIndex_) {
		case SpatialFilter::AVERAGE:
			FilterCar::apply((*data), this->buffer_->channels());
			break;
		case SpatialFilter::ELECTRODE:
			FilterReference::apply((*data), this->buffer_->channels(), this->RefElectrodeIndex_);
			break;
		default:
			break;
	}


	this->buffer_->add(*data);
}

void ScopePanel::draw(void) {

	if(this->isset() == true) {	
		this->scope_->plot((*this->buffer_));
	}
}

void ScopePanel::reset_channels(void) {
	this->nchannels_ = 0;
	this->channel_labels_.clear();
	this->ui_->ChannelsList->clear();	
	this->ui_->ReferenceOpt->clear();	
	this->channel_selected_index_.clear();
}

void ScopePanel::on_ChannelSelection(void) {

	if(this->isset() == false)
		return;

	this->channel_selected_index_.clear();

	for(QListWidgetItem *item: this->ui_->ChannelsList->selectedItems()){
    	this->channel_selected_index_.push_back(this->ui_->ChannelsList->row(item));
	}

	// Update temporal scope
	this->scope_->set_channel_labels(this->channel_labels_);
	this->scope_->setup(this->nsamples_, this->channel_selected_index_);
}

void ScopePanel::on_ScaleChanged(int index) {
	this->ScaleValue_ = this->scales_.at(index);;
	this->scope_->set_scale(this->ScaleValue_);
}

void ScopePanel::on_TimeWindowChanged(int index) {
	this->window_length_ = this->windows_.at(index);

	this->nsamples_ = (unsigned int)(this->samplerate_ * this->window_length_);
	this->buffer_->reset(this->nsamples_, this->nchannels_);
	
	// Update temporal scope
	this->scope_->set_time_window(this->window_length_);
	this->scope_->setup(this->nsamples_, this->channel_selected_index_);
}

void ScopePanel::on_SpatialFilterChanged(int index) {

	this->SpatialFilterIndex_ = this->ui_->ReferenceValue->currentIndex();
	if(this->SpatialFilterIndex_ == SpatialFilter::ELECTRODE) {
		this->ui_->ReferenceOpt->setEnabled(true);
	} else {
		this->ui_->ReferenceOpt->setDisabled(true);
	}
	
}

void ScopePanel::on_RefElectrodeChanged(int index) {
	this->RefElectrodeIndex_ = this->ui_->ReferenceOpt->currentIndex();
}

void ScopePanel::on_LowPassCheckChanged(int index) {
	this->IsLowPassActive_ = this->ui_->LowPassCheck->isChecked();

	if (this->IsLowPassActive_ == true) {
		this->LowPassCutoff_ = this->ui_->LowPassValue->value();
		this->filter_lp_.setup(this->FilterOrder_, this->samplerate_, this->LowPassCutoff_, this->nchannels_);
	}
}

void ScopePanel::on_LowPassValueChanged(double value) {
	if (this->IsLowPassActive_ == true) {
		this->LowPassCutoff_ = value;
		this->filter_lp_.setup(this->FilterOrder_, this->samplerate_, this->LowPassCutoff_, this->nchannels_);
	}
}

void ScopePanel::on_HighPassCheckChanged(int index) {
	this->IsHighPassActive_ = this->ui_->HighPassCheck->isChecked();

	if (this->IsHighPassActive_ == true) {
		this->HighPassCutoff_ = this->ui_->HighPassValue->value();
		this->filter_hp_.setup(this->FilterOrder_, this->samplerate_, this->HighPassCutoff_, this->nchannels_);
	}
}

void ScopePanel::on_HighPassValueChanged(double value) {
	if (this->IsHighPassActive_ == true) {
		this->HighPassCutoff_ = value;
		this->filter_hp_.setup(this->FilterOrder_, this->samplerate_, this->HighPassCutoff_, this->nchannels_);
	}
}
