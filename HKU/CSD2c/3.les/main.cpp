#include <iostream>
#include <thread>
#include <unistd.h>
#include "jack_moduleStereo.h"
#include "square.h"
#include "sine.h"
#include "chorus.h"
#include "waveshaper.h"
#include "Tremolo.h"
#include "writeToFile.h"


JackModule jack;
unsigned long samplerate=44100;
unsigned long chunksize = 256;
int monoStereo = 1;
Sine osc1(440,samplerate);
Sine osc2(440,samplerate);
Waveshaper effect(440,samplerate);

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
        outBuffer[2*i] = effect.getEffectSampleM(osc1.getSample())*amp;
        outBuffer[2*i+1] = effect.getEffectSampleM(osc1.getSample())*amp;
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
bool write = true;
if(write == true){
  WriteToFile writeFile("outpus.csv",true);
    for(int i = 0; i < 500; i++) {
      writeFile.write(std::to_string(effect.getEffectSampleM(osc1.getSample())) + "\n");
      osc1.genNextSample();
    }
  }
else {
    std::thread audioThread(audioProcess);

    while (running)
    {
      switch (std::cin.get())
      {
        case 'q':
          running = false;
          break;
          // case 't':
          //     effect.setModFreq();
          case 's':
          monoStereo *= -1;
          // case 'd':
          //   effect.setDelayTime();
          case 'w':
          effect.setDryWet();
          case 'b':
          effect.bypass();
          case 'c':
          effect.setCurve(3);
        }
      }
      audioThread.join();
      //ending the thread
      return 0;
    }
}
