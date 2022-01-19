#include "synth.h"
#include "oscillator.h"
#include <iostream>

class Sine : public Synth, public Oscillator {
  public:
  //Constructor and destructor
    Sine();
    ~Sine();

    void calculate();

  private:
    double phase;
};

#endif
