#include "1dFastNoise.h"
#include <iostream>

FastNoise::FastNoise(float frequency,float samplerate) :
  Oscillator(frequency, samplerate), xAxis(0), yAxis(0){
    noise = FastNoiseLite(1337);
    switchNoise(4);
}

FastNoise::~FastNoise() {}

void FastNoise::calcNextSample() {
    if((xAxis & 1) == 0){
      sample = noise.GetNoise((float)xAxis++, (float)yAxis);
      //even xAxis numbers
      //R output
      std::cout << "Fastnoise::calcNextSample() sample R = " << sample << '\n';
    } else {
      sample = noise.GetNoise((float)xAxis++, (float)yAxis);
      //odd xAxis numbers
      //L output
      std::cout << "Fastnoise::calcNextSample() sample L = " << sample << '\n';
    }
    if(xAxis > samplerate*10){
      yAxis += 1;
      // std::cout << "FastNoise::calcNextSample() yAxis += 1 " << '\n';
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
