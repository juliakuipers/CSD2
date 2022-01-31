#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include "oscillator.h"

class Sine : public Oscillator {
  public:
    //Constructor and destructor
    Sine(double samplerate,double freq,double amp,double phase);
    ~Sine();

    // go to next sample
    void calculate();
    double getSample();
    //virtual double getFreq() = 0;
    //virtual double getAmp() = 0;

  protected:
    double sample;
    double samplerate;
    double freq;
    double amp;
    double phase;
    

};

#endif