#pragma once
#include "ofMain.h"
#include "AudioFile.h"

class MIR{

  public:

    MIR();
    ~MIR();

    void updateMIR();

    int bpmTick(float bpm, float note);
    float fillFftArray();
    void getAudioSample();
    float getEnergy();

    ofSoundPlayer mySound;

  private:

    int bandsAmount;
    float *fft;
    float *soundSpectrum;
    float increment;
    float time;
    float energy;
    float fftSum;
};
