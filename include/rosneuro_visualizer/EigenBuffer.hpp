#ifndef ROSNEURO_VISUALIZER_EIGENBUFFER_HPP
#define	ROSNEURO_VISUALIZER_EIGENBUFFER_HPP

#include <Eigen/Dense>
#include <vector>
#include <cstdio>
#include <gtest/gtest_prod.h>

class EigenBuffer {

	public: 
		EigenBuffer(unsigned int nsamples, unsigned int nchannels);
		virtual ~EigenBuffer(void);

		void reset(unsigned int nsamples, unsigned int nchannels);
		bool add(const std::vector<float>& data);
		unsigned int samples(void) const;
		unsigned int channels(void) const;

		Eigen::MatrixXf& get(void);
		const Eigen::MatrixXf& get(void) const;
		const float at(unsigned int sampleId, unsigned int channelId) const;

	private:
		Eigen::MatrixXf buffer_;
		unsigned int	nchannels_;
		unsigned int	nsamples_;
		unsigned int 	index_ = 0;

        FRIEND_TEST(EigenBufferTestSuite, AppendDataTest);
};





#endif
