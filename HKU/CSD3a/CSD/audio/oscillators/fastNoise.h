//
// Created by Julia Kuipers on 12/09/2022.
//

#include "FastNoiseLite.h"
#include "oscillator.h"

#pragma once

class FastNoise : public Oscillator {
public:
    FastNoise(float frequency, float samplerate);
    ~FastNoise();

    // float calculate() override;
    void setNoise(char noiseType);
    //array?

private:
    FastNoiseLite noise;
    int bufferSize;
    int bufferIndex;
    float* noiseData = nullptr;
    void fillNoiseBuffer();
    void calcNextSample() override;
};
