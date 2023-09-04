#include <Arduino.h>
#include <IRremote.h>
#include "IRcode.h"
#include "rgb.h"
#include "ARGBControl.h"
IRcode dioda(2);

rgb RGB;
ARGBControl* argb;

bool mode = true;

void setup()
{
    Serial.begin(9600);
    dioda.init();
    argb = new ARGBControl;
    // argb.rainbowStep();
    Serial.println("STARTED");
}

void loop()
{
    RGB();
    dioda();
    (*argb)();
    IRcode::kodIR got = dioda.get();
    if (got == IRcode::kodIR::DIY4)
    {
        
        if (mode)
        {
            mode = false;
            argb->alarm();
        }
        else{
            mode = true;
            RGB.blink("FF0000");
        }
        
    }

    if (mode)
    {
        RGB.ObslozIR(got);
    }
    else{
        argb->ObslozIR(got);
    }
    // argb->rainbowStep();
}