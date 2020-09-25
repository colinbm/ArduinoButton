#include <Arduino.h>
#include "Button.h"

Button::Button(int pin) {
  this->pin = pin;
  pinMode(pin, INPUT);
}

bool Button::isDown() {
  unsigned long ts = millis();

  bool downNow = digitalRead(this->pin);

  if (downNow) {
    if (!this->down) {
      this->downAt = ts;
      this->down = true;
    }
    if (millis() - this->downAt > this->threshold) {
      if (repeats || !reported) {
        this->downAt = ts;
        this->reported = true;
        return true;
      }
    }
  } else {
    this->reported = false;
    this->down = false;
  }

  return false;
}