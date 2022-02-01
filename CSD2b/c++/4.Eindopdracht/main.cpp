#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "writeToFile.h"
#include "FmSynth.h"
/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

//#define WRITE_TO_FILE 0 //WRITE_TO_FILE 1 to make file 


int main(int argc,char **argv)
{

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  FmSynth synth(samplerate,48,0.5);
  synth.setAmp();
  //synth.waveForm();


  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < (samplerate*0.010); i++) {
    fileWriter.write(std::to_string(synth.getSample()) + "\n");
    synth.calculate();
    synth.updatePitch();
  }


  float amplitude = 0.15;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&synth, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = synth.getSample() * amplitude;
      synth.calculate();
      synth.updatePitch();
      //mtof update de freq in de functie 
      //synth.set();
    }

    amplitude = 0.5;
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
      //case 's':
        //synth.set();
    }
  }

  //end the program
  return 0;

} // main()
