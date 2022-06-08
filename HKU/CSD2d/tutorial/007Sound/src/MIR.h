#pragma once
#include "ofMain.h"
#include "AudioFile.h"

class MIR{

  public:

    MIR();
    ~MIR();

    void updateMIR();

    int bpmTick(float bpm, float note);
    float fillFftArray(int bandsAmount, int i);
    void getAudioSample();
    float getFFTEnergy();
    float getCurrentSample();
    float onsetDetection();

    ofSoundPlayer mySound;

  private:

    // int bandsAmount;
    float *fft;
    float *soundSpectrum;
    float *sampleArray;
    float increment;
    float time;
    float energy;
    float fftSum;
    int AFnumSamples;

};
