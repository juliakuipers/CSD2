#include "Tremolo.h"
#include "square.h"
#include "sine.h"

Tremolo::Tremolo(float freq,float samplerate) : Effect(freq,samplerate)
{
  osc = new Sine(freq,samplerate);
}

Tremolo::~Tremolo()
{
  delete osc;
  osc = nullptr;
}

void Tremolo::setModFreq()
{
  float setMFreq;
  while(1){
    std::cout << " Tremolo - setModFreq " << std::endl;
    std::cin >> setMFreq;
    if(std::cin.fail()) std::cin.clear();
    if(!std::cin.fail()) break;
    }
    std::cout << "Tremolo setModFreq break \n" ;
    osc->setFrequency(setMFreq);
    //source https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
}

float Tremolo::calculateM(float sample)
{
  modSig = (osc->genNextSample() + 1.0)*0.5;
  // std::cout << "Tremolo::calculate - modSig = " << modSig << std::endl;
  return sample * modSig;
}
