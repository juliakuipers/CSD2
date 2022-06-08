#include "MIR.h"

AudioFile<float> audioFile;

MIR::MIR() :
increment(0), time(0), energy(0), AFnumSamples(0)
{
  mySound.load("timev2.wav");
  audioFile.load ("/Users/Julia/Documents/Atom/HKU/CSD2d/tutorial/007Sound/bin/data/timev2.wav");
  mySound.play();
  audioFile.printSummary();
  AFnumSamples = audioFile.getNumSamplesPerChannel();
  // mySound.getPosition(); //Returns the current position as a percent 0.0-1.0

  sampleArray = new float[AFnumSamples];
  fft = new float[512];
  for (int i = 0; i < 512; i++) {
    fft[i] = 0;
  }
  getAudioSample();
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
  for (int i = 0; i < AFnumSamples; i++)
  {
     sampleArray[i] = audioFile.samples[channel][i];
  } //i need a buffer if i want to use rms
  std::cout << "MIR::getAudioSample() : buffer is filled " << std::endl;
  // num samples per channel / samplerate = length in seconds
  //length in seconds * samplerate = num samples per channel
  //if 1 sec has passed 1 times the samplerate should have been read from num sampler per channel
}

float MIR::getFFTEnergy(){
  energy = 0 + fftSum;
  if(energy > 7){energy = 7;}
  float radiusIncrement = pow(0.75,energy) *ofGetWidth()/2;
  // std::cout << "MIR::getFFTEnergy : fftSum = " << fftSum << std::endl;
  return radiusIncrement;
}

float MIR::getCurrentSample(){
  float mySoundPosition = mySound.getPosition(); //Returns the current position as a percent 0.0-1.0
  int posInNumSamples = mySoundPosition / 100 * AFnumSamples;
  return sampleArray[posInNumSamples];
}

float MIR::onsetDetection(){
  //calculate a peakAmount while filling the buffer
  //bool????
  float sample = getCurrentSample();
  float peakAmount = 0.1;
  if(sample >= peakAmount){return 1;}
  else{return 0;}
}
