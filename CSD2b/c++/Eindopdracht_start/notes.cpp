/*
& references an object 
unsigned int can only store positive integers 
a base class is a literal base with all basic properties
it cannot inherit properties from it's derived class 
a derived class (sinus,square), inherits these properties and also has its own properties
derived classes usually have more functionality 

class BaseClass{
  // members....
  // member function 
}
     
class DerivedClass : public BaseClass{
  // members....
  // member function 
}

i think the only function that belongs to the waveform is the calculation the other ones are part of the oscillator 

pointer:
var = 25; assign a value to a name 
foo = &var; assign foo to the adress of var, an adress stored in memory 
bar = var; store the integer value in bar 
baz = *foo;(pointer) points to whatever is stored in that specific place in memory, without differentiating between int, float, string ect