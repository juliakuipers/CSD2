#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "writeToFile.h"
#include "sine.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define WRITE_TO_FILE 1 //writes plot.py


int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  Oscillator osc(220.0,samplerate);
  Sine sine;
  sine.setFreq(220.0);
  sine.setAmp(0.5);
  //Square square(660,samplerate);

  #if WRITE_TO_FILE
    WriteToFile fileWriter("output.csv", true);

    for(int i = 0; i < 500; i++) {
      fileWriter.write(std::to_string(sine.getSample()) + "\n");
      sine.tick(); // writes the square 
  } 

  float amp = 0.15;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&sine, &amp ](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = sine.getSample() * amp;
      sine.tick();
    }
    amp = 0.5;
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
#endif
  //end the program
  return 0;
} // main()
