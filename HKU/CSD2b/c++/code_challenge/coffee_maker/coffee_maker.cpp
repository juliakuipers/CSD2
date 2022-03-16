#include "coffee_maker.h"
#include <stdlib.h>  

CoffeeMaker::CoffeeMaker(){
    std::cout << "i want coffee\n";
}

CoffeeMaker::~CoffeeMaker(){
    std::cout << "for my needs are satisfied\n";
}

int CoffeeMaker::add_water(){
    int x;
    std::cout << "how many cups of coffee?\n";
    std::cin >> x;
    return x;
}

int CoffeeMaker::coffee(){
    int x;
    std::cout << "how strong? (1/inf)\n";
    std::cin >> x;
    return x;
}

void CoffeeMaker::grinder(){
    int x = coffee();
    for (int i = 0; i < x ; i ++){
        std::cout << "adding one spoon of coffee to grinder (" << i + 1 << "/" << x << ") \n";
        //sleep(3000);
    }
}

void CoffeeMaker::add_filter(){
    std::cout << "adding filter\n";
}

bool CoffeeMaker::cooking_water(){
    if (add_filter() == true){
        return true;
    }
}

bool CoffeeMaker::coffee_brewing(){
    if(cooking_water() == true){
        return true;
    }
}

void CoffeeMaker::done(){
    if(coffee_brewing() == true){
        std::cout << "done\n";
    } 
}