#include "1dFastNoise.h"
#include <vector>
#include <iostream>

FastNoise::FastNoise(float frequency,float samplerate) :
  Oscillator(frequency, samplerate), xAxis(0), yAxis(0){
    setNoise('p');
    noise = FastNoiseLite(1337);
}

FastNoise::~FastNoise() {}

void FastNoise::calcNextSample() {
    if((xAxis & 1) == 0){
      sample = noise.GetNoise((float)xAxis++, (float)yAxis);
      //even xAxis numbers
      //R output
    } else {
      sample = noise.GetNoise((float)xAxis++, (float)yAxis);
      //odd xAxis numbers
      //L output
    }
}

void FastNoise::setNoise(char noiseType) {
    switch (noiseType) {
        case 'p':
            noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
        case 'c':
            noise.SetNoiseType(FastNoiseLite::NoiseType_Cellular);
    }
}
