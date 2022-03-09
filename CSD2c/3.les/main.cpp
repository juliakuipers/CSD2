#include <iostream>
#include <thread>
#include <unistd.h>
#include "jack_moduleStereo.h"
#include "square.h"
#include "chorus.h"
// #include "waveshaper.h"
#include "Tremolo.h"

JackModule jack;
unsigned long samplerate=44100;
unsigned long chunksize = 256;
int monoStereo = 1;
Square osc1(440,samplerate);
Square osc2(440,samplerate);
Chorus effect(440,samplerate);

bool running = true;
static void audioProcess()
{
  float *inBuffer = new float [chunksize];
  float *outBuffer = new float [chunksize*2];
  float amp = 0.2;
  do{
      jack.readSamples(inBuffer,chunksize);
      for(unsigned int i = 0 ; i<chunksize ; i++)
      {
        outBuffer[2*i] = effect.getEffectSampleL(osc1.getSample())*amp;
        outBuffer[2*i+1] = effect.getEffectSampleR(osc1.getSample())*amp;
        osc1.genNextSample();
        // osc2.genNextSample();
        }
      jack.writeSamples(outBuffer,chunksize*2);
  }while(running);
}


int main(int argc,char **argv)
{
  jack.setNumberOfInputChannels(2);
  jack.setNumberOfOutputChannels(2);
  jack.init(argv[0]);
  jack.autoConnect();
  samplerate=jack.getSamplerate();
  std::cout << "samplerate = " << samplerate << std::endl;
  std::cout << "running \n";
  std::thread audioThread(audioProcess);
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        break;
      case 't':
          effect.setModFreq();
      case 's':
        monoStereo *= -1;
      // case 'd':
      //   effect.setDelayTime();
      case 'w':
        effect.setDryWet();
      case 'b':
        effect.bypass();
    }
  }
  audioThread.join();
  //ending the thread
  return 0;
}
