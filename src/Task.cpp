#include "Task.h"

Task::Task()
{

}


Task::~Task()
{

}

Task* Task::Rainbow()
{
    Task* task=new Task;
    task->setRainbow();
    return task;
}

Task* Task::Blink()
{
    Task* task=new Task;
    task->setBlink();
    return task;
}

Task* Task::Fade3()
{
    Task* task=new Task;
    task->setFade3();
    return task;
}

Task* Task::Fade7()
{
    Task* task=new Task;
    task->setFade7();
    return task;
}

Task* Task::Jump3()
{
    Task* task=new Task;
    task->setJump3();
    return task;
}

Task* Task::Jump7()
{
    Task* task=new Task;
    task->setJump7();
    return task;
}

Task* Task::DIY1()
{
    Task* task=new Task;
    task->setDIY1();
    return task;
}

Task* Task::DIY2()
{
    Task* task=new Task;
    task->setDIY2();
    return task;
}

Task* Task::DIY3()
{
    Task* task=new Task;
    task->setDIY3();
    return task;
}

Task* Task::DIY4()
{
    Task* task=new Task;
    task->setDIY4();
    return task;
}

Task* Task::DIY5()
{
    Task* task=new Task;
    task->setDIY5();
    return task;
}

Task* Task::DIY6()
{
    Task* task=new Task;
    task->setDIY6();
    return task;
}

Task* Task::ChangeColor(Color color)
{
    Serial.println("Cons ChangeColor");
    Task* task=new Task;
    task->setChangeColor();
    Serial.println(task->isChangeColor());
    task->color = color;
    return task;
}

Task* Task::Pause()
{
    Task* task=new Task;
    task->setPause();
    return task;
}

Task* Task::Brighter()
{
    Task* task=new Task;
    task->setBrighter();
    return task;
}

Task* Task::Darker()
{
    Task* task=new Task;
    task->setDarker();
    return task;
}

Task* Task::OnOff()
{
    Task* task=new Task;
    task->setOnOff();
    return task;
}

Task* Task::RedUp()
{
    Task* task=new Task;
    task->setRedUp();
    return task;
}

Task* Task::RedDown()
{
    Task* task=new Task;
    task->setRedDown();
    return task;
}

Task* Task::GreenUp()
{
    Task* task=new Task;
    task->setGreenUp();
    return task;
}

Task* Task::GreenDown()
{
    Task* task=new Task;
    task->setGreenDown();
    return task;
}

Task* Task::BlueUp()
{
    Task* task=new Task;
    task->setBlueUp();
    return task;
}

Task* Task::BlueDown()
{
    Task* task=new Task;
    task->setBlueDown();
    return task;
}

Task* Task::Quick()
{
    Task* task=new Task;
    task->setQuick();
    return task;
}

Task* Task::Slow()
{
    Task* task=new Task;
    task->setSlow();
    return task;
}

bool Task::isRainbow()
{
    return doRainbow;
}

bool Task::isBlink()
{
    return doBlink;
}

bool Task::isFade3()
{
    return doFade3;
}

bool Task::isFade7()
{
    return doFade7;
}

bool Task::isJump3()
{
    return doJump3;
}

bool Task::isJump7()
{
    return doJump7;
}

bool Task::isDIY1()
{
    return doDIY1;
}       

bool Task::isDIY2()
{
    return doDIY2;
}

bool Task::isDIY3()
{
    return doDIY3;
}

bool Task::isDIY4()
{
    return doDIY4;
}

bool Task::isDIY5()
{
    return doDIY5;
}

bool Task::isDIY6()
{
    return doDIY6;
}

bool Task::isChangeColor()
{
    return doChangeColor;
}

bool Task::isPause()
{
    return doPause;
}

bool Task::isBrighter()
{
    return doBrighter;
}

bool Task::isDarker()
{
    return doDarker;
}

bool Task::isOnOff()
{
    return doOnOff;
}

bool Task::isRedUp()
{
    return doRedUp;
}

bool Task::isRedDown()
{
    return doRedDown;
}

bool Task::isGreenUp()
{
    return doGreenUp;
}

bool Task::isGreenDown()
{
    return doGreenDown;
}

bool Task::isBlueUp()
{
    return doBlueUp;
}

bool Task::isBlueDown()
{
    return doBlueDown;
}

bool Task::isQuick()
{
    return doQuick;
}

bool Task::isSlow()
{
    return doSlow;
}

Color Task::getColor()
{
    return color;
}

std::string Task::toString()
{
    std::string str ="";
    str += "Task: ";
    if (isChangeColor())
    {
        str += "ChangeColor, color: ";
        str += color.toString();
    }
    else if (isOnOff())
    {
        str += "OnOff";
    }
    else if (isBrighter())
    {
        str += "Brighter";
    }
    else if (isDarker())
    {
        str += "Darker";
    }
    else if (isRedUp())
    {
        str += "RedUp";
    }
    else if (isRedDown())
    {
        str += "RedDown";
    }
    else if (isGreenUp())
    {
        str += "GreenUp";
    }
    else if (isGreenDown())
    {
        str += "GreenDown";
    }
    else if (isBlueUp())
    {
        str += "BlueUp";
    }
    else if (isBlueDown())
    {
        str += "BlueDown";
    }
    else if (isQuick())
    {
        str += "Quick";
    }
    else if (isSlow())
    {
        str += "Slow";
    }
    else if (isPause()) {
        str += "Pause";
    }
    else if (isRainbow()) {
        str += "Rainbow";
    }
    else if (isBlink()) {
        str += "Blink";
    }
    else if (isFade3()) {
        str += "Fade3";
    }
    else if (isFade7()) {
        str += "Fade7";
    }
    else if (isJump3()) {
        str += "Jump3";
    }
    else if (isJump7()) {
        str += "Jump7";
    }
    else if (isDIY1()) {
        str += "DIY1";
    }
    else if (isDIY2()) {
        str += "DIY2";
    }
    else if (isDIY3()) {
        str += "DIY3";
    }
    else if (isDIY4()) {
        str += "DIY4";
    }
    else if (isDIY5()) {
        str += "DIY5";
    }
    else if (isDIY6()) {
        str += "DIY6";
    }
    return str;
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
    this->doChangeColor = doChangeColor;
}

void Task::setPause(bool doPause)
{
    this->clear();
    this->doPause = doPause;
}

void Task::setBrighter(bool doBrighter)
{
    this->clear();
    this->doBrighter = doBrighter;
}

void Task::setDarker(bool doDarker)
{
    this->clear();
    this->doDarker = doDarker;
}

void Task::setOnOff(bool doOnOff)
{
    this->clear();
    this->doOnOff = doOnOff;
}

void Task::setRedUp(bool doRedUp)
{
    this->clear();
    this->doRedUp = doRedUp;
}

void Task::setRedDown(bool doRedDown)
{
    this->clear();
    this->doRedDown = doRedDown;
}

void Task::setGreenUp(bool doGreenUp)
{
    this->clear();
    this->doGreenUp = doGreenUp;
}

void Task::setGreenDown(bool doGreenDown)
{
    this->clear();
    this->doGreenDown = doGreenDown;
}

void Task::setBlueUp(bool doBlueUp)
{
    this->clear();
    this->doBlueUp = doBlueUp;
}

void Task::setBlueDown(bool doBlueDown)
{
    this->clear();
    this->doBlueDown = doBlueDown;
}

void Task::setQuick(bool doQuick)
{
    this->clear();
    this->doQuick = doQuick;
}

void Task::setSlow(bool doSlow)
{
    this->clear();
    this->doSlow = doSlow;
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
