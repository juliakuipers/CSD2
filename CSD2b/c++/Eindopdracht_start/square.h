#include "oscillator.h"

class Square : public Oscillator {
public:
  //Constructor and destructor
  Square(double samplerate,double freq);
  ~Square();

  void tick();

private:
  double phase;
  double freq;
  double samplerate;
};

