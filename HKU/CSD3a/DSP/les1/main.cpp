// #include <iostream>
// #include <thread>
// #include "math.h"
// #include "allPassFilter.h"
// #include "writeToFile.h"
// #include "jack_module.h"
// #include "1dFastNoise.h"
//
// #define WRITE_TO_FILE 0
//
// int main(int argc,char **argv)
// {
//   AllPassFilter apf;
//   JackModule jack;
//   WriteToFile fileWriter("output.csv", true);
//   FastNoise noise(44100,440);
//   int input = -1;
//   #if WRITE_TO_FILE
//   for(int i = 0; i < 500; i++) {
//     // input *= -1;
//     fileWriter.write(std::to_string(noise.genNextSample()) + "\n");
//     }
//     //end the program
//   for(int i = 0 ; i < 10 ; i++){
//     // float fir =  apf.kamFilterFIR(input);
//     // float iir = apf.kamFilterIIR(input);
//     // float allPass = apf.kamFilterFIR(apf.kamFilterIIR(input));
//     // float allPass = apf.kamFilterIIR(apf.kamFilterFIR(input));
//     // std::cout << "allPass = " << allPass << '\n';
//   }
//   #else
//   float amplitude = 0.25;
//   //assign a function to the JackModule::onProces
//   jack.onProcess = [&amplitude, &apf, &noise](jack_default_audio_sample_t *inBuf,
//     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
//     for(unsigned int i = 0; i < nframes; i++) {
//       outBuf[i] = apf.kamFilterFIR(noise.genNextSample());
//       // outBuf[i] = synth.getSample() * amplitude;
//       // synth.calculate();
//       // melody.tick();
//     }
//
//     amplitude = 0.25;
//     return 0;
//   };
//
//   jack.autoConnect();
//
//   //keep the program running and listen for user input, q = quit
//   std::cout << "\n\nPress 'q' when you want to quit the program.\n";
//   bool running = true;
//   while (running)
//   {
//     switch (std::cin.get())
//     {
//       case 'q':
//         running = false;
//         jack.end();
//         break;
//     }
//   }
//   //end the program
//   #endif
//   return 0;
// }
//
// #include "1dFastNoise.h"
// #include "juce_audio.h"
// #include <juce_core/juce_core.h>
//
//
// struct Callback : AudioCallback{
//     void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
//     {
// //        for (int channel = 0; channel < numOutputChannels; ++channel) {
//             for (int sample = 0; sample < numSamples; ++sample) {
// //                std::cout << "Sample: " << noise.output() << std::endl;
//                 output[0][sample] = noise.output();
//                 output[1][sample] = noise2.output();
//
//             }
// //        }
//     }
// //    Noise noi{0};
//     FastNoise noise{48000};
//     FastNoise noise2{48000};
//
// };
//
//
//
// int main(int argc, char* argv[]){
//     juce::ignoreUnused(argc, argv);
//
//     Callback callback;
//     AudioBackend audioBackend;
//
//     double Fs = 44100;
//
//     audioBackend.registerCallback(&callback);
//     audioBackend.openDefaultIODevice(2, 2);
//
//     auto running = true;
//     while(running){
//         switch (std::cin.get()){
//             case 'q':
//                 running = false;
//                 break;
//         }
//     }
//
//     audioBackend.closeDevice();
//
//     return 0;
// }

#include <1dFastNoise.h>
#include "juce_audio.h"
#include <juce_core/juce_core.h>
// #include <allPassFilter.h>
#include <fakeStereo.h>

struct Callback : AudioCallback{
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {
//        for (int channel = 0; channel < numOutputChannels; ++channel) {
            for (int sample = 0; sample < numSamples; ++sample) {
                // output[0][sample] = apf.kamFilterIIR(noise.genNextSample());
                // std::cout << "output[0]" << '\n';
                // output[1][sample] = apf2->kamFilterFIR(noise2.genNextSample());
                // output[0][sample] = apf->kamFilterIIR(noise.genNextSample());
                // output[1][sample] = apf2->kamFilterIIR(noise2.genNextSample());
                // output[0][sample] = noise.genNextSample();
                // output[1][sample] = noise2.genNextSample();

            }
//        }
    }
//    Noise noi{0};
    FastNoise noise{440,48000};
    FastNoise noise2{440,48000};
    // AllPassFilter apf;
    // AllPassFilter apf2;

};

int main(int argc, char* argv[]){
    juce::ignoreUnused(argc, argv);

    Callback callback;
    AudioBackend audioBackend;

    double Fs = 44100;
    // AllPassFilter apf;

    // auto Juliapf = AllPassFilter(Fs);
    // auto Julaapf = AllPassFilter(Fs);
    //
    // callback.apf = &Juliapf;
    // callback.apf2 = &Juliaapf;

    audioBackend.registerCallback(&callback);
    audioBackend.openDefaultIODevice(2, 2);

    // for(int i = -3; i < 13; i ++){
    //   int a = 0;
    //   if(i == 0){ a = 1;}
    //   int output  = apf.kamFilterIIR(apf.kamFilterFIR(a));
    //   // std::cout << "main() i =      " << i << '\n';
    //   // std::cout << "main() input =  " << a << '\n';
    //   // std::cout << "main() output = " << output << '\n';
    //   std::cout << "main() :i:input:output" << '\n';
    //   std::cout << "       : " << i << " : " << a <<" : "<< output << '\n';
    // }
    FakeStereo fs(1);



    float input = 0.0f;
    // auto running = true;
    // while(running){
    //     switch (std::cin.get()){
    //         case 'q':
    //             running = false;
    //             break;
    //         // case 'w':
    //         //     std::cout << "Set The stuff: ";
    //         //     input = std::cin();
    //             // Juliapf.setStuff(input);
    //     }
    // }

    audioBackend.closeDevice();

    return 0;
}

// nmfFilter
