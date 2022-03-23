#include "rosneuro_visualizer/EigenBuffer.hpp"

EigenBuffer::EigenBuffer(void) {}

EigenBuffer::EigenBuffer(unsigned int nsamples, unsigned int nchannels) {

	this->reset(nsamples, nchannels);
}

EigenBuffer::~EigenBuffer(void) {}

void EigenBuffer::reset(unsigned int nsamples, unsigned int nchannels) {

	this->nsamples_  = nsamples;
	this->nchannels_ = nchannels;

	// CAREFUL! Internal buffer representation is channels x samples to avoid
	// transposition
	this->buffer_ = Eigen::MatrixXf::Zero(nchannels, nsamples);

	this->index_ = 0;
}

unsigned int EigenBuffer::samples(void) const {
	unsigned int csamples = this->nsamples_;
	return csamples;
}

unsigned int EigenBuffer::channels(void) const {
	unsigned int cchannels = this->nchannels_;
	return cchannels;
}

bool EigenBuffer::add(const std::vector<float>& data) {

	unsigned int data_nsamples, data_nchannels;
	unsigned int nelems = data.size();

	// The number of channels must be the same, so getting the number of the
	// samples of data dividing the number of elements per the number of
	// channels in the buffer
	data_nchannels = this->channels();
	data_nsamples  = nelems/data_nchannels;

	// If the number of samples if greater than the dimension of the buffer,
	// then return false
	if(data_nsamples > this->samples())
		return false;
	
	// CAREFUL! Internal buffer representation is channels x samples to avoid
	// transposition
	Eigen::Map<Eigen::MatrixXf> frame(const_cast<float*>(data.data()), data_nchannels, data_nsamples);
	this->buffer_.block(0, this->index_, data_nchannels, data_nsamples) = frame;
	
	this->index_ = this->index_ + data_nsamples;

	if(this->index_ >= this->samples())
		this->index_ = 0;

	return true;
}

const void EigenBuffer::get(const Eigen::Ref<const Eigen::MatrixXf>& out) const {
	//return this->buffer_;
}

const float EigenBuffer::at(unsigned int sampleId, unsigned int channelId) const {
	// CAREFUL! Internal buffer representation is channels x samples to avoid
	// transposition
	return this->buffer_(channelId, sampleId);
}

Eigen::MatrixXf& EigenBuffer::get(void) {
	return this->buffer_;
}

const Eigen::MatrixXf& EigenBuffer::get(void) const {
	return this->buffer_;
}


