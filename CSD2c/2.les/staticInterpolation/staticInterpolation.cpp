#include "staticInterpolation.h"

StaticInterpolation::StaticInterpolation()
{

}

StaticInterpolation::~StaticInterpolation()
{

}

float StaticInterpolation::nnMap(float value, float low, float high)
{
  if(value > 0.5) value = high;
  else value = low;
  std::cout << value << std::endl;
  return value;
}
//given two values low and high and also a value value between 0,1
//if the low is 3 and the high is 5 and the value is 0.5
//the point which the function should return is then 4 since its between 3 and 5

float StaticInterpolation::linMap(float value, float low, float high)
{

}
