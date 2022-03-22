#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

int main()
{
  int numSamples = 20;
  vector<float> v;
  float floatCount = -1.0;
  vector<float> averageNumber;
  float currentSample = -1;
  int size = 0;
  // for (int i = 0; i < numSamples; i++)
  // {
  //   if(i !=5){v.push_back(i);}
  // }
  // for (auto i = v.begin(); i != v.end(); ++i)
  // {
  //   cout << *i << "\n ";
  // }
  while(true)
  {
    for(int l = 0; l < numSamples; l++)
    {
      currentSample += 0.009;
      if(currentSample > floatCount || currentSample < floatCount-0.1){
        cout << "currentSample is within range  [floatCount + 0.1, floatCount]  = [" << floatCount+0.1 << ", " << floatCount << "]" << endl;
        cout << "currentSample is at number = " << currentSample << endl;
        v.push_back(currentSample);
      }
    }
    float sum  = accumulate(v.begin(),v.end(),0.0f);
    float average = sum/v.size();
    cout << "v.size(), sum, average = " << v.size() << ", " << sum << ", " << average << endl;
    averageNumber.push_back(average);
    v.clear();
    cout << "v is empty = " << v.empty() << endl;
    floatCount += 0.1;
    size = averageNumber.size();
    if(floatCount >= 1){break;}
  }
  for(int i = 0; i < size; i++)
  {
    cout << "vector averageNumber index " << i << " = " << averageNumber[i] << endl;
  }
}
