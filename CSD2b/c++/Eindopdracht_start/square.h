#include "oscillator.h"

class Square : public Oscillator {
public:
  //Constructor and destructor
  Square(double samplerate,double freq,double amp);
  ~Square();

  void calculate();

private:
  double phase;
  double freq;
  double samplerate;
};

