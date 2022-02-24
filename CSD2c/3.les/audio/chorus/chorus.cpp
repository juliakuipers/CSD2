#include "chorus.h"
#include "square.h"

Chorus::Chorus()
{
  std::cout << "Chorus - Constructor \n";
  osc = new Square(440,44100);
}

Chorus::~Chorus()
{
  std::cout << "Chorus - Destructor \n";
  delete osc;
  osc = nullptr;
}
