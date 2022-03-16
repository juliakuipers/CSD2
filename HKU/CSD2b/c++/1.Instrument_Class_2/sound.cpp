#include "sound.h"

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
    int x = roll();
    for (int i = 0 ; i < x ; i++){ 
        std::cout << "Beep\n";
    }
}
