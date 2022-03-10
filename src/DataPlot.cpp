#include "rosneuro_visualizer/DataPlot.hpp"

DataPlot::DataPlot(void) : yticker_(new QCPAxisTickerText), xticker_(new QCPAxisTickerText) {}

DataPlot::~DataPlot(void) {}


void DataPlot::setup(QCustomPlot* plot) {

	this->qplot_ = plot;
	
	this->pengrid_.setStyle(Qt::SolidLine);
	this->pengrid_.setWidth(1);
	this->pengrid_.setColor(QColor(1,1,1,32));
	
	this->penclear_.setStyle(Qt::SolidLine);
	this->penclear_.setWidth(0);
	this->penclear_.setColor(QColor(1, 1, 1, 0));

	this->yfont_.setPointSize(10);

	this->qplot_->addGraph();
	this->qplot_->xAxis->setTickLabels(false);
	this->qplot_->xAxis->setVisible(false);
	this->qplot_->yAxis->setTickLabels(true);
	this->qplot_->yAxis->setBasePen(this->penclear_);
	this->qplot_->yAxis->setTickPen(this->penclear_);
	this->qplot_->yAxis->grid()->setPen(this->pengrid_);
	this->qplot_->yAxis->setSubTicks(false);
	this->qplot_->yAxis->setTickLabelFont(this->yfont_);
	
	
}

void DataPlot::draw(unsigned int nchannels, const QList<QString>& labels) {
	
	this->qplot_->yAxis->setTicker(this->yticker_);
	unsigned int chId = 1;	
	for(auto it=labels.begin(); it!=labels.end(); ++it) {
		this->yticker_->addTick(chId, (*it));
		chId++;
	}

	this->qplot_->yAxis->setRange(0.5, nchannels + 0.5);
	this->qplot_->replot();

}
