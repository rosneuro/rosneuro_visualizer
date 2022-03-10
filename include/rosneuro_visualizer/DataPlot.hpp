#ifndef DATA_PLOT_HPP
#define DATA_PLOT_HPP

#include <qcustomplot.h>


class DataPlot {

	public:
		DataPlot(void);
		virtual ~DataPlot(void);

		void setup(QCustomPlot* plot);
		void draw(unsigned int nchannels, const QList<QString>& labels);


	private:
		QCustomPlot* qplot_;
		QPen 		 penclear_;
		QPen 		 pengrid_;
		QFont 		 yfont_;
		QSharedPointer<QCPAxisTickerText> yticker_;
		QSharedPointer<QCPAxisTickerText> xticker_;



};


#endif
