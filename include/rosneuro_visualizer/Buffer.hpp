#ifndef BUFFER_HPP
#define	BUFFER_HPP

#include <vector>
#include <cstdio>

class Buffer {

	public: 
		Buffer(void);
		Buffer(unsigned int nsamples, unsigned int nchannels);
		virtual ~Buffer(void);

		void reset(unsigned int nsamples, unsigned int nchannels);
		void reset(void);
		bool add(const std::vector<float>& data);
		unsigned int samples(void) const;
		unsigned int channels(void) const;

	public:
		
		std::vector<std::vector<float>> 	buffer_;
		unsigned int	nchannels_;
		unsigned int	nsamples_;
		unsigned int 	index_ = 0;


};





#endif
