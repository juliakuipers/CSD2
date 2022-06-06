#include "MIR.h"

AudioFile<float> audioFile;

MIR::MIR() :
increment(0), time(0), energy(0)
{
  mySound.load("timev2.wav");
  audioFile.load ("/Users/Julia/Documents/Atom/HKU/CSD2d/tutorial/007Sound/bin/data/timev2.wav");
  mySound.play();
  audioFile.printSummary();

  fft = new float[512];
  for (int i = 0; i < 512; i++) {
    fft[i] = 0;
  }
}

MIR::~MIR(){}

void MIR::updateMIR(){
  ofSoundUpdate();
}

int MIR::bpmTick(float bpm, float note){
  time = ofGetElapsedTimeMillis();
  float ms = (60000/bpm) * note; //if note is 1 it results in a quarter note
  if(time >= increment){
    increment += ms;
    return 1;
  }else {
    return 0;
  }
}

float MIR::fillFftArray(int bandsAmount, int i){
  fftSum = 0.0f;
  soundSpectrum = ofSoundGetSpectrum(bandsAmount);
  fftSum += soundSpectrum[i];
  return soundSpectrum[i];
}

void MIR::getAudioSample(){
  int channel = 0;
  int numSamples = audioFile.getNumSamplesPerChannel();
  for (int i = 0; i < numSamples; i++)
  {
     float sample = audioFile.samples[channel][i];
     std::cout << "currentSample = " << currentSample << std::fixed << std::endl;
  } //heb ik hier een buffer voor nodig????
  return sample
}

float MIR::getFFTEnergy(){
  energy = 0 + fftSum;
  if(energy > 7){energy = 7;}
  float radiusIncrement = pow(0.75,energy) *ofGetWidth()/2;
  return energy;
}
