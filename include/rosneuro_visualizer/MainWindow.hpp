#ifndef ROSNEURO_VISUALIZER_MAINWINDOW_HPP
#define ROSNEURO_VISUALIZER_MAINWINDOW_HPP

#include <deque>
#include <QMainWindow>
#include <QMessageBox>
#include "src/ui_neuroviz.h"
#include "src/ui_neuroviz_dialog_info.h"
#include "rosneuro_visualizer/EigenBuffer.hpp"
#include "rosneuro_visualizer/DataThread.hpp"
#include "rosneuro_visualizer/ScopePanel.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {

	Q_OBJECT
	
	public:
		MainWindow(QWidget *parent = nullptr);
		virtual ~MainWindow(void);

		void addPanel(NeuroPanel* panel);

	public slots:
	
		void on_TabChanged(int index);
		void on_InfoEvent(void);
		
		void on_StartEvent(void);
		void on_StopEvent(void);
		void on_FirstMessage(rosneuro_msgs::NeuroFrame frame);
		void on_MessageInfo(unsigned int sequence, float rate);
		void on_DataAvailable(rosneuro_msgs::NeuroFrame frame);

		

	private:
		void set_current_panel(void);

		void set_samplerate(float rate);
		void set_messagerate(float rate);
		void set_messagesequence(unsigned int sequence);
		void set_info(const rosneuro_msgs::NeuroFrame& frame);
		void store_channel_labels(const rosneuro_msgs::NeuroFrame& frame);
		void reset_channel_labels(void);
		void destroy_panel_widgets(void);

		std::string to_string(const rosneuro_msgs::NeuroDataInfo& info);


	

	private:
		Ui::NeuroVizPanel* 	ui_;
		DataThread 			thread_data_;
		NeuroPanel*			current_panel_;

		float				samplerate_;
		float				messagerate_;
		float				expected_messagerate_;
		unsigned int		sequence_;
		QString				info_;
		QList<QString>		eeg_labels_;
		QList<QString>		exg_labels_;
		QList<QString>		tri_labels_;

};


#endif
