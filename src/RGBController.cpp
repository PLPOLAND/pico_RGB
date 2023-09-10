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
    this->redPin = redPin;
    this->greenPin = greenPin;
    this->bluePin = bluePin;
    color.set(0, 0, 0);
}

RGBController::RGBController(byte redPin, byte greenPin, byte bluePin, Color color)
{
    this->redPin = redPin;
    this->greenPin = greenPin;
    this->bluePin = bluePin;
    this->color.set(color);
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
