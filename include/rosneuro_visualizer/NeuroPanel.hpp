#ifndef NEUROPANEL_HPP
#define NEUROPANEL_HPP

#include <qcustomplot.h>
#include "rosneuro_visualizer/Palette.hpp"
#include "rosneuro_visualizer/Buffer.hpp"

class Palette;

class NeuroPanel : public QCustomPlot {
	
	public:
		NeuroPanel(QWidget* parent = nullptr);
		virtual ~NeuroPanel(void);

		virtual void set_channel_labels(const QList<QString>& chlabel);
		virtual void set_scale(double scale);
		virtual void setup(unsigned int nsamples, unsigned int nchannels) = 0;
		virtual void draw(const Buffer& buffer, const QVector<int>& chindex) = 0; 


	protected:
		QPen 	penclear_;
		QPen	pengrid_;
		QPen	pengraph_;
		QFont 	xfont_;
		QFont	yfont_;
		static constexpr int xfontsize_ = 10;
		static constexpr int yfontsize_ = 10;
		double	scale_;

		QSharedPointer<QCPAxisTickerText> xticker_;
		QSharedPointer<QCPAxisTickerText> yticker_;

		QList<QString> 	channel_label_;
 		Palette	palette_;
};


#endif
