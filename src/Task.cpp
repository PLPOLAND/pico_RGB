#include "Task.h"

Task::Task()
{

}


Task::~Task()
{

}

Task Task::Rainbow()
{
    Task task;
    task.setRainbow();
    return task;
}

Task Task::Blink()
{
    Task task;
    task.setBlink();
    return task;
}

Task Task::Fade3()
{
    Task task;
    task.setFade3();
    return task;
}

Task Task::Fade7()
{
    Task task;
    task.setFade7();
    return task;
}

Task Task::Jump3()
{
    Task task;
    task.setJump3();
    return task;
}

Task Task::Jump7()
{
    Task task;
    task.setJump7();
    return task;
}

Task Task::DIY1()
{
    Task task;
    task.setDIY1();
    return task;
}

Task Task::DIY2()
{
    Task task;
    task.setDIY2();
    return task;
}

Task Task::DIY3()
{
    Task task;
    task.setDIY3();
    return task;
}

Task Task::DIY4()
{
    Task task;
    task.setDIY4();
    return task;
}

Task Task::DIY5()
{
    Task task;
    task.setDIY5();
    return task;
}

Task Task::DIY6()
{
    Task task;
    task.setDIY6();
    return task;
}

Task Task::ChangeColor(Color color)
{
    Task task;
    task.setChangeColor();
    task.color = color;
    return task;
}

Task Task::Pause()
{
    Task task;
    task.setPause();
    return task;
}

Task Task::Brighter()
{
    Task task;
    task.setBrighter();
    return task;
}

Task Task::Darker()
{
    Task task;
    task.setDarker();
    return task;
}

Task Task::OnOff()
{
    Task task;
    task.setOnOff();
    return task;
}

Task Task::RedUp()
{
    Task task;
    task.setRedUp();
    return task;
}

Task Task::RedDown()
{
    Task task;
    task.setRedDown();
    return task;
}

Task Task::GreenUp()
{
    Task task;
    task.setGreenUp();
    return task;
}

Task Task::GreenDown()
{
    Task task;
    task.setGreenDown();
    return task;
}

Task Task::BlueUp()
{
    Task task;
    task.setBlueUp();
    return task;
}

Task Task::BlueDown()
{
    Task task;
    task.setBlueDown();
    return task;
}

Task Task::Quick()
{
    Task task;
    task.setQuick();
    return task;
}

Task Task::Slow()
{
    Task task;
    task.setSlow();
    return task;
}


void Task::setRainbow(bool doRainbow)
{
    this->clear();
    doRainbow = doRainbow;
}

void Task::setBlink(bool doBlink)
{
    this->clear();
    doBlink = doBlink;
}

void Task::setFade3(bool doFade3)
{
    this->clear();
    doFade3 = doFade3;
}

void Task::setFade7(bool doFade7)
{
    this->clear();
    doFade7 = doFade7;
}

void Task::setJump3(bool doJump3)
{
    this->clear();
    doJump3 = doJump3;
}

void Task::setJump7(bool doJump7)
{
    this->clear();
    doJump7 = doJump7;
}

void Task::setDIY1(bool doDIY1)
{
    this->clear();
    doDIY1 = doDIY1;
}

void Task::setDIY2(bool doDIY2)
{
    this->clear();
    doDIY2 = doDIY2;
}

void Task::setDIY3(bool doDIY3)
{
    this->clear();
    doDIY3 = doDIY3;
}

void Task::setDIY4(bool doDIY4)
{
    this->clear();
    doDIY4 = doDIY4;
}

void Task::setDIY5(bool doDIY5)
{
    this->clear();
    doDIY5 = doDIY5;
}

void Task::setDIY6(bool doDIY6)
{
    this->clear();
    doDIY6 = doDIY6;
}

void Task::setChangeColor(bool doChangeColor)
{
    this->clear();
    doChangeColor = doChangeColor;
}

void Task::setPause(bool doPause)
{
    this->clear();
    doPause = doPause;
}

void Task::setBrighter(bool doBrighter)
{
    this->clear();
    doBrighter = doBrighter;
}

void Task::setDarker(bool doDarker)
{
    this->clear();
    doDarker = doDarker;
}

void Task::setOnOff(bool doOnOff)
{
    this->clear();
    doOnOff = doOnOff;
}

void Task::setRedUp(bool doRedUp)
{
    this->clear();
    doRedUp = doRedUp;
}

void Task::setRedDown(bool doRedDown)
{
    this->clear();
    doRedDown = doRedDown;
}

void Task::setGreenUp(bool doGreenUp)
{
    this->clear();
    doGreenUp = doGreenUp;
}

void Task::setGreenDown(bool doGreenDown)
{
    this->clear();
    doGreenDown = doGreenDown;
}

void Task::setBlueUp(bool doBlueUp)
{
    this->clear();
    doBlueUp = doBlueUp;
}

void Task::setBlueDown(bool doBlueDown)
{
    this->clear();
    doBlueDown = doBlueDown;
}

void Task::setQuick(bool doQuick)
{
    this->clear();
    doQuick = doQuick;
}

void Task::setSlow(bool doSlow)
{
    this->clear();
    doSlow = doSlow;
}

void Task::clear()
{
    doRainbow = false;
    doBlink = false;
    doFade3 = false;
    doFade7 = false;
    doJump3 = false;
    doJump7 = false;
    doDIY1 = false;
    doDIY2 = false;
    doDIY3 = false;
    doChangeColor = false;

    doPause = false;
    doBrighter = false;
    doDarker = false;
    doOnOff = false;

    doRedUp = false;
    doRedDown = false;
    doGreenUp = false;
    doGreenDown = false;
    doBlueUp = false;
    doBlueDown = false;

    doQuick = false;
    doSlow = false;

    color.set(0,0,0,0);
}
