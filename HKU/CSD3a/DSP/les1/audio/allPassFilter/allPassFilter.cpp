#include "allPassFilter.h"

AllPassFilter::AllPassFilter() : delay1(0), delay2(0), output(0) {
  circ1 = new CircularBuffer(5,1);
  circ2 = new CircularBuffer(5,1);
}

AllPassFilter::~AllPassFilter() {
  delete circ1;
  circ1 = nullptr;
  delete circ2;
  circ2 = nullptr;
}

float AllPassFilter::kamFilterFIR(float input)
{
  //circBuffer???
  circ1->write(input);
  output = circ1->read() + input;
  return output;
}

float AllPassFilter::kamFilterIIR(float input)
{
  circ2->write(input);
  output = input - circ2->read();
  // delay2 = output*-0.9;
  return output;
}
