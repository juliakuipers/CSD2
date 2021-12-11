#include "instrument.h"
#include "synth.h"

int main(){
    // Sound make_sound;
    std::cout << "main\n";
    Synth synth_sound; 
    std::cout
    << "velocity "
    << synth_sound.getVel()
    << "\n"
    << "pitch "
    << synth_sound.getPitch()
    << "\n";
    // make_sound.play();
    
}
//#TODO make both velocity and pitch work 