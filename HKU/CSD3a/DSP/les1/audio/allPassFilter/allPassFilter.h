#include <iostream>
#include "CircularBuffer.h"

class AllPassFilter
{
  //IIR & FIR
public:

  AllPassFilter();
  ~AllPassFilter();

  float kamFilterFIR(float input);
  float kamFilterIIR(float input);

private:

  float delay1;
  float delay2;
  float output;

  CircularBuffer* circ1 = nullptr;
  CircularBuffer* circ2 = nullptr;

  float samplerate = 44100;
};
