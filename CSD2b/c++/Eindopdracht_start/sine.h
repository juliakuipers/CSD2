#include "oscillator.h"

class Sine : public Oscillator{
  public:
    //Constructor and destructor
    Sine();
    ~Sine();

    void tick();

  protected:
    double phase;
};


