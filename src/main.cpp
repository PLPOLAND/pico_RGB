#include <Arduino.h>
#include <IRremote.hpp>
#include "IRDiode.h"

IRDiode* ir; // IR diode on pin 5
void setup() {
  Serial.begin(115200);
  ir = new IRDiode(5);
}

void loop() {
  (*ir)();
  // Serial.println("loop");
}