#pragma once
#include <iostream>
#include "CircularBuffer.h"
#include "oscillator.h"

class Chorus {
public:
  Chorus();
  ~Chorus();

private:
  Oscillator* osc = nullptr;
  CircularBuffer* circ = nullptr;


};
