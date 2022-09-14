#include "FastNoiseLite.h"
#include "oscillator.h"

#pragma once

class FastNoise : public Oscillator {
public:
    FastNoise(float frequency, float samplerate);
    ~FastNoise();

    void setNoise(char noiseType);

private:
    FastNoiseLite noise;

    // void fillNoiseBuffers(); //kanweg
    void calcNextSample() override;

    float xAxis;
    float yAxis;
};
