#include "button.h"
#include "led.h"
#include "lm35.h"

int main ()
  {
    // init internal timers on board
    init ();
    Serial.begin(9600);
    
    // lm35 sensor
    lm35* lm = new lm35(A0);
    
    // led
    led* l = new led(9, 10, 11);
    
    // warmer button
    button* warmerButton = new button(3);   
    // perfect temp button
    button* perfButton = new button(5);
    // cooler button
    button* coolerButton = new button(6);
    
    // start with green to show successful turn on
    l->changeColor(0, 5, 0);

    while (true) {
      lm->readTemp();
      float farh = lm->getTempF();
      checkCurrentState(warmerButton, perfButton, coolerButton, lm);
      checkCurrentTemp(farh, lm->getPerfTemp(), l);
      Serial.println(farh);
    }
  } 

void checkCurrentState(button* warmerButton, button* perfButton, button* coolerButton, lm35* lm35) {
   if (warmerButton->checkState() == HIGH) {
    lm35->increase();
    Serial.println(lm35->getPerfTemp());
   } else if (perfButton->checkState() == HIGH) {
    lm35->resetPrefTemp();
    Serial.println(lm35->getPerfTemp());
   } else if (coolerButton->checkState() == HIGH) {
    lm35->decrease();
    Serial.println(lm35->getPerfTemp());
   }
}

void checkCurrentTemp(float current, float perfect, led* led) {
  //todo come up with a utility function to make wider range of colors based upon difference from prefTemp
  if (current > perfect) {
    led->changeColor(50, 0, 0);
  } else if (current < perfect) {
    led->changeColor(0, 0, 50);
  } else {
    led->changeColor(0, 50, 0);
  }
  delay(1000);
}
