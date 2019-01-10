#ifndef button_h
#define button_h

#include "Arduino.h"
#include "Button.h"

class Button
{
  public:
  	Button(int pin);
  	bool checkState();
    void setStateHigh();
    void setStateLow();
  private:
  	int _pin;
  	bool _buttonState;
};

#endif
