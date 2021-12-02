#include "instrument.h"

Sound::Sound(){
    std::cout << "Constructor called\n";
}

Sound::~Sound(){
    std::cout << "Destructor called\n";
}

int Sound::pitch(){
    std::cout << "pick a note (f2-a5)\n";
}

int Sound::velocity(){
    std::cout << "velocity of instrument 0/127\n";
}

int Sound::roll(){
    int x;
    std::cout << "number of repetitions\n";
    std::cin >> x ;
    return x; 
}

void Sound::play(){
    int x;
    std::cout << "What type of instrument? (Vocal/Synth)\n";
    std::cin >> x;
    int y = roll();
    for (int i = 0 ; i < y ; i++){ 
        std::cout << "Beep\n";
    }
}

