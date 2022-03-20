#include <iostream>
#include "pickSample.h"
using namespace std;

int main()
{
  PickSample ps(440,44100);
  for(int i = 0; i < 100; i++)
  {
    float xi = i/100;
    cout << "main - xi = " << xi << endl;
    ps.calculateM(xi);
  }
  // WriteToFile writeFile("output.csv",true);
  // std::cout << "hi \n";
  // audioFile.load ("../eigenEffect/samples/OH.wav");
  //
  // int sampleRate = audioFile.getSampleRate();
  // int bitDepth = audioFile.getBitDepth();
  //
  // int numSamples = audioFile.getNumSamplesPerChannel();
  // double lengthInSeconds = audioFile.getLengthInSeconds();
  //
  // int numChannels = audioFile.getNumChannels();
  // bool isMono = audioFile.isMono();
  // bool isStereo = audioFile.isStereo();
  // int channel = 0;
  //
  // audioFile.printSummary();
  //
  // for(int i = 0; i < numSamples; i++)
  // {
  //   double currentSample = audioFile.samples[channel][i];
  //   writeFile.write(std::to_string(currentSample )+ "\n");
  // }

}
