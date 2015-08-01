#pragma once
#include <memory>

namespace speex_resampler_cpp {
/**Usage:
- Create a resampler with createResampler.
- Call read on some data to give it to the resampler.
- Call write to get some data out of the resampler.
- Repeat until you're done.
*/

class Resampler {
	public:
	virtual ~Resampler() {}
	//Write some data from the resampler to an output array.
	//returns frames written, not samples.
	virtual int write(float* dest, int maxFrameCount) = 0;
	//Put some data into the resampler.
	//this copies, the buffer can be reused.
	virtual void read(float* source) = 0;
	//note the estimate: this is not necessarily sample-accurate.
	virtual int estimateAvailableFrames() = 0;
	
	protected:
	Resampler() = default;
};

std::shared_ptr<Resampler> createResampler(int inputFrameCount, int inputChannels, int inputSr, int outputSr);

}