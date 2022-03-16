#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "writeToFile.h"
#include "square.h"
#include "melodyGen.h"
#include "Tremolo.h"
#include "Delay.h"
/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define WRITE_TO_FILE 0 //WRITE_TO_FILE 1 to make file


int main(int argc,char **argv)
{

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  Square osc(440, samplerate);
  MelodyGen mel(samplerate);
  // Tremolo tremolo(27.5,samplerate);
  Delay effect(440,samplerate);
  // effect.setDryWet();
  // effect.setFeedback();
  //so for the effects to work i can make it return a true

#if WRITE_TO_FILE
  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < 500; i++) {
    fileWriter.write(std::to_string(effect.getEffectSample(osc.getSample())) + "\n");
    osc.genNextSample();

  }
#else



  float amplitude = 0.15;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&osc, &mel, &effect, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    //
    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = effect.getEffectSample(osc.getSample()) * amplitude;
      osc.genNextSample();
      osc.setFrequency(mel.melody());
    }

    // for(unsigned int sample = 0; sample < nframes; sample++){
    //   outBuf[sample] = inBuf[sample];
    // }

    amplitude = 0.5;
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
      // case 't':
      //     effect.setModFreq();
      case 'd':
        effect.setDelayTime();
      case 'w':
        effect.setDryWet();
      case 'b':
        effect.bypass();
    }
  }
#endif
  //end the program
  return 0;

} // main()
