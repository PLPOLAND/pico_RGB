#ifndef RGBCONTROLLER_H
#define RGBCONTROLLER_H

#pragma once
#include <Arduino.h>
#include "Color.h"
#include "Task.h"

/// @brief class for controlling RGB LED strip
class RGBController
{
public:
    RGBController();
    ~RGBController();
    RGBController(byte redPin, byte greenPin, byte bluePin);
    RGBController(byte redPin, byte greenPin, byte bluePin, Color color);
    void setColor(Color color);
    Color getColor();
    void updatePins();
    void turnOnOff();

    void setTask( Task* task);
    void clearTask();

    void tick();


private:
    Color color;
    byte redPin;
    byte greenPin;
    byte bluePin;

    Task* task;
    
    bool isOn;

    void setRedPinValue(byte red);
    void setGreenPinValue(byte green);
    void setBluePinValue(byte blue);
};

#endif