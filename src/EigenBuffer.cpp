#include "rosneuro_visualizer/EigenBuffer.hpp"

EigenBuffer::EigenBuffer(void) {}

EigenBuffer::EigenBuffer(unsigned int nsamples, unsigned int nchannels) {

	this->reset(nsamples, nchannels);
}

EigenBuffer::~EigenBuffer(void) {
}

void EigenBuffer::reset(unsigned int nsamples, unsigned int nchannels) {

	//this->reset();
	this->nsamples_  = nsamples;
	this->nchannels_ = nchannels;

	// CAREFUL! Internal buffer representation is channels x samples to avoid
	// transposition
	this->buffer_ = Eigen::MatrixXf::Zero(nchannels, nsamples);
	//this->buffer_.resize(nchannels);
	//for(auto it=this->buffer_.begin(); it!=this->buffer_.end(); ++it) {
	//	(*it).resize(nsamples);
	//}

	this->index_ = 0;
}

//void EigenBuffer::reset(void) {
//	this->buffer_.clear();
//}

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

	//Eigen::Map<Eigen::MatrixXf> frame(const_cast<float*>(data.data()), data_nsamples, data_nchannels);
	
	// CAREFUL! Internal buffer representation is channels x samples to avoid
	// transposition
	Eigen::Map<Eigen::MatrixXf> frame(const_cast<float*>(data.data()), data_nchannels, data_nsamples);
	this->buffer_.block(0, this->index_, data_nchannels, data_nsamples) = frame;
	
	this->index_ = this->index_ + data_nsamples;

	//// Iterate across data vector with a step equals to the number of channels.
	//// Getting this data and save it in the deque structure
	//for(auto i = 0; i < nelems; i = i + data_nchannels) {
	//	std::vector<float> cvector = {data.begin() + i, data.begin() + i + data_nchannels};
	//	//printf("[%d %d]\n", i, i + data_nchannels - 1);	
	//	//printf("%ld\n", cvector.size());	
	//	unsigned int chId = 0;
	//	for(auto it=cvector.begin(); it!=cvector.end(); ++it) {

	//		this->buffer_.at(chId).at(this->index_) = (*it);
	//		
	//		chId++;
	//	}

	//	this->index_++;
	//}

	if(this->index_ >= this->samples())
		this->index_ = 0;

	return true;
}

const void EigenBuffer::get(const Eigen::Ref<const Eigen::MatrixXf>& out) const {
	//return this->buffer_;
}

float EigenBuffer::at(unsigned int row, unsigned int col) {
	// CAREFUL! Internal buffer representation is channels x samples to avoid
	// transposition
	return this->buffer_(col, row);
}


