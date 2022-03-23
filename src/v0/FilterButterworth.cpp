#include "rosneuro_visualizer/FilterButterworth.hpp"

FilterButterworth::FilterButterworth(void) {
}

FilterButterworth::~FilterButterworth(void) {
	rtf_destroy_filter(this->filt_);
}

void FilterButterworth::set_type(unsigned int type) {
	this->type_ = type;
}

bool FilterButterworth::setup(unsigned int order, double samplerate, double cutoff, unsigned int nchannels) {

	double normfc;
	bool retcod = true;

	this->order_ 		= order;
	this->samplerate_ 	= samplerate;
	this->cutoff_ 		= cutoff;
	this->nchannels_ 	= nchannels;

	normfc = this->cutoff_/this->samplerate_;
	this->filt_ = rtf_create_butterworth(this->nchannels_, RTF_FLOAT, normfc, this->order_, this->type_);

	if(this->filt_ == nullptr)
		retcod = false;

	return retcod;
}

void FilterButterworth::apply(std::vector<float>& data) {

	unsigned nchannels = this->nchannels_;
	unsigned nsamples  = data.size()/nchannels;
	
	float* input;
	float  output[nchannels*nsamples];

	input = data.data();

	rtf_filter(this->filt_, input, output, nsamples);

	data.assign(output, output + nchannels*nsamples);

}

