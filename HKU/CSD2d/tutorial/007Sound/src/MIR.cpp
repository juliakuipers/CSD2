#include "MIR.h"

AudioFile<float> audioFile;

MIR::MIR() :
bandsAmount(512), increment(0), time(0), energy(0)
{
  mySound.load("timev2.wav");
  audioFile.load ("/Users/Julia/Documents/Atom/HKU/CSD2d/tutorial/007Sound/bin/data/timev2.wav");
  mySound.play();
  audioFile.printSummary();

  fft = new float[bandsAmount];
  for (int i = 0; i < bandsAmount; i++) {
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

void MIR::fillFftArray(){
  fftSum = 0.0f;
  soundSpectrum = ofSoundGetSpectrum(bandsAmount);
  for (int i = 0; i < bandsAmount; i++) {
    fft[i] *= 0.9; //decay
    if (fft[i] < soundSpectrum[i]) {
      fft[i] = soundSpectrum[i];
      fftSum += soundSpectrum[i];
    }
  }
}

void MIR::getAudioSample(){
  int channel = 0;
  int numSamples = audioFile.getNumSamplesPerChannel();

  for (int i = 0; i < numSamples; i++)
  {
     double currentSample = audioFile.samples[channel][i];
     std::cout << "currentSample = " << currentSample << std::fixed << std::endl;
  }
  //return sample
}

float MIR::getEnergy(){
  energy = 0 + fftSum;
  if(energy > 7){energy = 7;}
  float radiusIncrement = pow(0.75,energy) *ofGetWidth()/2;
  return energy;
}
