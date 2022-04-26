#include "MIR.h"
AudioFile<float> audioFile;

MIR::MIR() : numSamples(0)
{
  audioFile.load ("./WAV/timev2.wav");
  audioFile.printSummary();
  numSamples = audioFile.getNumSamplesPerChannel();
  buffer = new float [numSamples];
  audioBuffer();
}

MIR::~MIR()
{
  delete [] buffer;
  buffer = nullptr;
}

void MIR::audioBuffer()
{
  int channel = 0;

  for (int i = 0; i < numSamples; i++)
    {
     buffer[i] = audioFile.samples[channel][i];
    }
}

float MIR::playWAV()
{
  int sampleCount = 0;
  if(sampleCount < numSamples){
    float sample = buffer[sampleCount];
    sampleCount += 1;
    return sample;
  } else {
    return 0;
  }
}
