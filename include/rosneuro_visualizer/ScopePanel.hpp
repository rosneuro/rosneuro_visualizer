#ifndef ROSNEURO_VISUALIZER_SCOPEPANEL_HPP
#define ROSNEURO_VISUALIZER_SCOPEPANEL_HPP

#include <numeric>
#include <QTimer>
#include "src/ui_neuroviz_timescope.h"
#include "rosneuro_visualizer/NeuroPanel.hpp"
#include "rosneuro_visualizer/TemporalPlot.hpp"
#include "rosneuro_visualizer/EigenBuffer.hpp"
#include "rosneuro_visualizer/FilterCar.hpp"
#include "rosneuro_visualizer/FilterReference.hpp"
#include "rosneuro_visualizer/FilterButterworth.hpp"


class ScopePanel : public NeuroPanel {
	
	Q_OBJECT
	
	public:
		ScopePanel(QString name, QWidget* parent = nullptr);
		virtual ~ScopePanel(void);
		
		virtual bool setup(const rosneuro_msgs::NeuroFrame& frame);
		virtual void reset(void);
		virtual void update(const rosneuro_msgs::NeuroFrame& frame);


	public slots:
	    void draw(void);
		void on_ChannelSelection(void);
		void on_ScaleChanged(int index);
		void on_TimeWindowChanged(int index);
		void on_SpatialFilterChanged(int index);
		void on_RefElectrodeChanged(int index);
		void on_LowPassCheckChanged(int index);
		void on_LowPassValueChanged(double value);
		void on_HighPassCheckChanged(int index);
		void on_HighPassValueChanged(double value);

	protected:
		void reset_channels(void);

	public:
		enum SpatialFilter {NOREFERENCE, AVERAGE, ELECTRODE, BIPOLAR};
		
	private:
		Ui::TimeScope* 		ui_;
		TemporalPlot* 		scope_;
	
		EigenBuffer*		buffer_;
		float				samplerate_;
		float 				window_length_;
		unsigned int		nsamples_;
		unsigned int		nchannels_;
		QList<QString>		channel_labels_;
		std::vector<int> 	channel_selected_index_;

		FilterButterworth	filter_lp_;
		FilterButterworth	filter_hp_;

		float 			ScaleValue_;
		unsigned int	SpatialFilterIndex_;
		unsigned int	RefElectrodeIndex_;
		bool 			IsLowPassActive_ = false;
		float			LowPassCutoff_;
		bool 			IsHighPassActive_ = false;
		float			HighPassCutoff_;
		unsigned int	FilterOrder_;
		
		const std::vector<double>	scales_ = {  1.0f,     2.5f,     5.0f,   10.0f, 
											    25.0f,    50.0f,   100.0f,  250.0f, 
											   500.0f,  1000.0f,  2500.0f, 5000.0f, 
											 10000.0f, 25000.0f, 50000.0f};
		const std::vector<double> 	windows_ = {1.0f, 2.0f, 5.0f, 10.0f, 20.0f, 30.0f};

		QTimer plotter_;

};

class EEGPanel : public ScopePanel {
	Q_OBJECT
	public:
		EEGPanel(QString name, QWidget* parent) : ScopePanel(name, parent) {
			this->setDataType(DataType::EEG);
		}
		virtual ~EEGPanel(void) {};
};

class EXGPanel : public ScopePanel {
	Q_OBJECT
	public:
		EXGPanel(QString name, QWidget* parent) : ScopePanel(name, parent) {
			this->setDataType(DataType::EXG);
		}
		virtual ~EXGPanel(void) {};
};


#endif
