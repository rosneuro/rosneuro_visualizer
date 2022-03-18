#include "rosneuro_visualizer/FilterCar.hpp"


void FilterCar::apply(Eigen::MatrixXf& buffer) {

	//buffer = buffer - (buffer.rowwise().mean()).replicate(1, buffer.cols());
	buffer = buffer - (buffer.colwise().mean()).replicate(buffer.rows(), 1);

}

void FilterCar::apply(std::vector<float>& data, unsigned int nchannels) {

	unsigned int nsamples = data.size()/nchannels;
	Eigen::Map<Eigen::MatrixXf> frame(const_cast<float*>(data.data()), nchannels, nsamples);

	frame = frame - (frame.colwise().mean()).replicate(frame.rows(), 1);
}
