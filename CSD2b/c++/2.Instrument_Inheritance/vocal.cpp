#include "vocal.h"

Vocal::Vocal(std::string name) : Sound(name){
    std::cout << "Constructor Vocal\n";
}

Vocal::~Vocal(){
    std::cout << "Destructor Vocal\n";
}

void Vocal::soprano(){
    std::cout << "soprano is singing at velocity =";
    << velocity
    << "and the pitch is"
    << pitch 
    << "\n";
}

void Vocal::tenor(){
    std::cout << "tenor is singing at velocity =";
    << velocity
    << "and the pitch is"
    << pitch 
    << "\n";
}
}

void Vocal::baritone(){
    std::cout << "soprano is singing at velocity =";
    << velocity
    << "and the pitch is"
    << pitch 
    << "\n";
}
}


