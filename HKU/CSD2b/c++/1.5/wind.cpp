#include "wind.h"

Wind::Wind(){
    std::cout << "Constructor called\n";
}

Wind::~Wind(){
    std::cout << "Destructor called\n";
}

void Wind::blow(){
    std::cout << "wind\n";
}
