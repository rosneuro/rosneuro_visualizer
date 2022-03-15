#include "rosneuro_visualizer/DataPanel.hpp"

DataPanel::DataPanel(void) : yticker_(new QCPAxisTickerText), xticker_(new QCPAxisTickerText) {}

DataPanel::~DataPanel(void) {}


void DataPanel::setup(QCustomPlot* plot) {

	this->qplot_ = plot;
	
	this->pengrid_.setStyle(Qt::SolidLine);
	this->pengrid_.setWidth(1);
	this->pengrid_.setColor(QColor(1,1,1,32));
	
	this->penclear_.setStyle(Qt::SolidLine);
	this->penclear_.setWidth(0);
	this->penclear_.setColor(QColor(1, 1, 1, 0));

	this->yfont_.setPointSize(10);

	for (auto chId = 0; chId < 16; chId++) {
		this->qplot_->addGraph();
	}

	this->qplot_->xAxis->setTickLabels(false);
	this->qplot_->xAxis->setVisible(false);
	this->qplot_->yAxis->setTickLabels(true);
	this->qplot_->yAxis->setBasePen(this->penclear_);
	this->qplot_->yAxis->setTickPen(this->penclear_);
	this->qplot_->yAxis->grid()->setPen(this->pengrid_);
	this->qplot_->yAxis->setSubTicks(false);
	this->qplot_->yAxis->setTickLabelFont(this->yfont_);
	
	
}

void DataPanel::draw(unsigned int nchannels, const QList<QString>& labels) {
	
	this->qplot_->yAxis->setTicker(this->yticker_);
	unsigned int chId = 1;	
	for(auto it=labels.begin(); it!=labels.end(); ++it) {
		this->yticker_->addTick(chId, (*it));
		chId++;
	}

	this->qplot_->yAxis->setRange(0.5, nchannels + 0.5);
	this->qplot_->replot();

}

void DataPanel::draw2(const Buffer& buffer, unsigned int nchannels, const QList<QString>& labels) {
	
	this->qplot_->yAxis->setTicker(this->yticker_);
	unsigned int chId = 1;	
	for(auto it=labels.begin(); it!=labels.end(); ++it) {
		this->yticker_->addTick(chId, (*it));
		chId++;
	}

	this->qplot_->yAxis->setRange(0.5, nchannels + 0.5);
	this->qplot_->xAxis->setRange(0, 10240);

	std::vector<std::vector<float>> data = buffer.buffer_;
	unsigned int buff_nsamples  = buffer.samples();
	unsigned int buff_nchannels = buffer.channels();
	
	QVector<double> x(buff_nsamples), y(buff_nsamples);

	for (auto i = 0; i < buff_nsamples; i++) {
		x[i] = i;
	}

	double scale = 50;
	for (auto c = 0; c < buff_nchannels; c++) {
		for (auto i = 0; i < buff_nsamples; i++) {
			y[i] = this->remap(data.at(c).at(i), scale) + c + 1;
		}
	
		this->qplot_->graph(c)->setData(x, y);

	}



	this->qplot_->replot();

}


double DataPanel::remap(double value, double scale) {

	double low1, high1, low2, high2, rvalue;

	low1 = -scale;
	high1 = scale;

	low2 = -0.5;
	high2 = 0.5;
	
	rvalue = low2 + (value - low1) * (high2 - low2) / (high1 - low1);

	return rvalue;

}
