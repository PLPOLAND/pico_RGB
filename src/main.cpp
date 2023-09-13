#include <Arduino.h>
#include <IRremote.hpp>
#include "IRControl.h"
#include "Task.h"
#include "RGBController.h"

void IRControlCodetoString(IRControlCode code)
{
  switch (code)
  {
  case IRControlCode::NIC:
    Serial.println("NIC");
    break;
  case IRControlCode::POWTORZ:
    Serial.println("POWTORZ");
    break;
  case IRControlCode::JASNIEJ:
    Serial.println("JASNIEJ");
    break;
  case IRControlCode::CIEMNIEJ:
    Serial.println("CIEMNIEJ");
    break;
  case IRControlCode::PAUZA_PLAY:
    Serial.println("PAUZA_PLAY");
    break;
  case IRControlCode::WYL:
    Serial.println("WYL");
    break;
  case IRControlCode::R:
    Serial.println("R");
    break;
  case IRControlCode::G:
    Serial.println("G");
    break;
  case IRControlCode::B:
    Serial.println("B");
    break;

  case IRControlCode::W:
    Serial.println("W");
    break;  
  case IRControlCode::C1:
    Serial.println("C1");
    break;
  case IRControlCode::C2:
    Serial.println("C2");
    break;
  case IRControlCode::C3:
    Serial.println("C3");
    break;
  case IRControlCode::C4: 
    Serial.println("C4");
    break;
  case IRControlCode::C5:
    Serial.println("C5");
    break;
  case IRControlCode::C6:
    Serial.println("C6");
    break;
  case IRControlCode::C7:
    Serial.println("C7");
    break;
  case IRControlCode::C8:
    Serial.println("C8");
    break;  
  case IRControlCode::C9:
    Serial.println("C9");
    break;
  case IRControlCode::C10:
    Serial.println("C10");
    break;
  case IRControlCode::C11:
    Serial.println("C11");
    break;
  case IRControlCode::C12:
    Serial.println("C12");
    break;
  case IRControlCode::C13:
    Serial.println("C13");
    break;
  case IRControlCode::C14:
    Serial.println("C14");
    break;
  case IRControlCode::C15:
    Serial.println("C15");
    break;
  case IRControlCode::C16:
    Serial.println("C16");
    break;
  case IRControlCode::RPLUS:
    Serial.println("RPLUS");
    break;
  case IRControlCode::GPLUS:
    Serial.println("GPLUS");
    break;
  case IRControlCode::BPLUS:
    Serial.println("BPLUS");
    break;
  case IRControlCode::QUICK:
    Serial.println("QUICK");
    break;
  case IRControlCode::RMINUS:
    Serial.println("RMINUS");
    break;
  case IRControlCode::GMINUS:
    Serial.println("GMINUS");
    break;
  case IRControlCode::BMINUS:
    Serial.println("BMINUS");
    break;
  case IRControlCode::SLOW:
    Serial.println("SLOW");
    break;
  case IRControlCode::DIY1: 
    Serial.println("DIY1");
    break;
  case IRControlCode::DIY2:
    Serial.println("DIY2");
    break;
  case IRControlCode::DIY3:
    Serial.println("DIY3");
    break;
  case IRControlCode::AUTO:
    Serial.println("AUTO");
    break;
  case IRControlCode::DIY4:
    Serial.println("DIY4");
    break;
  case IRControlCode::DIY5:
    Serial.println("DIY5");
    break;
  case IRControlCode::DIY6:
    Serial.println("DIY6");
    break;
  case IRControlCode::FLASH:
    Serial.println("FLASH");
    break;
  case IRControlCode::JUMP3:
    Serial.println("JUMP3");
    break;
  case IRControlCode::JUMP7:
    Serial.println("JUMP7");
    break;
  case IRControlCode::FADE3:
    Serial.println("FADE3");
    break;
  case IRControlCode::FADE7:
    Serial.println("FADE7");
    break;
  default:
    break;
  }
}


IRControl* ir; // IR diode on pin 5
RGBController* rgb;

void setup() {
  Serial.begin(115200);
  ir = new IRControl(5);
  rgb = new RGBController(0, 1, 2);
}

void loop() {
  Task* task = ir->tick();
  if (task != nullptr)
  {
    Serial.println(task->toString().c_str());
    rgb->setTask(task);
  }
  rgb->tick();
}