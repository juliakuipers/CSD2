#include "instrument.h"

class Vocal{
public: 
    Vocal();
    Vocal(std::string name,std::string pitch)
    ~Vocal();
protected:
    void soprano(); //c4 to a5
    void tenor(); //b2 to c5
    void baritone(); //f2 to f4
private:
    std::string name;
    std::string pitch;
};

