#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator {
public:
  //Constructor and destructor
  Saw(double samplerate);
  ~Saw();

  void calculate();
  double getSample();

protected:
  double phase;
  double sample;
  double samplerate;
};

#endif
