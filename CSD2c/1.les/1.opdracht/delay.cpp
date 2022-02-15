#include "delay.h"

Delay::Delay(float freq, float samplerate) : Effect(freq,samplerate), size(samplerate*5), numSamplesDelay(samplerate)
{
  circ = new CircularBuffer(size,numSamplesDelay);
  std::cout << "Delay - Constructor \n";
}

Delay::~Delay()
{
  std::cout << "Delay - Destructor \n";
  delete circ;
  circ = nullptr;

}

float Delay::calculate(float sample)
{

  // std::cout << "Delay - calculate - sample " << sample << "\n";
  // circ.setReadIndex();
  circ->write(sample);
  float samp = circ->read();
  // std::cout << "Delay - calculate - samp "<< samp<<"\n";

  // ding();
  return samp;
}

void Delay::ding()
{
  circ->setReadIndex();
}
// 
// void Delay::drywet()
// {
//   float drywet = Effect::drywet();
//   std::cout << "hjfidsa;\n";
// }
