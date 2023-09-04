#include<Arduino.h>
#include<Adafruit_NeoPixel.h>
#include<Timers.h>
#include<IRcode.h>



class ARGBControl
{
private:
    Adafruit_NeoPixel *strip;
    Timer timer;

    bool rainbow = false;

public:
    ARGBControl();
    ~ARGBControl();

    void rainbowStep();
    void off();
    void alarm();
    void setFullColor(int r, int g, int b);
    void setFullColor(char *str);
    void ObslozIR(IRcode::kodIR kod);
    void operator()();
};

