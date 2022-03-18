#ifndef ROSNEURO_VISUALIZER_FILTER_BUTTERWORTH_HPP
#define ROSNEURO_VISUALIZER_FILTER_BUTTERWORTH_HPP

#include <vector>
#include <cmath>
#include <Eigen/Dense>
#include <rtf_common.h>
#include <rtfilter.h>

class FilterButterworth {

	public:
		FilterButterworth(void);
		virtual ~FilterButterworth(void);
		void set_type(unsigned int type);
		bool setup(unsigned int order, double samplerate, double cutoff, unsigned int nchannels);

		void apply(std::vector<float>& data);

	private:

		unsigned int 	order_;
		double 			samplerate_;
		double 			cutoff_;
		unsigned int 	nchannels_;
		hfilter 		filt_ = nullptr;
		unsigned int	type_;



};

#endif
