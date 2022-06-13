#include "MIR.h"

AudioFile<float> audioFile;

MIR::MIR() :
increment(0), time(0), energy(0), mySoundPosition(0), AFnumSamples(0)
{
  mySound.load("timev2.wav");
  //load sound with OF
  audioFile.load ("/Users/Julia/Documents/Atom/HKU/CSD2d/tutorial/007Sound/bin/data/timev2.wav");
  //load sound with AF
  mySound.play();
  audioFile.printSummary();
  AFnumSamples = audioFile.getNumSamplesPerChannel();
  mySound.setPositionMS(32000);
  sampleArray = new float[AFnumSamples];
  fft = new float[512];
  for (int i = 0; i < 512; i++) {
    fft[i] = 0;
    //empty fft array
  }
  getAudioSample();
}

MIR::~MIR(){}

void MIR::updateMIR(){
  ofSoundUpdate();
  mySoundPosition = mySound.getPosition();
}

int MIR::bpmTick(float bpm, float note){
  time = ofGetElapsedTimeMillis();
  float ms = (60000/bpm) * note; //if note is 1 it results in a quarter note
  if(time >= increment){
    increment += ms;
    return 1; //calculate a +1 on the beat
  }else {
    return 0;
  }
}

float MIR::fillFftArray(int bandsAmount, int i){
  fftSum = 0.0f;
  soundSpectrum = ofSoundGetSpectrum(bandsAmount);
  fftSum += soundSpectrum[i];
  return soundSpectrum[i];
} // make an fft

void MIR::getAudioSample(){
  int channel = 0;
  for (int i = 0; i < AFnumSamples; i++)
  {
     sampleArray[i] = audioFile.samples[channel][i];
     // fill buffer with samples from song
  }
  std::cout << "MIR::getAudioSample() : buffer is filled " << std::endl;
}

float MIR::getFFTEnergy(){
  energy = 0 + fftSum;
  if(energy > 7){energy = 7;}
  float radiusIncrement = pow(0.75,energy) *ofGetWidth()/2;
  //                                        //*ofGetWidth()/2 omdat dat de radius is die ik meegeef aan fractal.circles()
  // std::cout << "MIR::getFFTEnergy : fftSum = " << fftSum << std::endl;
  return radiusIncrement;
}

float MIR::getCurrentSample(){
  int posInNumSamples = mySoundPosition * AFnumSamples;
  return sampleArray[posInNumSamples];
  //returns current sample of song 
}

float MIR::onsetDetection(){
  //calculate a peakAmount while filling the buffer
  //work with a bool
  float sample = getCurrentSample();
  float peakAmount = 0.1;
  if(sample >= peakAmount){return 1;}
  else{return 0;}
}
