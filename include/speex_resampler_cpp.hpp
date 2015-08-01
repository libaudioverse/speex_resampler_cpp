#pragma once
#include <string>
#include <functional>
#include <list>
#include <limits>
#include <algorithm>
#include <utility>

namespace speex_resampler_cpp {
/**Usage:
- Create a resampler with CreateResampler.
- Call read on some data to give it to the resampler.
- Call write to get some data out of the resampler.
- Repeat until you're done.
*/

class Resampler {
	public:
	Resampler(int inputFrameCount, int inputChannels, int inputSr, int outputSr);
	//Write some data from the resampler to an output array.
	//returns frames written, not samples.
	int write(float* dest, int maxFrameCount);
	//Put some data into the resampler.
	//this copies, the buffer can be reused.
	void read(float* source);
	//note the estimate: this is not necessarily sample-accurate.
	int estimateAvailableFrames();
	private:
	float delta = 0.0f;
	std::list<float*> queue, done_queue;
	int offset=0, input_frame_count, input_channels, input_sr, output_sr;
	SpeexResamplerState* spx_resampler= nullptr;
	int spx_error= 0;
};

}