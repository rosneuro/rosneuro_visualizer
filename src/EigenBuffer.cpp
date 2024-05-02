#include "rosneuro_visualizer/EigenBuffer.hpp"

EigenBuffer::EigenBuffer(unsigned int nsamples, unsigned int nchannels) {
	this->reset(nsamples, nchannels);
}

EigenBuffer::~EigenBuffer(void) {
}

void EigenBuffer::reset(unsigned int nsamples, unsigned int nchannels) {
	this->nsamples_  = nsamples;
	this->nchannels_ = nchannels;
	this->buffer_ = Eigen::MatrixXf::Zero(nchannels, nsamples);
	this->index_ = 0;
}

unsigned int EigenBuffer::samples(void) const {
	return this->nsamples_;
}

unsigned int EigenBuffer::channels(void) const {
	return this->nchannels_;
}

bool EigenBuffer::add(const std::vector<float>& data) {

	unsigned int data_nsamples, data_nchannels;
	unsigned int nelems = data.size();

	data_nchannels = this->channels();
	data_nsamples  = nelems/data_nchannels;

	if(data_nsamples > this->samples())
		return false;

	Eigen::Map<Eigen::MatrixXf> frame(const_cast<float*>(data.data()), data_nchannels, data_nsamples);
	this->buffer_.block(0, this->index_, data_nchannels, data_nsamples) = frame;
	
	this->index_ = this->index_ + data_nsamples;

	if(this->index_ >= this->samples()) {
        this->index_ = 0;
    }

	return true;
}

const float EigenBuffer::at(unsigned int sampleId, unsigned int channelId) const {
	// CAREFUL! Internal buffer representation is channels x samples to avoid
	return this->buffer_(channelId, sampleId);
}

Eigen::MatrixXf& EigenBuffer::get(void) {
	return this->buffer_;
}

const Eigen::MatrixXf& EigenBuffer::get(void) const {
	return this->buffer_;
}
