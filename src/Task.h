#ifndef TASK_H
#define TASK_H

#pragma once
#include "Color.h"

class Task
{
public:
    ~Task();
    static Task Rainbow();
    static Task Blink();
    static Task Fade3();
    static Task Fade7();
    static Task Jump3();
    static Task Jump7();
    static Task DIY1();
    static Task DIY2();
    static Task DIY3();
    static Task DIY4();
    static Task DIY5();
    static Task DIY6();
    static Task ChangeColor(Color color);
    
    static Task Pause();
    static Task Brighter();
    static Task Darker();
    static Task OnOff();

    static Task RedUp();
    static Task RedDown();
    static Task GreenUp();
    static Task GreenDown();
    static Task BlueUp();
    static Task BlueDown();

    static Task Quick();
    static Task Slow();

protected:
    Task();
    void setRainbow(bool doRainbow = true);
    void setBlink(bool doBlink = true);
    void setFade3(bool doFade3 = true);
    void setFade7(bool doFade7 = true);
    void setJump3(bool doJump3 = true);
    void setJump7(bool doJump7 = true);
    void setDIY1(bool doDIY1 = true);
    void setDIY2(bool doDIY2 = true);
    void setDIY3(bool doDIY3 = true);
    void setDIY4(bool doDIY4 = true);
    void setDIY5(bool doDIY5 = true);
    void setDIY6(bool doDIY6 = true);
    void setChangeColor(bool doChangeColor = true);
    
    void setPause(bool doPause = true);
    void setBrighter(bool doBrighter = true);
    void setDarker(bool doDarker = true);
    void setOnOff(bool doOnOff = true);

    void setRedUp(bool doRedUp = true);
    void setRedDown(bool doRedDown = true);
    void setGreenUp(bool doGreenUp = true);
    void setGreenDown(bool doGreenDown = true);
    void setBlueUp(bool doBlueUp = true);
    void setBlueDown(bool doBlueDown = true);

    void setQuick(bool doQuick = true);
    void setSlow(bool doSlow = true);
    void clear();

private:
    bool doRainbow = false;
    bool doBlink = false;
    bool doFade3 = false;
    bool doFade7 = false;
    bool doJump3 = false;
    bool doJump7 = false;
    bool doDIY1 = false;
    bool doDIY2 = false;
    bool doDIY3 = false;
    bool doDIY4 = false;
    bool doDIY5 = false;
    bool doDIY6 = false;
    bool doChangeColor = false;
    
    bool doPause = false;
    bool doBrighter = false;
    bool doDarker = false;
    bool doOnOff = false;

    bool doRedUp = false;
    bool doRedDown = false;
    bool doGreenUp = false;
    bool doGreenDown = false;
    bool doBlueUp = false;
    bool doBlueDown = false;

    bool doQuick = false;
    bool doSlow = false;

    Color color;//for changing color
};

#endif