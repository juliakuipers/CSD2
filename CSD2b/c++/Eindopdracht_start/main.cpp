#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "writeToFile.h"
#include "sine.h"
#include "square.h"
//#include "fm.h"
//#include "user_input.h"

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
  //#TODO work with user input for waveforms 

  double freq = 440.0;
  double ampl = 0.5;
  std::string waveForm;
  std::cout 
  << "input sine or square"
  <<std::endl;
  std::cin >> waveForm;
  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  //Oscillator osc(samplerate);
  Sine sine(samplerate,freq,ampl);
  sine.setFreq(220);
  sine.setAmp(0.5);
  //todo setters do not work 

  Square square(samplerate,freq,ampl);
  // square.setFreq(freq);
  square.setAmp(0.5);
  //nothing goes wrong with setters and getters, maybe in the calculation 
  #if WRITE_TO_FILE
    WriteToFile fileWriter("output.csv", true);

    for(int i = 0; i < 500; i++) {
      fileWriter.write(std::to_string(sine.getSample()) + "\n");
      //                              i can put the fm fuction in here to see the waveform 

      sine.calculate(); 
  } 
  //maybe i can put generating of the waveform 
  double amp = 0.15;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&sine, &amp ](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++) {
      //nframes 
      outBuf[i] = sine.getSample() * amp;
      sine.calculate();
      //calculation of the waveform is in this for loop so its happening continiously 
      //berekening van golfvorm kan zonder audio in een subclass voor fm. dan de freq * de berekening voor frequency modulation. en dan in main zorg je alleen voor het afspelen van de audio 
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
      case 's':
        sine.setFreq(440);
        std::cout << "s\n";
    }
  }
#endif
  //end the program
  return 0;
} // main()
