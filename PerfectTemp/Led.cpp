#include "Arduino.h"
#include "Led.h"

Led::Led(int redLed, int greenLed, int blueLed) {
	_redLed = redLed;
	_greenLed = greenLed;
	_blueLed = blueLed;
}

void Led::changeColor(int redLed, int greenLed, int blueLed) {
	analogWrite(_redLed, redLed);
	analogWrite(_greenLed, greenLed);
	analogWrite(_blueLed, blueLed);
}
