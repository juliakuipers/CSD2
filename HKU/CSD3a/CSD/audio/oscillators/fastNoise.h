#include "FastNoiseLite.h"
#include "oscillator.h"

#pragma once

class FastNoise : public Oscillator {
public:
    FastNoise(float frequency, float samplerate);
    ~FastNoise();

    // float calculate() override;
    void setNoise(char noiseType);

private:
    FastNoiseLite noise;

    int bufferSize;
    int bufferIndex;

    float* noiseDataX = nullptr;
    float* noiseDataY = nullptr;

    void fillNoiseBuffers();
    void calcNextSample() override;
};