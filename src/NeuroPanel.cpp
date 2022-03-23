#include "rosneuro_visualizer/NeuroPanel.hpp"

NeuroPanel::NeuroPanel(QString name, QWidget* parent) : QWidget(parent), name_(name), isset_(false) {}

NeuroPanel::~NeuroPanel(void) {};

void NeuroPanel::setName(QString name) {
	this->name_ = name;
}

QString NeuroPanel::name(void) {
	return this->name_;
}

DataType NeuroPanel::getDataType(void) {
	return this->datatype_;
}

void NeuroPanel::setDataType(DataType type) {
	this->datatype_ = type;
}

bool NeuroPanel::isset(void) {
	return this->isset_;
}
