#ifndef ROSNEURO_VISUALIZER_NEUROPANEL_HPP
#define ROSNEURO_VISUALIZER_NEUROPANEL_HPP

#include <QWidget>
#include "rosneuro_msgs/NeuroFrame.h"

enum class DataType {EEG, EXG, TRI, UNKNOWN};

class NeuroPanel : public QWidget {

	Q_OBJECT
	
	public:
		NeuroPanel(QString name, QWidget* parent = nullptr);
		virtual ~NeuroPanel(void);

		virtual bool setup(const rosneuro_msgs::NeuroFrame& frame) = 0;
		virtual void reset(void) = 0;
		virtual void update(const rosneuro_msgs::NeuroFrame& frame) = 0;
		virtual void draw(void) = 0;
		virtual bool isset(void);

		DataType getDataType(void);
		void setDataType(DataType type);

		void setName(QString name);
		QString name(void);

	protected:
		QString  	name_;
		DataType 	datatype_ = DataType::UNKNOWN;
		bool		isset_;		

};


#endif
