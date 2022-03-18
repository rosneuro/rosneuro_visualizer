#ifndef ROSNEURO_VISUALIZER_CAR_HPP
#define ROSNEURO_VISUALIZER_CAR_HPP

#include <vector>
#include <Eigen/Dense>
#include "rosneuro_visualizer/EigenBuffer.hpp"

class FilterCar {

	public:
		static void apply(Eigen::MatrixXf& buffer);
		static void apply(std::vector<float>& data, unsigned int nchannels);
};



#endif
