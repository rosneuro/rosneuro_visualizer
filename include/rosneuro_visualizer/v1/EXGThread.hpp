#ifndef ROSNEURO_VISUALIZER_EXGTHREAD_HPP
#define ROSNEURO_VISUALIZER_EXGTHREAD_HPP

#include <ros/ros.h> // only for sleeping in the main loop TO BE CHECKED
#include "src/ui_panel.h"
#include "rosneuro_visualizer/NeuroThread.hpp"

class EXGThread : public NeuroThread {

	Q_OBJECT

	public:
		EXGThread(Ui::NeuroVizPanel* ui, QObject* parent = nullptr);
		virtual ~EXGThread(void);

	public slots:
		void on_ScaleChanged(int index);
	protected:
		void run(void) override;

	private:
		double scale_;

		const std::vector<double>	scales_ = {  1.0f,     2.5f,     5.0f,   10.0f, 
											    25.0f,    50.0f,   100.0f,  250.0f, 
											   500.0f,  1000.0f,  2500.0f, 5000.0f, 
											 10000.0f, 25000.0f, 50000.0f};

};


#endif
