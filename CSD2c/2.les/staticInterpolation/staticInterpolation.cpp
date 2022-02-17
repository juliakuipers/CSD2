#include "staticInterpolation.h"
#include "sine.h"
//needs an oscillator

StaticInterpolation::StaticInterpolation()
{
  circ = new CircularBuffer(2,1);
  //size and numSamplesDelay of circ should be 2 and 1
  float freq = 440;
  float samplerate = 44100;
  osc = new Sine(freq, samplerate);
}

StaticInterpolation::~StaticInterpolation()
{
  delete circ;
  circ = nullptr;
}

float StaticInterpolation::nnMap(float sample)
{
  float low = -1;
  float high = 1;
  if(sample > 0.5) sample = high;
  else sample = low;
  return sample;
}

float StaticInterpolation::linMap(float sample)
{
  //so as input i have two samples of the oscillator and my current sample
  //i need a buffer for the Sine
  //also the possibility to change the frequency of the Sine
   

  circ->write(sample);
  return circ->read();
}


//the low sample which is the current sample
//the high sample which is from the future, the sample in the buffer, a sample which has not been played yet
//the sample that gets calculated is the 0.5 sample the x between 0 and 1.
//so then i would need the indexes of the buffer
//the buffer needs a size of 2, one for the current and one for the future
//for this to work i need the 'future' sample and the current sample
//maybe i can assign a 0 to the current and a 1 to the future sample
//i dont think it matters what exact number the x samples are on only whats behind the . (the exact position of the x between the two x's)
//i also might need a functionality where i put the waveform (sine, square ect) into the buffer
//the formula: y = y1 + (x - x1) * (y2 - y1) / (x2 - x1)
//y1 = the first sample, the current sample
//y2 = the 'future' sample
//y = the linear interpolated sample
//x1 = the position in the buffer of the current sample (might be 0)
//x2 = the position in the buffer of the 'future' sample (might be 1)
//x = the position between the two samples whereof i want a linear interpolated sample
