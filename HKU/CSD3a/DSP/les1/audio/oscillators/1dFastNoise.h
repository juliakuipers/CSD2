#include "FastNoiseLite.h"
#include "oscillator.h"

#pragma once

class FastNoise : public Oscillator {
public:
    FastNoise(float frequency, float samplerate);
    ~FastNoise();

    void switchNoise(int noiseType);

private:
    FastNoiseLite noise;

    // void fillNoiseBuffers(); //kanweg
    void calcNextSample() override;

    int xAxis;
    int yAxis;
};
//muziek laten horen in de les
