#include "waveshaper.h"

int main()
{
  Waveshaper effect;
  effect.setCurve(1);
  effect.calculate(-0.38);
}
