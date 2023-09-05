#include <Arduino.h>
#include <IRremote.hpp>
#include "IRDiode.hpp"
// #include "IRcode.h"
// #include "rgb.h"
// IRcode dioda(5);

// rgb RGB;

// bool mode = true;

// void setup()
// {
//     Serial.begin(9600);
//     dioda.init();
//     // argb.rainbowStep();
//     Serial.println("STARTED");
// }

// void loop()
// {
//     RGB();
//     dioda();
//     IRcode::kodIR got = dioda.get();
//     if (got == IRcode::kodIR::DIY4)
//     {
        
        
//             mode = true;
//             RGB.blink("FF0000");
        
//     }

//         RGB.ObslozIR(got);
//     // argb->rainbowStep();
// }
IRDiode ir(5); // IR diode on pin 5
void setup() {
  Serial.begin(115200);
  
}

void loop() {
  ir();
  Serial.println("loop");
}