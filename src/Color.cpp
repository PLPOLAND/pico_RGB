#include "Color.h"

Color::Color()
{
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->brightness = 100;
}

Color::~Color()
{

}

Color::Color(byte red, byte green, byte blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->brightness = 100;
}
/// @brief Gets red value of the color with brightness taken into account
byte Color::getRed()
{
    return this->red * this->brightness / 100;
}

/// @brief Gets green value of the color with brightness taken into account
byte Color::getGreen()
{
    return this->green * this->brightness / 100;
}
/// @brief Gets blue value of the color with brightness taken into account
byte Color::getBlue()
{
    return this->blue * this->brightness / 100;
}
/// @brief Sets red value of the color
///
/// @param red (0, 255)

void Color::setRed(byte red){
    this->red = red;
}
/// @brief Sets green value of the color
///
/// @param green (0, 255)
void Color::setGreen(byte green){
    this->green = green;
}
/// @brief Sets blue value of the color
///
/// @param blue (0, 255)
void Color::setBlue(byte blue){
    this->blue = blue;
}
/// @brief Sets brightness of the color
/// 
/// @param brightness (0, 100)
void Color::setBrightness(byte brightness)
{
    if (brightness > 100)
    {
        brightness = 100;
    }
    else if (brightness < 0)
    {
        brightness = 0;
    }
    else
    {
        this->brightness = brightness;
    }
}

void Color::set(byte red, byte green, byte blue, int brightness){
    if (brightness != -1)
    {
        setBrightness(brightness);
    }
    setRed(red);
    setGreen(green);
    setBlue(blue);
    
}
void Color::set(float hue, byte saturation, int value){
    if (value != -1)
    {
        setBrightness(value);
    }

    int hi = static_cast<int>(std::floor(hue / 60.0)) % 6;
    float f = hue / 60.0 - std::floor(hue / 60.0);
    int v = static_cast<int>(value);
    int p = static_cast<int>(value * (1 - saturation/255.0));
    int q = static_cast<int>(value * (1 - f * saturation/255.0));
    int t = static_cast<int>(value * (1 - (1 - f) * saturation/255.0));
    switch (hi) {
    case 0:
        setRed(v);
        setGreen(t);
        setBlue(p);
        break;
    case 1:
        setRed(q);
        setGreen(v);
        setBlue(p);
        break;
    case 2:
        setRed(p);
        setGreen(v);
        setBlue(t);
        break;
    case 3:
        setRed(p);
        setGreen(q);
        setBlue(v);
        break;
    case 4:
        setRed(t);
        setGreen(p);
        setBlue(v);
        break;
    default:
        setRed(v);
        setGreen(p);
        setBlue(q);
        break;
    }
}

Color Color::fromHSV(float hue, byte saturation, int value){
    Color color;
    color.set(hue, saturation, value);
    return color;
}