#include "Arduino.h"
#include "lm35.h"

lm35::lm35(int pin) {
  _pin = pin;
	_prefTemp = 72;
	pinMode(_pin, INPUT);
}

float lm35::readTemp() {
	// todo read the temp!
  _temp = analogRead(_pin);
  return _temp;
}

void lm35::setPerfTemp(float newTemp) {
	_prefTemp = newTemp;
}

float lm35::getTemp() {
  return _temp;
}

float lm35::getPerfTemp() {
  return _prefTemp;
}

void lm35::increase() {
  _prefTemp += 1;
}

void lm35::decrease() {
  _prefTemp -= 1;
}

void lm35::resetPrefTemp() {
  _prefTemp = 72;
}

float lm35::getTempF() {
   readTemp();
   float val = getTemp();
   float cel = (5.0 * val * 100.0)/1024.0;
   float farh = ((cel*9)/5) + 32;
   return farh;
}
