#include <iostream>

class Sound {
public: 
    Sound();
    ~Sound();
    void play();
    int roll;

};

Sound::Sound(){
    std::cout << "Constructor called\n";
    roll = 4;
}

Sound::~Sound(){
    std::cout << "Destructor called\n";
}

void Sound::play(){
    for (int i = 0 ; i < 4 ; i++){ 
        std::cout << "Beep\n";
    }
}

int main(){
    Sound make_sound;     
    make_sound.play();
}
