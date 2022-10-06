#include <iostream>
#include "CircularBuffer.h"

class AllPassFilter
{
  //IIR & FIR
public:

  AllPassFilter();
  ~AllPassFilter();

  float allPass(float input_);

  void setDelayTime(float time);

private:

  float kamFilterFIR(float input);
  float kamFilterIIR(float input);

  float delay1;
  float delay2;
  float output;

  CircularBuffer* circ1 = nullptr;
  CircularBuffer* circ2 = nullptr;

  float samplerate = 44100;
};
