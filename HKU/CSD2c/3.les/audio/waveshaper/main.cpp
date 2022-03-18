#include "waveshaper.h"

int main()
{
  Waveshaper effect(440,44100);
  effect.calculateM(-0.24);
}
