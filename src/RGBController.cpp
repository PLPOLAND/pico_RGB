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

}

RGBController::RGBController(byte redPin, byte greenPin, byte bluePin)
{
}

RGBController::RGBController(byte redPin, byte greenPin, byte bluePin, Color color)
{
}

void RGBController::setColor(Color color)
{

}

void RGBController::getColor()
{
}

void RGBController::updatePins()
{
    this->color.getRed();
    this->color.getGreen();
    this->color.getBlue();
}

void RGBController::setRedPinValue(byte red)
{
}

void RGBController::setGreenPinValue(byte green)
{
}

void RGBController::setBluePinValue(byte blue)
{
}
