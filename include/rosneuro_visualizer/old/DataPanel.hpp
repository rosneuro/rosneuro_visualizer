#ifndef DATA_PANEL_HPP
#define DATA_PANEL_HPP

#include <qcustomplot.h>
#include "rosneuro_visualizer/Buffer.hpp"


class DataPanel {

	public:
		DataPanel(void);
		virtual ~DataPanel(void);

		void setup(QCustomPlot* plot);
		void draw(unsigned int nchannels, const QList<QString>& labels);
		void draw2(const Buffer& buffer, unsigned int nchannels, const QList<QString>& labels);

		double remap(double value, double scale);

	private:
		QCustomPlot* qplot_;
		QPen 		 penclear_;
		QPen 		 pengrid_;
		QFont 		 yfont_;
		QSharedPointer<QCPAxisTickerText> yticker_;
		QSharedPointer<QCPAxisTickerText> xticker_;



};


#endif
