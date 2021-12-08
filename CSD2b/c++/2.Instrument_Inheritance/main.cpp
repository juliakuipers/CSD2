#include "instrument.h"
#include "synth.h"

int main(){
    Sound make_sound;
    Synth synth_sound(120,"f3");     
    make_sound.play();
    synth_sound.play();
}
//#TODO make both velocity and pitch work 