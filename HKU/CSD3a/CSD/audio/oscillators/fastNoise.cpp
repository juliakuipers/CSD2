#include "fastNoise.h"
#include <vector>
#include <iostream>

FastNoise::FastNoise(float frequency,float samplerate) :
  Oscillator(frequency, samplerate), bufferSize(128*128), bufferIndex(0){
    setNoise('p');
    noise = FastNoiseLite(1337);
    noiseData = new float [bufferSize];
    fillNoiseBuffer();
    //check samplerate om vector uit te lezen
    //noise.SetSeed(i);
}

FastNoise::~FastNoise() {
  delete [] noiseData;
  noiseData = nullptr;
}

void FastNoise::calcNextSample() {
    //nieuwe vector met noise zodra de andere is uitgelezen
    //nieuwe seed
    if(bufferIndex < bufferSize){
      sample = noiseData[bufferIndex];
      bufferIndex++;
    }
    if(bufferIndex >= bufferSize) {
      bufferIndex = 0;
      fillNoiseBuffer();
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

void FastNoise::fillNoiseBuffer() {
    int index = 0;
    for (int y = 0; y < 128; y++)
    {
        for (int x = 0; x < 128; x++)
        {
            noiseData[index++] = noise.GetNoise((float)x, (float)y);
        }
    }
    std::cout << "FastNoise::fillNoiseBuffer() buffer = filled" << '\n';
}
