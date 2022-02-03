#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>
#include "oscillator.h"

class Square : public Oscillator{
public:
  Square(double samplerate);
  ~Square();

  void calculate() override;
};

#endif
