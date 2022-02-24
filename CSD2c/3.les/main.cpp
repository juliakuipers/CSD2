#include <iostream>
#include <thread>
#include <unistd.h>
#include "jack_moduleStereo.h"
#include "oscillator.h"

JackModule jack;
unsigned long samplerate=44100;
unsigned long chunksize = 256;
Oscillator* osc = nullptr;
Oscillator* osc = nullptr;

bool running = true;
static void audioProcess()
{
  float *inBuffer = new float [chunksize];
  float *outBuffer = new float [chunksize*2];
  do{
      jack.readSamples(inBuffer,chunksize);
      for(unsigned int i = 0 ; i<chunksize ; i++)
      {
        outBuffer[2*i] = osc1.getSample()*amp;
        outBuffer[2*i+1] = osc2.getSample()*amp;
        osc1.genNextSample()
        osc2.genNextSample()
        std::cout << "audioProcess \n";
        }
      jack.writeSamples(outBuffer,chunksize*2);
  }while(running);
}


int main(int argc,char **argv)
{
  jack.setNumberOfInputChannels(1);
  jack.setNumberOfOutputChannels(2);
  jack.init(argv[0]);
  jack.autoConnect();
  samplerate=jack.getSamplerate();
  osc1 = new Sine(440,samplerate);
  osc2 = new Sine(220,samplerate);
  float amp = 0.2;
  std::cout << "samplerate = " << samplerate << std::endl;

  std::cout << "running \n";
  std::thread audioThread(audioProcess);
  while(running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        break;
    }
  }
  audioThread.join();
  delete osc1;
  delete osc2;
  osc1 nullptr;
  osc2 nullptr;
  //ending the thread
  return 0;
}
