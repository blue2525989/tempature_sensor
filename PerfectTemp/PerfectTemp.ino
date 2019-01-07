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
      checkCurrentState(warmerButton, perfButton, coolerButton, lm, l);
    }
  } 

void checkCurrentState(button* warmerButton, button* perfButton, button* coolerButton, lm35* lm35, led* led) {
   if (warmerButton->checkState() == HIGH) {
    lm35->increase();
   } else if (perfButton->checkState() == HIGH) {
    lm35->resetPrefTemp();
   } else if (coolerButton->checkState() == HIGH) {
    lm35->decrease();
   }


   lm35->readTemp();
   float val = lm35->getTemp();
   float cel = (5.0 * val * 100.0)/1024.0;
   float farh = ((cel*9)/5) + 32;
   Serial.println(farh);
   
   checkCurrentTemp(farh, lm35->getPerfTemp(), led);
   delay(250);
}

void checkCurrentTemp(float current, float perfect, led* led) {
  if (current > perfect) {
    led->changeColor(50, 0, 0);
  } else if (current < perfect) {
    led->changeColor(0, 0, 50);
  } else {
    led->changeColor(0, 50, 0);
  }
}
