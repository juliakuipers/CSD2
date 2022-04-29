#include "MIR.h"
AudioFile<float> audioFile;

MIR::MIR() : numSamples(0), sampleCount(0)
{
  audioFile.load ("./WAV/timev2.wav");
  audioFile.printSummary();
  numSamples = audioFile.getNumSamplesPerChannel();
  bufferR = new float [numSamples];
  bufferL = new float [numSamples];
  audioBuffer();
}

MIR::~MIR()
{
  delete [] bufferR;
  delete [] bufferL;
  bufferR = nullptr;
  bufferL = nullptr;
}

void MIR::audioBuffer()
{
  // int channel = 0;

  for (int i = 0; i < numSamples; i++)
    {
     bufferL[i] = audioFile.samples[0][i];
     bufferR[i] = audioFile.samples[1][i];
    }
}

float MIR::playRWAV()
{
  if(sampleCount < numSamples){
    float sample = bufferR[sampleCount];
    sampleCount += 1;
    std::cout << "bufferR[sampleCount] = " << bufferR[sampleCount] << std::endl;
    return sample;
  } else {
    return 0;
  }
}
float MIR::playLWAV()
{
  if(sampleCount < numSamples){
    float sample = bufferL[sampleCount];
    std::cout << "bufferL[sampleCount] = " << bufferL[sampleCount] << std::endl;
    sampleCount += 1;
    return sample;
  } else {
    return 0;
  }
}
