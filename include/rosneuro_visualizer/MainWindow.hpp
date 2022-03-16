#ifndef ROSNEURO_VISUALIZER_MAINWINDOW_HPP
#define ROSNEURO_VISUALIZER_MAINWINDOW_HPP

#include <deque>
#include <QMainWindow>
#include <QMessageBox>
#include "src/ui_panel.h"
#include "src/ui_dialog_info.h"
#include "rosneuro_visualizer/DataThread.hpp"
#include "rosneuro_visualizer/ScopePanel.hpp"
#include "rosneuro_visualizer/Buffer.hpp"
#include "rosneuro_visualizer/EigenBuffer.hpp"

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
		void on_ChannelsChanged(void);
		void on_ScaleChanged(void);
		void on_WindowChanged(void);
		
		void on_DataInfo(float samplerate, unsigned int nchannels, QList<QString> labels, QString info);
		void on_MessageInfo(unsigned int sequence, float rate);
		void on_DataAvailable(std::vector<float> data);
		
		void ui_set_samplerate(float samplerate);
		void ui_set_channels(const QList<QString>& labels);
		void ui_set_info(const QString& info);

	private:
		
	private:
		Ui::NeuroVizPanel* 	ui_;
		DataThread 			thread_;
		
		ScopePanel*			scope_;
		//Buffer				buffer_;
		EigenBuffer				buffer_;
		unsigned int		window_size_ = 10;
		float				samplerate_;

		QVector<int>		channel_index_selected_;
		QString				info_;
		const std::vector<double>	scales_ = {  1.0f,     2.5f,     5.0f,   10.0f, 
											    25.0f,    50.0f,   100.0f,  250.0f, 
											   500.0f,  1000.0f,  2500.0f, 5000.0f, 
											 10000.0f, 25000.0f, 50000.0f};
		const std::vector<double> 	windows_ = {1.0f, 2.0f, 5.0f, 10.0f, 20.0f, 30.0f};

};


#endif
