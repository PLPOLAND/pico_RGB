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

    static Color Red();
    static Color Green();
    static Color Blue();
    static Color White();

    static Color C1();
    static Color C2();
    static Color C3();
    static Color C4();
    static Color C5();
    static Color C6();
    static Color C7();
    static Color C8();
    static Color C9();
    static Color C10();
    static Color C11();
    static Color C12();
    static Color C13();
    static Color C14();
    static Color C15();
    static Color C16();



private:
    byte red; //0-255
    byte green; //0-255
    byte blue; //0-255

    byte brightness; // 0-100
};

#endif