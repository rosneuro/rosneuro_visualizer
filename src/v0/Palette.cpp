#include "rosneuro_visualizer/Palette.hpp"

Palette::Palette(void) {};
Palette::~Palette(void) {};

void Palette::add(QColor color) {
	this->palette_.push_back(color);
}

void Palette::next(void) {
	this->index_++;
	if(this->index_ >= this->palette_.size())
		this->index_ = this->index_ - this->palette_.size();
}

void Palette::previous(void) {
	this->index_--;
	if(this->index_ < 0)
		this->index_ = this->palette_.size() + this->index_;
}

QColor Palette::get(void) {
	return this->palette_.at(this->index_);
}

void Palette::reset(void) {
	this->index_ = 0;
}

