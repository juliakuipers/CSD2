#include <iostream>
#include <thread>
#include <unistd.h>
#include "jack_moduleStereo.h"
// #include "noiseGen.h"
#include "fastNoise.h"
#include "writeToFile.h"

// int main(){
//   // NoiseGen noise1(440,100);
//   // noise1.genNextSample();
//   FastNoise noise1(44,100);
//   noise1.genNextSample();
//   return 0;
// }

JackModule jack;
unsigned long samplerate=44100;
unsigned long chunksize = 256;
int monoStereo = 1;
FastNoise noise1(440,samplerate);

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
        // outBuffer[2*i] = noise1.getSample(inBuffer[i]*amp);
        // outBuffer[2*i+1] = noise1.getSample(inBuffer[i]*amp);
        outBuffer[2*i] = noise1.getSample();
        outBuffer[2*i+1] = noise1.getSample();
        noise1.genNextSample();
        }
      jack.writeSamples(outBuffer,chunksize*2);
  }while(running);
}
//om goeie stereo te maken werken met x en y

int main(int argc,char **argv)
{
  jack.setNumberOfInputChannels(1);
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
      float s  = noise1.getSample();
      writeFile.write(std::to_string(s) + "\n");
      noise1.genNextSample();
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
          case 's':
          monoStereo *= -1;
          break;
        }
      }
      audioThread.join();
      //ending the thread
      return 0;
    }
}
