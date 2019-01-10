#ifndef led_h
#define led_h

#include "Arduino.h"
#include "Led.h"

class Led
{
  public:
	Led(int redLed, int greenLed, int blueLed);
  	void changeColor(int redLed, int greenLed, int blueLed);

  private:
  	int _redLed;
  	int _greenLed;
  	int _blueLed;
};

#endif
