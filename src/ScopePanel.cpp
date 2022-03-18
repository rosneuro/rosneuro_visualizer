#include "rosneuro_visualizer/ScopePanel.hpp"


ScopePanel::ScopePanel(QWidget* parent) : NeuroPanel(parent) {
	this->set_scale(50.0f);
	this->setup(0, 0);
}

ScopePanel::~ScopePanel(void) {}

void ScopePanel::setup(unsigned int nsamples, unsigned int nchannels) {

	// Setting un y-ticker (channels)
	this->set_axis_y(nchannels);
	
	// Setting un x-ticker (samples)
	this->set_axis_x(nsamples);

	// Adding graph for each channel
	this->clearGraphs();
	for(auto i=0; i<nchannels; i++)
		this->addGraph();

}

void ScopePanel::draw(const EigenBuffer& buffer, const QVector<int>& chindex) {

	unsigned int nchannels = chindex.size();
	unsigned int nsamples  = buffer.samples();
	QVector<double> xvalues(nsamples), yvalues(nsamples);

	if(chindex != this->channel_index_) {
		
		// Adding graph for the provided channels
		this->clearGraphs();
		for(auto i=0; i<chindex.size(); i++)
			this->addGraph();

		// Adding y-tick considering the provided channels
		unsigned int chId = 1;
		for(auto i=0; i<chindex.size(); i++) {
			this->yticker_->addTick(chId, this->channel_label_.at(chindex.at(nchannels - i - 1)));
			chId++;
		}
		this->set_axis_y(nchannels);

		this->channel_index_ = chindex;
	}
	
	this->set_axis_x(buffer.samples());

	// Create x-values vector
	for(auto i=0; i<nsamples; i++)
		xvalues[i] = i;
	
	
	// Create y-values vector
	unsigned int pIdx = 0;
	this->palette_.reset();
	for(auto ch = 0; ch<nchannels; ch++) {
		unsigned int chInd = chindex.at(ch);
		for(auto sp = 0; sp<nsamples; sp++) {
			//yvalues[sp] = this->remap(const_cast<EigenBuffer&>(buffer).at(sp, chInd), this->scale_) + nchannels - ch;
			yvalues[sp] = this->remap(buffer.at(sp, chInd), this->scale_) + nchannels - ch;
		}

		this->graph(ch)->setData(xvalues, yvalues);

		QColor color = this->palette_.get();
		this->pengraph_.setColor(color);
		this->graph(ch)->setPen(this->pengraph_);
		this->palette_.next();
	}

	// Plotting the data
	this->replot();
}

/*
void ScopePanel::draw(const Buffer& buffer, const QVector<int>& chindex) {

	unsigned int nchannels = chindex.size();
	unsigned int nsamples  = buffer.samples();
	QVector<double> xvalues(nsamples), yvalues(nsamples);

	if(chindex != this->channel_index_) {
		
		// Adding graph for the provided channels
		this->clearGraphs();
		for(auto i=0; i<chindex.size(); i++)
			this->addGraph();

		// Adding y-tick considering the provided channels
		unsigned int chId = 1;
		for(auto i=0; i<chindex.size(); i++) {
			this->yticker_->addTick(chId, this->channel_label_.at(chindex.at(nchannels - i - 1)));
			chId++;
		}
		this->set_axis_y(nchannels);

		this->channel_index_ = chindex;
	}
	
	this->set_axis_x(buffer.samples());

	// Create x-values vector
	for(auto i=0; i<nsamples; i++)
		xvalues[i] = i;
	
	
	// Create y-values vector
	unsigned int pIdx = 0;
	this->palette_.reset();
	for(auto ch = 0; ch<nchannels; ch++) {
		unsigned int chInd = chindex.at(ch);
		for(auto sp = 0; sp<nsamples; sp++) {
			yvalues[sp] = this->remap(buffer.get().at(chInd).at(sp), this->scale_) + nchannels - ch;
		}

		this->graph(ch)->setData(xvalues, yvalues);

		QColor color = this->palette_.get();
		this->pengraph_.setColor(color);
		this->graph(ch)->setPen(this->pengraph_);
		this->palette_.next();
	}

	// Plotting the data
	this->replot();
}*/

void ScopePanel::set_axis_y(unsigned int nchannels) {
	this->yAxis->setTicker(this->yticker_);
	this->yAxis->setRange(0.5, nchannels + 0.5);
}

void ScopePanel::set_axis_x(unsigned int nsamples) {
	this->xAxis->setTicker(this->xticker_);
	this->xAxis->setRange(0, nsamples);
}

double ScopePanel::remap(double value, double scale) {

	double low1, high1, low2, high2, rvalue;

	low1 = -scale;
	high1 = scale;

	low2 = -1.0;
	high2 = 1.0;
	
	rvalue = low2 + (value - low1) * (high2 - low2) / (high1 - low1);

	return rvalue;

}
