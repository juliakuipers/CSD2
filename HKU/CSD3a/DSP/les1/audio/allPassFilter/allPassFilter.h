#include <iostream>

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
};
