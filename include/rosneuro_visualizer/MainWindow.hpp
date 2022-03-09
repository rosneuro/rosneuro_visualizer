#ifndef ROSNEURO_VISUALIZER_MAINWINDOW_HPP
#define ROSNEURO_VISUALIZER_MAINWINDOW_HPP

#include <QMainWindow>
#include "src/ui_panel.h"
#include "rosneuro_visualizer/NeuroDataManagement.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {

	Q_OBJECT

	public:
		MainWindow(NeuroDataManagement* system, QWidget *parent = nullptr);
		virtual ~MainWindow(void);

	public slots:
		void on_TopicButtonToggled(void);
		void on_TopicValueChanged(void);

	private:
		void toggle_running_state(void);
		
	private:
		Ui::NeuroVizPanel* ui_;
		bool is_scope_running_;
		NeuroDataManagement* system_;


};


#endif
