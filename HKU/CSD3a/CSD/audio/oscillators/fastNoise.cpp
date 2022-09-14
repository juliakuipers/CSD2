#include "fastNoise.h"
#include <vector>
#include <iostream>

FastNoise::FastNoise(float frequency,float samplerate) :
  Oscillator(frequency, samplerate), bufferSize((samplerate*samplerate)/2), bufferIndex(0){
    setNoise('p');
    noise = FastNoiseLite(1337);
    noiseDataX = new float [bufferSize];
    noiseDataY = new float [bufferSize];
    fillNoiseBuffers();
    //check samplerate om vector uit te lezen
    //noise.SetSeed(i);
}

FastNoise::~FastNoise() {
  delete [] noiseDataX;
  delete [] noiseDataY;
  noiseDataX = nullptr;
  noiseDataY = nullptr;
}

void FastNoise::calcNextSample() {
    //nieuwe vector met noise zodra de andere is uitgelezen
    if(bufferIndex < bufferSize){
      sample = noiseDataX[bufferIndex];
      sample = noiseDataY[bufferIndex];
      bufferIndex++;
    }
    if(bufferIndex >= bufferSize) {
      bufferIndex = 0;
      std::cout << "FastNoise::calcNextSample() refilling buffer" << '\n';
      fillNoiseBuffers();
      //seed needs to be changed
    }
    //to calc next sample: sample =
}

void FastNoise::setNoise(char noiseType) {
    switch (noiseType) {
        case 'p':
            noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
        case 'c':
            noise.SetNoiseType(FastNoiseLite::NoiseType_Cellular);
    }
}

void FastNoise::fillNoiseBuffers(){
  //nieuwe seed
  int index = 0;
  for (int y = 0; y < 128; y++)
  {
    for (int x = 0; x < 128; x ++)
    {
      if((x & 1) == 0){
        std::cout << "FastNoise::fillNoiseBuffer() noiseDataX[" << index << "] = " << noiseDataX[index] << '\n';
        noiseDataX[index++] = noise.GetNoise((float)x, (float)y);
      } else {
        std::cout << "FastNoise::fillNoiseBuffer() noiseDataY[" << index << "] = " << noiseDataY[index] << '\n';
        noiseDataY[index++] = noise.GetNoise((float)x, (float)y);
      }
    }
  }
  std::cout << "FastNoise::fillNoiseBuffer() buffer = filled" << '\n';
}
