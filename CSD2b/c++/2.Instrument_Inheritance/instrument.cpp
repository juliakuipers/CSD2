#include "instrument.h"

Sound::Sound(){
    std::cout << "Constructor called\n";
}

Sound::~Sound(){
    std::cout << "Destructor called\n";
}

int Sound::roll(){
    int x;
    std::cout << "number of repetitions\n";
    std::cin >> x ;
    return x; 
}

void Sound::play(){
    int y = roll();
    for (int i = 0 ; i < y ; i++){ 
        std::cout << "Beep\n";
    }
}

//vanaf synth moet ik de waardes na instrument sturen, niet vanaf instrument na synth 