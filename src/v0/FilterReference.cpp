#include "rosneuro_visualizer/FilterReference.hpp"


void FilterReference::apply(Eigen::MatrixXf& buffer, unsigned int refIdx) {

	//buffer = buffer - (buffer.rowwise().mean()).replicate(1, buffer.cols());
	buffer = buffer - buffer.row(refIdx).replicate(1, buffer.cols());

}

void FilterReference::apply(std::vector<float>& data, unsigned int nchannels, unsigned int refIdx) {

	
	unsigned int nsamples = data.size()/nchannels;
	//printf("Samples: %d, Channels: %d\n", nsamples, nchannels);
	Eigen::Map<Eigen::MatrixXf> frame(const_cast<float*>(data.data()), nchannels, nsamples);

	//printf("[%ld %ld]\n", frame.row(refIdx).replicate(frame.rows(), 1).rows(), frame.row(refIdx).replicate(frame.rows(), 1).cols());
	frame = frame - frame.row(refIdx).replicate(frame.rows(), 1);
}
