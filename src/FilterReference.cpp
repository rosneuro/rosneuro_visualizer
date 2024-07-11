#include "rosneuro_visualizer/FilterReference.hpp"

void FilterReference::apply(Eigen::MatrixXf& buffer, unsigned int refIdx) {
	buffer = buffer - buffer.row(refIdx).replicate(buffer.rows(), 1);
}

void FilterReference::apply(std::vector<float>& data, unsigned int nchannels, unsigned int refIdx) {
	unsigned int nsamples = data.size()/nchannels;
	Eigen::Map<Eigen::MatrixXf> frame(const_cast<float*>(data.data()), nchannels, nsamples);
	frame = frame - frame.row(refIdx).replicate(frame.rows(), 1);
}
