#ifndef ROSNEURO_VISUALIZER_TEMPORALPLOT_HPP
#define ROSNEURO_VISUALIZER_TEMPORALPLOT_HPP

#include <cmath>
#include <qcustomplot.h>
#include <QElapsedTimer>
#include "rosneuro_visualizer/EigenBuffer.hpp"
#include "rosneuro_visualizer/Palette.hpp"

class TemporalPlot : public QCustomPlot {

	Q_OBJECT

	public:
		TemporalPlot(QWidget* parent = nullptr);
		virtual ~TemporalPlot(void);
	
		void setup(unsigned int nsamples, const std::vector<int>& channel_selected);
		void set_time_window(float window);
		void set_channel_labels(const QList<QString>& chlabels);
		void set_scale(double scale);
		void set_axis_x(unsigned int nsamples);
		void set_axis_y(unsigned int nchannels);
		double rescale(double value, double scale);

		void plot(const EigenBuffer& buffer);

	protected:
		QVector<double>	x_;
		QVector<double> y_;

		QPen 	penclear_;
		QPen	pengrid_;
		QPen	pengraph_;
		QFont 	xfont_;
		QFont	yfont_;
		static constexpr int xfontsize_ = 10;
		static constexpr int yfontsize_ = 10;
		double	scale_ = 100.0f;

		QSharedPointer<QCPAxisTickerText> xticker_;
		QSharedPointer<QCPAxisTickerText> yticker_;

		QList<QString> 		channel_labels_;
		std::vector<int> 	channel_selected_index_;
		float 				time_window_;
 		
		Palette	palette_;

		const int decimation_time_ = 20; // milliseconds
		int decimation_;
		QElapsedTimer timer;
};


#endif
