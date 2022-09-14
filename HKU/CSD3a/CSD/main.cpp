#include "1dFastNoise.h"

int main(){
  // NoiseGen noise1(440,100);
  // noise1.genNextSample();
  FastNoise noise1(44,100);
  for(int i = 0; i < 128*129; i++)
  {
    noise1.genNextSample();
  }
  return 0;
}
