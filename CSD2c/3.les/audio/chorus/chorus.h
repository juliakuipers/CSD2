#pragma once
#include <iostream>
#include "circularBuffer.h"
#include "oscillator.h"

class Chorus {
public:
  Chorus();
  ~Chorus();

private:
  Oscillator* osc = nullptr;

};
