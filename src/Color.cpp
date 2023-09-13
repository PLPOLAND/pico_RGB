#include "Color.h"

Color::Color()
{
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->brightness = 100;
}

Color Color::Red()
{
    Color color;
    color.setRed(255);
    return color;
}

Color Color::Green()
{
    Color color;
    color.setGreen(255);
    return color;
}

Color Color::Blue()
{
    Color color;
    color.setBlue(255);
    return color;
}

Color Color::White()
{
    Color color;
    color.setRed(255);
    color.setGreen(255);
    color.setBlue(255);
    return color;
}

Color Color::C1()
{
    Color color;
    color.set("FF0F00");
    return color;
}

Color Color::C2()
{
    Color color;
    color.set("05FF05");
    return color;
}

Color Color::C3()
{
    Color color;
    color.set("0A0AFF");
    return color;
}

Color Color::C4()
{
    Color color;
    color.set("FF1464");
    return color;
}

Color Color::C5()
{
    Color color;
    color.set("FF1600");
    return color;
}

Color Color::C6()
{
    Color color;
    color.set("5959FF");
    return color;
}

Color Color::C7()
{
    Color color;
    color.set("B300FF");
    return color;
}

Color Color::C8()
{
    Color color;
    color.set("FF3277");
    return color;
}

Color Color::C9()
{
    Color color;
    color.set("FF2600");
    return color;
}

Color Color::C10()
{
    Color color;
    color.set("004F00");
    return color;
}

Color Color::C11()
{
    Color color;
    color.set("B300CF");
    return color;
}

Color Color::C12()
{
    Color color;
    color.set("4949FF");
    return color;
}

Color Color::C13()
{
    Color color;
    color.set("FF6600");
    return color;
}

Color Color::C14()
{
    Color color;
    color.set("001F00");
    return color;
}

Color Color::C15()
{
    Color color;
    color.set("E600FF");
    return color;
}

Color Color::C16()
{
    Color color;
    color.set("6969FF");
    return color;
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
/// @brief Sets color from hex string
void Color::set(std::string hex)
{
    byte r, g, b;

    sscanf(hex.c_str(), "%02x%02x%02x", &r, &g, &b);
    
    setRed(r);
    setGreen(g);
    setBlue(b);
}

/// @brief Sets color from another color
void Color::set(Color& color)
{
    setRed(color.getRed());
    setGreen(color.getGreen());
    setBlue(color.getBlue());
    setBrightness(color.brightness);
}
/// @brief Creates a color from HSV values
Color Color::fromHSV(float hue, byte saturation, int value){
    Color color;
    color.set(hue, saturation, value);
    return color;
}

/// @brief Creates a color from a hex string
Color Color::fromHex(std::string hex)
{
    Color color;
    color.set(hex);
    return color;
}