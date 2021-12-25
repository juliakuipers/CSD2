#ifndef _SINE_H_
#define _SINE_H_
#include "oscillator.h"
#include <iostream>

class Sine : public Oscillator{
  public:
    //Constructor and destructor
    Sine();
    ~Sine();

    void tick();

  protected:
    double phase;
};

#endif
