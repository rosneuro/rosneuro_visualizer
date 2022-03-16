#ifndef SCOPEPANEL_HPP
#define SCOPEPANEL_HPP

#include "rosneuro_visualizer/NeuroPanel.hpp"

class ScopePanel : public NeuroPanel {

	public:
		ScopePanel(QWidget* parent = nullptr);
		virtual ~ScopePanel(void);

		void setup(unsigned int nsamples, unsigned int nchannels);
		//void draw(const Buffer& buffer, const QVector<int>& chindex);
		void draw(const EigenBuffer& buffer, const QVector<int>& chindex);

		void set_axis_y(unsigned int nchannels);
		void set_axis_x(unsigned int nsamples);


		double remap(double value, double scale);
	private:
		QVector<int> channel_index_;
};

#endif
