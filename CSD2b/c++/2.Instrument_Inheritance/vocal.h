#include "instrument.h"

class Vocal : public Sound {
public: 
    Vocal();
    ~Vocal();
    void soprano(); //c4 to a5
    void tenor(); //b2 to c5
    void baritone(); //f2 to f4
};

