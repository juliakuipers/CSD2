#include "User_input.h"
#include <algorithm>
#include <iostream>
using namespace std;

user_Input::user_Input(){
    cout 
    << "user_Input Constructor"
    << endl;
}

user_Input::~user_Input(){
    cout
    << "user_Input Destructor"
    << endl;
}

void user_Input::waveForm(){
    string = wave;


  // Remove all double-quote characters
    s.erase(remove( s.begin(), s.end(), '\"' ),s.end()
    );

}
