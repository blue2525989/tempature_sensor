#ifndef lm35_h
#define lm35_h

#include "Arduino.h"
#include "lm35.h"

class lm35
{
  public:
  	lm35(int pin);
  	float readTemp();
  	void increase();
  	void decrease();
    float getTemp();
    float getPerfTemp();
    void resetPrefTemp();
    float getTempF();
  
  private:
    int _pin;
  	float _temp;
  	float _prefTemp;
    void setPerfTemp(float newTemp);
};

#endif
