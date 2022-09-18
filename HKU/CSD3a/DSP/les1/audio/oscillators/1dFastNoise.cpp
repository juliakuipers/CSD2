#include "1dFastNoise.h"
#include <iostream>

FastNoise::FastNoise(float frequency,float samplerate) :
  Oscillator(frequency, samplerate), xAxis(0), yAxis(0){
    noise = FastNoiseLite(1337);
}

FastNoise::~FastNoise() {}

void FastNoise::calcNextSample() {
    if((xAxis & 1) == 0){
      sample = noise.GetNoise((float)xAxis++, (float)yAxis);
      //even xAxis numbers
      std::cout << "FastNoise::calcNextSample() xAxis R = " << xAxis << '\n';
      //R output
    } else {
      sample = noise.GetNoise((float)xAxis++, (float)yAxis);
      std::cout << "FastNoise::calcNextSample() sample L = " << sample << '\n';
      std::cout << "FastNoise::calcNextSample() xAxis L = " << xAxis << '\n';
      //odd xAxis numbers
      //L output
    }
    if(xAxis > samplerate*10){
      yAxis += 1;
      std::cout << "FastNoise::calcNextSample() yAxis += 1 " << '\n';
    }
    if(yAxis > samplerate*10){
      xAxis = 0;
      yAxis = 0;
    }
    // std::cout << "sample = " << sample << '\n';
}

void FastNoise::switchNoise(int noiseType) {
  switch (noiseType) {
      case 0:
          noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
      case 1:
          noise.SetNoiseType(FastNoiseLite::NoiseType_Cellular);
      case 2:
          noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
      case 3:
          noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2S);
      case 4:
          noise.SetNoiseType(FastNoiseLite::NoiseType_Value);
      case 5:
          noise.SetNoiseType(FastNoiseLite::NoiseType_ValueCubic);
  }
}
