#include "freqShifter.h"


int main()
{
  FreqShifter effect(440,44100);
  effect.calculate(0.4);
}
