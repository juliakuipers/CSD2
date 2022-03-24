#include <iostream>
#include <thread>
#include <unistd.h>
#include "jack_moduleStereo.h"
#include "square.h"
#include "sine.h"
#include "saw.h"
#include "chorus.h"
#include "waveshaper.h"
#include "Tremolo.h"
#include "writeToFile.h"
// #include "pickSample.h"


JackModule jack;
unsigned long samplerate=44100;
unsigned long chunksize = 256;
int monoStereo = 1;
Sine osc1(440,samplerate);
Sine osc2(440,samplerate);
Tremolo effect(440,samplerate);

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
        outBuffer[2*i] = effect.getEffectSampleM(inBuffer[i]*amp);
        outBuffer[2*i+1] = effect.getEffectSampleM(inBuffer[i]*amp);
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
bool write = false;
if(write == true){
  WriteToFile writeFile("output.csv",true);
    for(int i = 0; i < 500; i++) {
      float s  = effect.getEffectSampleM(osc1.getSample());
      writeFile.write(std::to_string(s) + "\n");
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
          // break;
          case 's':
          monoStereo *= -1;
          break;
          // case 'd':
          //   effect.setDelayTime();
          // break;
          case 'w':
          effect.setDryWet();
          break;
          case 'b':
          effect.bypass();
          break;
          // case 'c':
          // effect.setCurve(3);
          // break;
        }
      }
      audioThread.join();
      //ending the thread
      return 0;
    }
}
