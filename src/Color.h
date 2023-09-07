#ifndef COLOR_H
#define COLOR_H

#pragma once
#include <Arduino.h>

class Color
{
public:
    Color();
    ~Color();
    Color(byte red, byte green, byte blue);
    
    byte getRed();
    byte getGreen();
    byte getBlue();

    void setRed(byte red);
    void setGreen(byte green);
    void setBlue(byte blue);
    void setBrightness(byte brightness);

    void set(byte red, byte green, byte blue, int brightness = -1);
    void set(float hue, byte saturation, int value = -1);

    static Color fromHSV(float hue, byte saturation, int value);
    //TODO fromhex

private:
    byte red;
    byte green;
    byte blue;

    byte brightness; // 0-100
};

#endif