#include "rosneuro_visualizer/NeuroPanel.hpp"

NeuroPanel::NeuroPanel(QWidget* parent) : QCustomPlot(parent) {

	// Setting up grid pen
	this->pengrid_.setStyle(Qt::SolidLine);
	this->pengrid_.setWidth(1);
	this->pengrid_.setColor(QColor(1,1,1,32));
	
	// Setting up empty pen
	this->penclear_.setStyle(Qt::SolidLine);
	this->penclear_.setWidth(0);
	this->penclear_.setColor(QColor(1, 1, 1, 0));
	
	// Setting up graph pen (color will change)
	this->pengraph_.setStyle(Qt::SolidLine);
	this->pengraph_.setWidth(1);

	// Setting up label font size
	this->xfont_.setPointSize(this->xfontsize_);
	this->yfont_.setPointSize(this->yfontsize_);

	// Instanciate x-y tickers
	this->xticker_ = QSharedPointer<QCPAxisTickerText>(new QCPAxisTickerText);
	this->yticker_ = QSharedPointer<QCPAxisTickerText>(new QCPAxisTickerText);

	// Setting up x-y axis
	this->xAxis->setTickLabels(false);
	this->xAxis->setVisible(false);
	this->xAxis->setTickLabelFont(this->xfont_);

	this->yAxis->setTickLabels(true);
	this->yAxis->setSubTicks(false);
	this->yAxis->setBasePen(this->penclear_);
	this->yAxis->setTickPen(this->penclear_);
	this->yAxis->grid()->setPen(this->pengrid_);
	this->yAxis->setTickLabelFont(this->yfont_);

	// Setting color palette

	this->palette_.add(QColor(  0,   0, 255)); // blue
	this->palette_.add(QColor(  0,   0,   0)); // black
	this->palette_.add(QColor(255,   0,   0)); // red
	this->palette_.add(QColor(  0, 102,   0)); // dark green
	this->palette_.add(QColor(255, 128,   0)); // orange
	this->palette_.add(QColor(153,  76,   0)); // brown
	this->palette_.add(QColor(255,   0, 255)); // pink
	this->palette_.add(QColor(  0, 255, 255)); // cyan

}

NeuroPanel::~NeuroPanel(void) {}

void NeuroPanel::set_scale(double scale) {
	this->scale_ = scale;
}

void NeuroPanel::set_channel_labels(const QList<QString>& chlabel) {
	this->channel_label_ = chlabel;
}

