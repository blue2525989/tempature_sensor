#include "Arduino.h"
#include "button.h"


button::button(int pin) {
	_pin = pin;
	pinMode(_pin, INPUT);
}

bool button::checkState() {
	_buttonState = digitalRead(_pin);
	return _buttonState;
}
