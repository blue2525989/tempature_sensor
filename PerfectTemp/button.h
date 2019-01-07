#ifndef button_h
#define button_h

#include "Arduino.h"
#include "button.h"

class button
{
  public:
  	button(int pin);
  	bool checkState();
  
  private:
  	int _pin;
  	bool _buttonState;
};

#endif
