#include "Arduino.h"
#include "Lm35.h"

Lm35::Lm35(int pin) {
  _pin = pin;
	_prefTemp = 72;
	pinMode(_pin, INPUT);
}

float Lm35::readTemp() {
  _temp = analogRead(_pin);
  return _temp;
}

void Lm35::setPerfTemp(float newTemp) {
	_prefTemp = newTemp;
}

float Lm35::getTemp() {
  return _temp;
}

float Lm35::getPerfTemp() {
  return _prefTemp;
}

void Lm35::increase() {
  _prefTemp += 1;
}

void Lm35::decrease() {
  _prefTemp -= 1;
}

void Lm35::resetPrefTemp() {
  _prefTemp = 72;
}

float Lm35::getTempF() {
   readTemp();
   float val = getTemp();
   float cel = (5.0 * val * 100.0)/1024.0;
   float farh = ((cel*9)/5) + 32;
   return farh;
}
