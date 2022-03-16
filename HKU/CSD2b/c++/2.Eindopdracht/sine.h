#include "oscillator.h"

class Sine : public Oscillator {
  public:
  //Constructor and destructor
    Sine();
    ~Sine();

    void calculate();
    double getSample();

  private:
    double phase;
    double sample;
};

