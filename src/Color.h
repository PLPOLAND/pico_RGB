#ifndef COLOR_H
#define COLOR_H

#pragma once
#include <Arduino.h>
#include <string>

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
    void set(std::string hex);
    void set(Color& color);

    static Color fromHSV(float hue, byte saturation, int value);
    static Color fromHex(std::string hex);

private:
    byte red; //0-255
    byte green; //0-255
    byte blue; //0-255

    byte brightness; // 0-100
};

#endif