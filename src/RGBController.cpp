#include "RGBController.h"

RGBController::RGBController()
{
    color.set(0, 0, 0);
    redPin = 0;
    greenPin = 1;
    bluePin = 2;
}

RGBController::~RGBController()
{
    delete task;
}

RGBController::RGBController(byte redPin, byte greenPin, byte bluePin)
{
    this->redPin = redPin;
    this->greenPin = greenPin;
    this->bluePin = bluePin;
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    this->color.set(0, 0, 0);
    this->task = nullptr;
}

RGBController::RGBController(byte redPin, byte greenPin, byte bluePin, Color color)
{
    this->redPin = redPin;
    this->greenPin = greenPin;
    this->bluePin = bluePin;
    this->color.set(color);
    this->task = nullptr;
}

void RGBController::setColor(Color color)
{
    this->color.set(color);
    this->updatePins();
}

Color RGBController::getColor()
{
    return this->color;
}

void RGBController::updatePins()
{
    setRedPinValue(this->color.getRed());
    setGreenPinValue(this->color.getGreen());
    setBluePinValue(this->color.getBlue());
}

void RGBController::setTask(Task* task)
{
    clearTask();
    this->task = task;
}

void RGBController::clearTask()
{
    delete task;
    task = nullptr;
}

void RGBController::tick()
{
    if (task == nullptr)
    {
        Serial.println(F("Task is null"));
    }
    
    if (task != nullptr)
    {
        // Serial.println(F("Task is not null"));
        // Serial.println(task->toString().c_str());
        if (task->isChangeColor())
        {
            this->setColor(task->getColor());

        }
        else if (task->isOnOff())
        {
            this->turnOnOff();
            this->clearTask();
        }
        else if (task->isBrighter())
        {
            this->color.setBrightness(this->color.getBrightness() + 10);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isDarker())
        {
            this->color.setBrightness(this->color.getBrightness() - 10);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isRedUp())
        {
            this->color.setRed(this->color.getRed() + 1);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isRedDown())
        {
            this->color.setRed(this->color.getRed() - 1);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isGreenUp())
        {
            this->color.setGreen(this->color.getGreen() + 1);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isGreenDown())
        {
            this->color.setGreen(this->color.getGreen() - 1);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isBlueUp())
        {
            this->color.setBlue(this->color.getBlue() + 1);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isBlueDown())
        {
            this->color.setBlue(this->color.getBlue() - 1);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isQuick())
        {
            //TODO
        }
        else if (task->isSlow())
        {
            //TODO
        }
        else if (task->isPause()){
            //TODO
        }
        else if(task->isRainbow()){
            //TODO
        }
        else if(task->isBlink()){
            //TODO
        }
        else if(task->isFade3()){
            //TODO
        }
        else if(task->isFade7()){
            //TODO
        }
        else if(task->isJump3()){
            //TODO
        }
        else if(task->isJump7()){
            //TODO
        }
        else if(task->isDIY1()){
            //TODO
        }
        else if(task->isDIY2()){
            //TODO
        }
        else if(task->isDIY3()){
            //TODO
        }
        else if(task->isDIY4()){
            //TODO
        }
        else if(task->isDIY5()){
            //TODO
        }
        else if(task->isDIY6()){
            //TODO
        }
        

    }
}

void RGBController::turnOnOff()
{
    if (this->isOn)
    {
        delete task;
        task = nullptr;
        this->setBluePinValue(0);
        this->setGreenPinValue(0);
        this->setRedPinValue(0);
        this->isOn = false;
    }
    else{
        this->setColor(this->color);
        this->isOn = true;
    }
    
}

void RGBController::setRedPinValue(byte red)
{
    analogWrite(this->redPin, red);
}

void RGBController::setGreenPinValue(byte green)
{
    analogWrite(this->greenPin, green);
}

void RGBController::setBluePinValue(byte blue)
{
    analogWrite(this->bluePin, blue);
}
