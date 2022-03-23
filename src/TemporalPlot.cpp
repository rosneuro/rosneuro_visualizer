#include "rosneuro_visualizer/TemporalPlot.hpp"


TemporalPlot::TemporalPlot(QWidget* parent) : QCustomPlot(parent)  {

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

	this->yAxis->setVisible(false);
	this->yAxis->setTickLabels(false);
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

TemporalPlot::~TemporalPlot(void) {}

void TemporalPlot::setup(unsigned int nsamples, const std::vector<int>& channel_selected) {

	unsigned int nchannels = channel_selected.size();
	this->channel_selected_index_ = channel_selected;

	// Setting un y-ticker (channels)
	this->set_axis_y(nchannels);
	
	// Setting un x-ticker (samples)
	this->set_axis_x(nsamples);

	// Adding graph for each channel
	this->clearGraphs();
	for(auto i=0; i<nchannels; i++)
		this->addGraph();

	// Create x-values vector
	this->x_.clear();
	for(auto i=0; i<nsamples; i++)
		this->x_.push_back(i);	
	
	// Create TMP y-values vector
	this->y_.clear();
	for(auto i=0; i<nsamples; i++)
		this->y_.push_back(1);	

}

void TemporalPlot::set_scale(double scale) {
	this->scale_ = scale;
}

void TemporalPlot::set_time_window(float window) {
	this->time_window_ = window;
}

void TemporalPlot::set_channel_labels(const QList<QString>& chlabels) {
	this->channel_labels_ = chlabels;
}

void TemporalPlot::set_axis_y(unsigned int nchannels) {

	this->yticker_->clear();
	for(auto i = 0; i<nchannels; ++i) {
		int chanIndex = this->channel_selected_index_.at(i);
		this->yticker_->addTick(nchannels-i, this->channel_labels_.at(chanIndex));
	}
	
	this->yAxis->setTicker(this->yticker_);
	this->yAxis->setRange(0.5, nchannels + 0.5);
	this->yAxis->setTickLabels(true);
	this->yAxis->setVisible(true);
}

void TemporalPlot::set_axis_x(unsigned int nsamples) {

	this->xticker_->clear();
	float step = std::ceil(this->time_window_/6.0f);

	if(this->time_window_ == 20.0f)
		step = 5.0f;

	unsigned int ustep = static_cast<unsigned int>(step);
	unsigned int uwin  = static_cast<unsigned int>(this->time_window_);
	float samplerate = nsamples/this->time_window_;
	
	for(auto i=0; i<uwin; i+=ustep) {
		this->xticker_->addTick(i*samplerate, QString::number(i) + " s");
	}
	this->xticker_->addTick(uwin*samplerate, QString::number(uwin) + " s");

	this->xAxis->setTicker(this->xticker_);
	this->xAxis->setRange(0, nsamples);
	this->xAxis->setTickLabels(true);
	this->xAxis->setVisible(true);
}

void TemporalPlot::plot(void) {

	//printf("plot\n");
	//this->graph(0)->setData(this->x_, this->y_);

	this->replot();


	//QVector<double> x(101), y(101); // initialize with entries 0..100
	//for (int i=0; i<101; ++i)
	//{
	//  x[i] = i/50.0 - 1; // x goes from -1 to 1
	//  y[i] = x[i]*x[i]; // let's plot a quadratic function
	//}
	//// create graph and assign data to it:
	//this->graph(0)->setData(x, y);
	//// give the axes some labels:
	//this->xAxis->setLabel("x");
	//this->yAxis->setLabel("y");
	//// set axes ranges, so we see all data:
	//this->xAxis->setRange(-1, 1);
	//this->yAxis->setRange(0, 1);
	//this->replot();
}