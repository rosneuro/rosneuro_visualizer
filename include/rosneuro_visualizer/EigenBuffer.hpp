#ifndef EIGEN_BUFFER_HPP
#define	EIGEN_BUFFER_HPP

#include <Eigen/Dense>
#include <vector>
#include <cstdio>

class EigenBuffer {

	public: 
		EigenBuffer(void);
		EigenBuffer(unsigned int nsamples, unsigned int nchannels);
		virtual ~EigenBuffer(void);

		void reset(unsigned int nsamples, unsigned int nchannels);
		//void reset(void);
		bool add(const std::vector<float>& data);
		unsigned int samples(void) const;
		unsigned int channels(void) const;
		//const std::vector<std::vector<float>>& get(void) const;
		const void get(const Eigen::Ref<const Eigen::MatrixXf>& out) const;

		Eigen::MatrixXf& get(void);
		const Eigen::MatrixXf& get(void) const;
		const float at(unsigned int sampleId, unsigned int channelId) const;

	private:
		
		//std::vector<std::vector<float>> 	buffer_;
		Eigen::MatrixXf buffer_;
		unsigned int	nchannels_;
		unsigned int	nsamples_;
		unsigned int 	index_ = 0;


};





#endif
