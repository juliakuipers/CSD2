#include "allPassFilter.h"

AllPassFilter::AllPassFilter() : delay1(0), delay2(0), output(0) {}

AllPassFilter::~AllPassFilter() {}

float AllPassFilter::kamFilterFIR(float input)
{
  //circBuffer???
  output = delay1 + input;
  delay1 = input;
  return output;
}

float AllPassFilter::kamFilterIIR(float input)
{
  output = input - delay2;
  delay2 = output*-0.9;
  return output;
}
