#include "vocal.h"

Vocal::Vocal(std::string name) : Sound(name){
    std::cout << "Constructor Vocal\n"
}

Vocal::~Vocal(){
    std::cout << "Destructor Vocal\n"
}

void Vocal::sing(){
    std::cout << "Vocal is singing\n"
}

void Vocal::rap(){
    std::cout << "Vocal is rapping\n"
}

void Vocal::scream(){
    std::cout << "Vocal is screaming\n"
}

// class Vocal : public Sound {
// public: 
//     Vocal();
//     ~Vocal();
//     void sing();
//     void rap();
//     void scream();
// };

