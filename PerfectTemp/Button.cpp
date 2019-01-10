#include "Arduino.h"
#include "Button.h"


Button::Button(int pin) {
	_pin = pin;
	pinMode(_pin, INPUT);
}

bool Button::checkState() {
	_buttonState = digitalRead(_pin);
	return _buttonState;
}
