#ifndef ROSNEURO_VISUALIZER_REFERENCE_HPP
#define ROSNEURO_VISUALIZER_REFERENCE_HPP

#include <vector>
#include <Eigen/Dense>
#include "rosneuro_visualizer/EigenBuffer.hpp"

class FilterReference {

	public:
		static void apply(Eigen::MatrixXf& buffer, unsigned int refIdx);
		static void apply(std::vector<float>& data, unsigned int nchannels, unsigned int refIdx);
};



#endif
