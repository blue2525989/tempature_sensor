#include "Arduino.h"
#include "led.h"

led::led(int redLed, int greenLed, int blueLed) {
	_redLed = redLed;
	_greenLed = greenLed;
	_blueLed = blueLed;
}

void led::changeColor(int redLed, int greenLed, int blueLed) {
	analogWrite(_redLed, redLed);
	analogWrite(_greenLed, greenLed);
	analogWrite(_blueLed, blueLed);
}
