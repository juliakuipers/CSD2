#ifndef _saw_H_
#define _saw_H_
#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator {
public:
  //Constructor and destructor
  Saw(double samplerate);
  ~Saw();

  void calculate() override;

};

#endif
