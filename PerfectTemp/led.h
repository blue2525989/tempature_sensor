#ifndef led_h
#define led_h

#include "Arduino.h"
#include "led.h"

class led
{
  public:
  	led(int redLed, int greenLed, int blueLed);
  	void changeColor(int redLed, int greenLed, int blueLed);

  private:
  	int _redLed;
  	int _greenLed;
  	int _blueLed;
};

#endif
