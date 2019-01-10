#ifndef lm35_h
#define lm35_h

#include "Arduino.h"
#include "Lm35.h"

class Lm35
{
  public:
	Lm35(int pin);
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
