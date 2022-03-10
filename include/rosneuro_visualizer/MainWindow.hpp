#ifndef ROSNEURO_VISUALIZER_MAINWINDOW_HPP
#define ROSNEURO_VISUALIZER_MAINWINDOW_HPP

#include <QMainWindow>
#include <QMessageBox>
#include "src/ui_panel.h"
#include "src/ui_dialog_info.h"
#include "rosneuro_visualizer/DataThread.hpp"
#include "rosneuro_visualizer/DataPlot.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {

	Q_OBJECT

	public:
		MainWindow(QWidget *parent = nullptr);
		virtual ~MainWindow(void);

	public slots:
		void on_TopicButton(void);
		void on_InfoButton(void);
		void on_TopicValueChanged(void);
		void on_InfoSamplerate(unsigned int samplerate);
		void on_InfoChannels(QList<QString> labels);
		void on_InfoData(QString info);
		void on_InfoMessageSequence(unsigned int sequence);
		void on_InfoMessageRate(float rate);
		void on_NewData(void);
		void on_ChannelsChanged(void);

	private:
		
	private:
		Ui::NeuroVizPanel* 	ui_;
		DataThread 			thread_;
		QString 			data_info_;
		DataPlot			data_plot_;

		QList<QString>		LbChannels_;
		unsigned int		NumChannels_shown_;
		QList<QString>		LbChannels_shown_;

};


#endif
