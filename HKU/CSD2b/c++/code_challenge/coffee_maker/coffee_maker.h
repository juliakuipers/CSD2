#include <iostream>

class CoffeeMaker {
    public:
    // iwantcoffee
    CoffeeMaker(); 
    // for my needs are satisfied 
    ~CoffeeMaker(); 
    // int add_water (to machine) (amount of coffee cups)
    int add_water();  
    // int coffee (how strong 1/3) 
    int coffee(); 
    // grinder -> add coffee
    void grinder(); 
    // add_filter to coffee machine
    void add_filter(); 
    // water = cooking
    bool cooking_water(); 
    // coffee = brewing
    bool coffee_brewing(); 
    // coffee = done
    void done(); 
};