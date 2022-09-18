#include <iostream>
#include <thread>
#include "math.h"
#include "allPassFilter.h"
#include "writeToFile.h"
#include "jack_module.h"
#include "1dFastNoise.h"

#define WRITE_TO_FILE 0

int main(int argc,char **argv)
{
  AllPassFilter apf;
  JackModule jack;
  WriteToFile fileWriter("output.csv", true);
  FastNoise noise(44100,440);
  int input = -1;
  #if WRITE_TO_FILE
  for(int i = 0; i < 500; i++) {
    // input *= -1;
    fileWriter.write(std::to_string(noise.genNextSample()) + "\n");
    }
    //end the program
  for(int i = 0 ; i < 10 ; i++){
    // float fir =  apf.kamFilterFIR(input);
    // float iir = apf.kamFilterIIR(input);
    // float allPass = apf.kamFilterFIR(apf.kamFilterIIR(input));
    // float allPass = apf.kamFilterIIR(apf.kamFilterFIR(input));
    // std::cout << "allPass = " << allPass << '\n';
  }
  #else
  float amplitude = 0.25;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&amplitude, &apf, &noise](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = apf.kamFilterFIR(noise.genNextSample());
      // outBuf[i] = synth.getSample() * amplitude;
      // synth.calculate();
      // melody.tick();
    }

    amplitude = 0.25;
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }
  //end the program
  #endif
  return 0;
}
