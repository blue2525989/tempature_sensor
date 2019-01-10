#include "Button.h"
#include "Led.h"
#include "Lm35.h"

int main ()
  {
    // init internal timers on board
    init ();
    Serial.begin(9600);
    
    // lm35 sensor
    Lm35* lm = new Lm35(A0);
    
    // led
    Led* l = new Led(9, 10, 11);
    
    // warmer button
    Button* warmerButton = new Button(3);
    // perfect temp button
    Button* perfButton = new Button(5);
    // cooler button
    Button* coolerButton = new Button(6);
    
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

void checkCurrentState(Button* warmerButton, Button* perfButton, Button* coolerButton, Lm35* lm35) {
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

void checkCurrentTemp(float current, float perfect, Led* led) {
  float perfectMinus = perfect - 1.5;
  float perfectIncrease = perfect + 1.5;
  //todo come up with a utility function to make wider range of colors based upon difference from prefTemp
  if (current > perfectMinus || current > perfectIncrease) {
    led->changeColor(50, 0, 0);
  } else if (current < perfectMinus || current < perfectIncrease) {
    led->changeColor(0, 0, 50);
  } else {
    led->changeColor(0, 50, 0);
  }
  delay(1000);
}
