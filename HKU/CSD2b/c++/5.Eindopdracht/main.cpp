#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "writeToFile.h"
#include "SimpleSynth.h"
#include "FmSynth.h"
#include "melodyGen.h"
#include "synth.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define WRITE_TO_FILE 1 //WRITE_TO_FILE 1 to make file 
#define SELECT_WAVEFORM 0


int main(int argc,char **argv)
{

  // create a JackModule instance
  JackModule jack;

  #if SELECT_WAVEFORM
    std::string Carrier;
    std::string Modulator;
    while(true){
      std::cout << "input Sine, Saw or Square for Carrier " << std::endl; 
      std::cin >> Carrier;
      if(Carrier == "Sine" || Carrier == "Saw" || Carrier == "Square"){
        break;
      }
    }

    while(true){
      std::cout << "input Sine, Saw or Square for Modulator " << std::endl; 
      std::cin >> Modulator;
      if(Modulator == "Sine" || Modulator == "Saw" || Modulator == "Square"){
        break;
      }
    }
  #else 
    std::string Carrier = "Sine";
    std::string Modulator = "Sine";    
  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  FmSynth synth(samplerate,Carrier,Modulator);
  //in here i specify the synth i wanna use 
  synth.mTof(60);
  MelodyGen melody(samplerate,&synth);

#if WRITE_TO_FILE
  WriteToFile fileWriter("output.csv", true);

  for(int i = 0; i < 500; i++) {
    fileWriter.write(std::to_string(synth.getSample()) + "\n");
    synth.calculate();
  }
#else

  float amplitude = 0.25;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&synth, &amplitude, &melody](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = synth.getSample() * amplitude;
      synth.calculate();
      melody.tick();
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
#endif
#endif
  //end the program
  return 0;

} // main()
