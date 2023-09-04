#include <Arduino.h>
#include "IRcode.h"
#include <Timers.h>
#if !defined(RGB_H)
#define RGB_H

String t = "";

typedef byte pin;

Timer of;
long timerTIME = MINS(5);

const byte dim_curve[] = {
    0,
    1,
    1,
    2,
    2,
    2,
    2,
    2,
    2,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    6,
    6,
    6,
    6,
    6,
    6,
    6,
    6,
    7,
    7,
    7,
    7,
    7,
    7,
    7,
    8,
    8,
    8,
    8,
    8,
    8,
    9,
    9,
    9,
    9,
    9,
    9,
    10,
    10,
    10,
    10,
    10,
    11,
    11,
    11,
    11,
    11,
    12,
    12,
    12,
    12,
    12,
    13,
    13,
    13,
    13,
    14,
    14,
    14,
    14,
    15,
    15,
    15,
    16,
    16,
    16,
    16,
    17,
    17,
    17,
    18,
    18,
    18,
    19,
    19,
    19,
    20,
    20,
    20,
    21,
    21,
    22,
    22,
    22,
    23,
    23,
    24,
    24,
    25,
    25,
    25,
    26,
    26,
    27,
    27,
    28,
    28,
    29,
    29,
    30,
    30,
    31,
    32,
    32,
    33,
    33,
    34,
    35,
    35,
    36,
    36,
    37,
    38,
    38,
    39,
    40,
    40,
    41,
    42,
    43,
    43,
    44,
    45,
    46,
    47,
    48,
    48,
    49,
    50,
    51,
    52,
    53,
    54,
    55,
    56,
    57,
    58,
    59,
    60,
    61,
    62,
    63,
    64,
    65,
    66,
    68,
    69,
    70,
    71,
    73,
    74,
    75,
    76,
    78,
    79,
    81,
    82,
    83,
    85,
    86,
    88,
    90,
    91,
    93,
    94,
    96,
    98,
    99,
    101,
    103,
    105,
    107,
    109,
    110,
    112,
    114,
    116,
    118,
    121,
    123,
    125,
    127,
    129,
    132,
    134,
    136,
    139,
    141,
    144,
    146,
    149,
    151,
    154,
    157,
    159,
    162,
    165,
    168,
    171,
    174,
    177,
    180,
    183,
    186,
    190,
    193,
    196,
    200,
    203,
    207,
    211,
    214,
    218,
    222,
    226,
    230,
    234,
    238,
    242,
    248,
    255,
};

struct rgb_colors;

void getRGB(int hue, int sat, int val, rgb_colors &kol);

rgb_colors rgb2hsv(rgb_colors &in);

struct rgb_colors
{
    rgb_colors(byte a = 0, byte b = 0, byte c = 0) : r(0), g(0), b(0), H(a), S(b), V(c){};

    void update(byte t)
    {
        getRGB(H, S, t, *this);
    }

    void setHSV(byte a = 0, byte b = 0, byte c = 0)
    {
        H = a;
        S = b;
        V = c;
    }
    byte r;
    byte g;
    byte b;

    int H;
    int S;
    int V;
};

// rgb_colors rgb2hsv(rgb_colors &in)
// {
//     rgb_colors &out = in;
//     double min, max, delta;

//     min = in.r < in.g ? in.r : in.g;
//     min = min < in.b ? min : in.b;

//     max = in.r > in.g ? in.r : in.g;
//     max = max > in.b ? max : in.b;

//     out.V = max; // v
//     delta = max - min;
//     if (delta < 0.00001)
//     {
//         out.S = 0;
//         out.H = 0; // undefined, maybe nan?
//         return out;
//     }
//     if (max > 0.0)
//     {                          // NOTE: if Max is == 0, this divide would cause a crash
//         out.S = (delta / max); // s
//     }
//     else
//     {
//         // if max is 0, then r = g = b = 0
//         // s = 0, h is undefined
//         out.S = 0.0;
//         out.H = NAN; // its now undefined
//         return out;
//     }
//     if (in.r >= max)                   // > is bogus, just keeps compilor happy
//         out.H = (in.g - in.b) / delta; // between yellow & magenta
//     else if (in.g >= max)
//         out.H = 2.0 + (in.b - in.r) / delta; // between cyan & yellow
//     else
//         out.H = 4.0 + (in.r - in.g) / delta; // between magenta & cyan

//     out.H *= 60.0; // degrees

//     if (out.H < 0.0)
//         out.H += 360.0;
//     return out;
// }

void getRGB(int hue, int sat, int val, rgb_colors &kol)
{
    /* convert hue, saturation and brightness ( HSB/HSV ) to RGB
        The dim_curve is used only on brightness/value and on saturation (inverted).
        This looks the most natural.*/

    val = dim_curve[val];
    sat = 255 - dim_curve[255 - sat];

    int r;
    int g;
    int b;
    int base;

    kol.H = hue;
    kol.S = sat;
    kol.V = val;

    if (sat == 0)
    { // Acromatic color (gray). Hue doesn't mind.
        kol.r = val;
        kol.g = val;
        kol.b = val;
    }
    else
    {
        base = ((255 - sat) * val) >> 8;

        switch (hue / 60)
        {
        case 0:
            r = val;
            g = (((val - base) * hue) / 60) + base;
            b = base;
            break;

        case 1:
            r = (((val - base) * (60 - (hue % 60))) / 60) + base;
            g = val;
            b = base;
            break;

        case 2:
            r = base;
            g = val;
            b = (((val - base) * (hue % 60)) / 60) + base;
            break;

        case 3:
            r = base;
            g = (((val - base) * (60 - (hue % 60))) / 60) + base;
            b = val;
            break;

        case 4:
            r = (((val - base) * (hue % 60)) / 60) + base;
            g = base;
            b = val;
            break;

        case 5:
            r = val;
            g = base;
            b = (((val - base) * (60 - (hue % 60))) / 60) + base;
            break;
        }

        // kol.r = 255 - r; //do zmiany w finalnej wersji
        // if (kol.r < 0)
        //     kol.r = -kol.r;

        // kol.g = 255 - g; //do zmiany w finalnej wersji
        // if (kol.g < 0)
        //     kol.g = -kol.g;

        // kol.b = 255 - b; //do zmiany w finalnej wersji
        // if (kol.b < 0)
        //     kol.b = -kol.b;
        kol.r = r;
        kol.g = g;
        kol.b = b;
    }
}

bool inline _cyfra_Hex(char t)
{

    if ((t >= '0' && t <= '9') || (t >= 'A' && t <= 'F'))
        return true;
    else
        return false;
}
byte inline _cyfra_Hex_to_dec(char t)
{
    if (t >= '0' && t <= '9')
    {
        return t - '0';
    }
    else if (t == 'A')
        return 10;
    else if (t == 'B')
        return 11;
    else if (t == 'C')
        return 12;
    else if (t == 'D')
        return 13;
    else if (t == 'E')
        return 14;
    else if (t == 'F')
        return 15;
    else
        return 0;
}
template <typename T>
void hexToRGB(T t, rgb_colors &kol, byte MaxL = 100)
{
    char *wsk = nullptr;
    wsk = const_cast<char *>(t);
    if (_cyfra_Hex(*wsk))
    {
        kol.r = _cyfra_Hex_to_dec(*wsk) * 16;
    }
    wsk++;
    if (_cyfra_Hex(*wsk))
    {
        kol.r += _cyfra_Hex_to_dec(*wsk);
    }
    else
    {
        Serial.println("Blad1");
    }
    wsk++;
    if (_cyfra_Hex(*wsk))
    {
        kol.g = _cyfra_Hex_to_dec(*wsk) * 16;
    }
    wsk++;
    if (_cyfra_Hex(*wsk))
    {
        kol.g += _cyfra_Hex_to_dec(*wsk);
    }
    else
    {
        Serial.println("Blad1");
    }
    wsk++;
    if (_cyfra_Hex(*wsk))
    {
        kol.b = _cyfra_Hex_to_dec(*wsk) * 16;
    }
    wsk++;
    if (_cyfra_Hex(*wsk))
    {
        kol.b += _cyfra_Hex_to_dec(*wsk);
    }
    else
    {
        Serial.println("Blad1");
    }

    // Serial.print(" R: ");
    // Serial.print(kol.r);
    // Serial.print(" G: ");
    // Serial.print(kol.g);
    // Serial.print(" B: ");
    // Serial.println(kol.b);

    kol.r = floor(kol.r * ((double)MaxL / 100));
    kol.g = floor(kol.g * ((double)MaxL / 100));
    kol.b = floor(kol.b * ((double)MaxL / 100));
    // Serial.println("AFTER");
    // Serial.print(" R: ");
    // Serial.print(kol.r);
    // Serial.print(" G: ");
    // Serial.print(kol.g);
    // Serial.print(" B: ");
    // Serial.println(kol.b);
}

template <>
void hexToRGB<String>(String t, rgb_colors &kol, byte MaxL)
{

    if (_cyfra_Hex(t[0]))
    {
        kol.r = _cyfra_Hex_to_dec(t[0]) * 16;
    }
    if (_cyfra_Hex(t[1]))
    {
        kol.r += _cyfra_Hex_to_dec(t[1]);
    }
    else
    {
        Serial.println("Blad1");
    }
    if (_cyfra_Hex(t[2]))
    {
        kol.g = _cyfra_Hex_to_dec(t[2]) * 16;
    }
    if (_cyfra_Hex(t[3]))
    {
        kol.g += _cyfra_Hex_to_dec(t[3]);
    }
    else
    {
        Serial.println("Blad2");
    }
    if (_cyfra_Hex(t[4]))
    {
        kol.b = _cyfra_Hex_to_dec(t[4]) * 16;
    }
    if (_cyfra_Hex(t[5]))
    {
        kol.b += _cyfra_Hex_to_dec(t[5]);
    }
    else
    {
        Serial.println("Blad3");
    }

    kol.r = floor(kol.r * ((double)MaxL / 100));
    kol.g = floor(kol.g * ((double)MaxL / 100));
    kol.b = floor(kol.b * ((double)MaxL / 100));
}

struct flagi
{
    flagi() : czyTecza(false), czyZmianaKol(false), czyJump3(false), czyJump7(false), czyDIY1(false), czyDIY2(false), czyDIY3(false), czyFade3(false), czyFade7(false){};

    bool czyTecza;
    bool czyZmianaKol;
    bool czyJump3;
    bool czyJump7;
    bool czyDIY1;
    bool czyDIY2;
    bool czyDIY3;
    bool czyFade3;
    bool czyFade7;
    byte last;

    void reset()
    {
        if (czyTecza == true)
        {
            last = 0;
        }
        else if (czyJump3 == true)
        {
            last = 2;
        }
        else if (czyDIY1 == true)
        {
            last = 3;
        }
        else if (czyFade3 == true)
        {
            last = 4;
        }
        else if (czyFade7 == true)
        {
            last = 5;
        }
        else if (czyJump7 == true)
        {
            last = 6;
        }
        else if (czyDIY1 == true)
        {
            last = 7;
        }
        else if (czyZmianaKol == true)
        {
            last = 1;
        }
        else if(czyDIY3 == true){
            last = 8;
        }

        czyTecza = false;
        czyZmianaKol = false;
        czyJump3 = false;
        czyJump7 = false;
        czyDIY1 = false;
        czyDIY2 = false;
        // czyDIY3 = false;
        czyFade3 = false;
        czyFade7 = false;
    }
    void set_from_last()
    {
        if (last == 0)
        {
            czyTecza = true;
            czyZmianaKol = false;
            czyJump3 = false;
            czyDIY1 = false;
            czyDIY2 = false;
            czyFade3 = false;
            czyFade7 = false;
            czyJump7 = false;
            czyDIY3 = false;
        }
        else if (last == 1)
        {
            czyTecza = false;
            czyZmianaKol = true;
            czyJump3 = false;
            czyDIY1 = false;
            czyDIY2 = false;
            czyFade3 = false;
            czyFade7 = false;
            czyJump7 = false;
            czyDIY3 = false;
        }
        else if (last == 2)
        {
            czyTecza = false;
            czyZmianaKol = false;
            czyJump3 = true;
            czyDIY1 = false;
            czyDIY2 = false;
            czyFade3 = false;
            czyFade7 = false;
            czyJump7 = false;
            czyDIY3 = false;
        }
        else if (last == 3)
        {
            czyTecza = false;
            czyZmianaKol = false;
            czyJump3 = false;
            czyDIY1 = true;
            czyDIY2 = false;
            czyFade3 = false;
            czyFade7 = false;
            czyJump7 = false;
            czyDIY3 = false;
        }
        else if (last == 4)
        {
            czyTecza = false;
            czyZmianaKol = false;
            czyJump3 = false;
            czyDIY1 = false;
            czyDIY2 = false;
            czyFade3 = true;
            czyFade7 = false;
            czyJump7 = false;
            czyDIY3 = false;
        }
        else if (last == 5)
        {
            czyTecza = false;
            czyZmianaKol = false;
            czyJump3 = false;
            czyDIY1 = false;
            czyFade3 = false;
            czyDIY2 = false;
            czyFade7 = true;
            czyJump7 = false;
            czyDIY3 = false;
        }
        else if (last == 6)
        {
            czyTecza = false;
            czyZmianaKol = false;
            czyJump3 = false;
            czyDIY1 = false;
            czyDIY2 = false;
            czyFade3 = false;
            czyFade7 = false;
            czyJump7 = true;
            czyDIY3 = false;
        }
        else if (last == 7)
        {
            czyTecza = false;
            czyZmianaKol = false;
            czyJump3 = false;
            czyDIY1 = false;
            czyFade3 = false;
            czyFade7 = false;
            czyJump7 = false;
            czyDIY2 = true;
            czyDIY3 = false;
        }
        else if (last == 8)
        {
            czyTecza = false;
            czyZmianaKol = false;
            czyJump3 = false;
            czyDIY1 = false;
            czyFade3 = false;
            czyFade7 = false;
            czyJump7 = false;
            czyDIY2 = false;
            czyDIY3 = true;
        }
    }
    bool any_on()
    {
        if (czyTecza == true || czyZmianaKol == true || czyJump3 == true || czyDIY1 == true || czyFade3 == true || czyFade7 == true || czyJump7 == true || czyDIY2 == true || czyDIY3 == true)
            return true;
        else
            return false;
    }
};

class rgb
{
private:
    rgb_colors kolory;
    rgb_colors newKolor;
    pin pinR;
    pin pinG;
    pin pinB;
    byte maxLight;
    flagi flags;

    long speed;
    unsigned long timer;

public:
    rgb(byte a = 0, byte c = 0, byte d = 0, pin e = 9, pin f = 6, pin g = 5, bool t = false, int ts = 20) : kolory(a, c, d), newKolor(0, 0, 0), pinR(e), pinG(f), pinB(g), maxLight(100), flags(), timer(0),speed(100){};
    void set(byte a, byte c, byte d)
    {
        kolory.r = a;
        // kolory.r = floor(a * ((double)maxLight / 100));
        analogWrite(pinR, kolory.r * ((double)maxLight / 100));

        kolory.g = c;
        // kolory.g = floor(c * ((double)maxLight / 100));
        analogWrite(pinG, kolory.g * ((double)maxLight / 100));

        kolory.b = d;
        // kolory.b = floor(d * ((double)maxLight / 100));
        analogWrite(pinB, kolory.b * ((double)maxLight / 100));
    }
    void set()
    {
        // kolory.r = a;
        // kolory.r = floor(a * ((double)maxLight / 100));
        analogWrite(pinR, kolory.r * ((double)maxLight / 100));

        // kolory.g = c;
        // kolory.g = floor(c * ((double)maxLight / 100));
        analogWrite(pinG, kolory.g * ((double)maxLight / 100));

        // kolory.b = d;
        // kolory.b = floor(d * ((double)maxLight / 100));
        analogWrite(pinB, kolory.b * ((double)maxLight / 100));
        Serial.println("bez");
    }
    void temporaryset(byte r, byte g, byte b)
    {
        analogWrite(pinR, r);
        analogWrite(pinG, g);
        analogWrite(pinB, b);
    }

    void tecza()
    {
        if (kolory.g < 255 && kolory.b == 0)
        {
            kolory.r--;
            kolory.g++;
        }
        if (kolory.b < 255 && kolory.r == 0)
        {
            kolory.g--;
            kolory.b++;
        }
        if (kolory.r < 255 && kolory.g == 0)
        {
            kolory.r++;
            kolory.b--;
        }
        set(kolory.r, kolory.g, kolory.b);
    }

    void Zmianakol()
    {

        if (kolory.r < newKolor.r)
        {
            kolory.r++;
        }
        else if (kolory.r > newKolor.r)
        {
            kolory.r--;
        }
        if (kolory.g < newKolor.g)
        {
            kolory.g++;
        }
        else if (kolory.g > newKolor.g)
        {
            kolory.g--;
        }
        if (kolory.b < newKolor.b)
        {
            kolory.b++;
        }
        else if (kolory.b > newKolor.b)
        {
            kolory.b--;
        }

        if (kolory.r == newKolor.r && kolory.g == newKolor.g && kolory.b == newKolor.b)
        {
            flags.czyZmianaKol = false;
        }
        set(kolory.r, kolory.g, kolory.b);
    }
    void DIY1()
    {
        byte tmp = rand() % 3;

        if (tmp == 0)
        {
            newKolor.r = rand() % 255;
            newKolor.g = rand() % 255;
            newKolor.b = 0;

            // set(rand() % 255, rand() % 255, 0);
        }
        else if (tmp == 1)
        {
            newKolor.r = rand() % 255;
            newKolor.g = 0;
            newKolor.b = rand() % 255;
        }
        else
        {
            newKolor.r = 0;
            newKolor.g = rand() % 255;
            newKolor.b = rand() % 255;
        }

        flags.czyZmianaKol = true;
        Zmianakol();
    }
    void DIY2()
    {
        //static byte t = 0;
        static bool znak = true;

        if (znak == true)
        {
            maxLight++;
        }
        else
        {
            maxLight--;
        }

        if (maxLight >= 100)
        {
            maxLight = 100;
            znak = false;
        }
        else if (maxLight <= 0)
        {
            maxLight = 0;
            znak = true;
        }

        set();
    }
    //off after time
    void DIY3(){
        if (of.available())
        {
            hexToRGB("000000", newKolor , maxLight);
            
            // set(newKolor.r, newKolor.g, newKolor.b);
            flags.reset();
            flags.czyDIY3 = false;
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        
    }

    void JUMP3()
    {
        static byte num = 0;
        //Serial.println(num);
        if (num == 0)
        {
            //resetuj_flagi();
            hexToRGB("FF0600", newKolor, maxLight);
            // czyZmianaKol = true;
            // Zmianakol();
            set(newKolor.r, newKolor.g, newKolor.b);
            num++;
        }
        else if (num == 1)
        {
            //resetuj_flagi();
            hexToRGB("02FF02", newKolor, maxLight);
            // czyZmianaKol = true;
            // Zmianakol();
            set(newKolor.r, newKolor.g, newKolor.b);
            num++;
        }
        else
        {
            //resetuj_flagi();
            hexToRGB("1010FF", newKolor, maxLight);
            // czyZmianaKol = true;
            // Zmianakol();
            set(newKolor.r, newKolor.g, newKolor.b);
            num = 0;
        }
    }
    void JUMP7()
    {
        static byte num = 0;
        //Serial.println(num);
        if (num == 0)
        {
            //resetuj_flagi();
            hexToRGB("FF0600", newKolor, maxLight);
            // czyZmianaKol = true;
            // Zmianakol();
            set(newKolor.r, newKolor.g, newKolor.b);
            num++;
        }
        if (num == 1)
        {
            //resetuj_flagi();
            hexToRGB("FF1601", newKolor, maxLight);
            // czyZmianaKol = true;
            // Zmianakol();
            set(newKolor.r, newKolor.g, newKolor.b);
            num++;
        }
        if (num == 2)
        {
            //resetuj_flagi();
            hexToRGB("FFA601", newKolor, maxLight);
            // czyZmianaKol = true;
            // Zmianakol();
            set(newKolor.r, newKolor.g, newKolor.b);
            num++;
        }
        else if (num == 3)
        {
            //resetuj_flagi();
            hexToRGB("02FF02", newKolor, maxLight);
            // czyZmianaKol = true;
            // Zmianakol();
            set(newKolor.r, newKolor.g, newKolor.b);
            num++;
        }
        else if (num == 4)
        {
            //resetuj_flagi();
            hexToRGB("02FF10", newKolor, maxLight);
            // czyZmianaKol = true;
            // Zmianakol();
            set(newKolor.r, newKolor.g, newKolor.b);
            num++;
        }
        else if (num == 5)
        {
            //resetuj_flagi();
            hexToRGB("02FFA2", newKolor, maxLight);
            // czyZmianaKol = true;
            // Zmianakol();
            set(newKolor.r, newKolor.g, newKolor.b);
            num++;
        }
        else
        {
            //resetuj_flagi();
            hexToRGB("1010FF", newKolor, maxLight);
            // czyZmianaKol = true;
            // Zmianakol();
            set(newKolor.r, newKolor.g, newKolor.b);
            num = 0;
        }
    }
    void FADE3()
    {
        static byte num = 0;
        //Serial.println(num);
        if (num == 0)
        {
            //resetuj_flagi();
            hexToRGB("FF0600", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
            num++;
        }
        else if (num == 1)
        {
            //resetuj_flagi();
            hexToRGB("02FF02", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
            num++;
        }
        else
        {
            //resetuj_flagi();
            hexToRGB("1010FF", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
            num = 0;
        }
    }


    void ObslozIR(IRcode::kodIR &ir)
    {

        switch (ir)
        {
        case IRcode::WYL:
            flags.reset();
            if (kolory.r != 0 || kolory.b != 0 || kolory.g != 0)
            {
                hexToRGB("000000", newKolor, 0);
                flags.czyZmianaKol = true;
                Zmianakol();
            }
            else
            {
                hexToRGB("FF6600", newKolor, maxLight);
                flags.czyZmianaKol = true;
                Zmianakol();
            }
            break;

        case IRcode::AUTO:
            flags.reset();
            hexToRGB("FF0000", newKolor, maxLight);
            set(newKolor.r, newKolor.g, newKolor.b);
            flags.czyTecza = true;
            break;

        case IRcode::PAUZA_PLAY:
            if (flags.any_on())
                flags.reset();
            else
                flags.set_from_last();
            break;

        case IRcode::W:
        {
            flags.reset();
            hexToRGB("FFFFFF", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::JASNIEJ: //TODO:
            if (maxLight < 100 && (maxLight + 10) < 100)
            {
                maxLight = maxLight + 10;
            }
            else if (maxLight < 100)
            {
                maxLight = 100;
            }
            set(kolory.r, kolory.g, kolory.b);
            break;

        case IRcode::CIEMNIEJ: //TODO:
            if (maxLight > 0 && (maxLight - 10) > 0)
            {
                maxLight = maxLight - 10;
            }
            else if (maxLight > 0)
            {
                maxLight = 0;
            }
            set(kolory.r, kolory.g, kolory.b);
            break;

        case IRcode::RPLUS:
            set(++kolory.r, kolory.g, kolory.b);
            break;

        case IRcode::RMINUS:
            set(--kolory.r, kolory.g, kolory.b);
            break;

        case IRcode::BPLUS:
            set(kolory.r, kolory.g, ++kolory.b);
            break;

        case IRcode::BMINUS:
            set(kolory.r, kolory.g, --kolory.b);
            break;

        case IRcode::GPLUS:

            set(kolory.r, ++kolory.g, kolory.b);
            break;

        case IRcode::GMINUS:
            set(kolory.r, --kolory.g, kolory.b);
            break;

        case IRcode::SLOW:
            speed = 100;
            timerTIME = MINS(10);
            break;

        case IRcode::QUICK:
            timerTIME = MINS(5);
            speed = 20;
            break;

        case IRcode::R:
        {
            flags.reset();
            hexToRGB("FF0000", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::G:
        {
            flags.reset();
            hexToRGB("00FF00", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::B:
        {
            flags.reset();
            hexToRGB("0000FF", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C1:
        {
            flags.reset();
            hexToRGB("FF0F00", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C2:
        {
            flags.reset();
            hexToRGB("05FF05", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C3:
        {
            flags.reset();
            hexToRGB("0A0AFF", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C4:
        {
            flags.reset();
            hexToRGB("FF1464", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C5:
        {
            flags.reset();
            hexToRGB("FF1600", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C6:
        {
            flags.reset();
            hexToRGB("5959FF", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C7:
        {
            flags.reset();
            hexToRGB("B300FF", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C8:
        {
            flags.reset();
            hexToRGB("FF3277", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C9:
        {
            flags.reset();
            hexToRGB("FF2600", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C10:
        {
            flags.reset();
            hexToRGB("004F00", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C11:
        {
            flags.reset();
            hexToRGB("B300CF", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C12:
        {
            flags.reset();
            hexToRGB("4949FF", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C13:
        {
            flags.reset();
            hexToRGB("FF6600", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C14:
        {
            flags.reset();
            hexToRGB("001F00", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C15:
        {
            flags.reset();
            hexToRGB("E600FF", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;

        case IRcode::C16:
        {
            flags.reset();
            hexToRGB("6969FF", newKolor, maxLight);
            flags.czyZmianaKol = true;
            Zmianakol();
        }
        break;
        case IRcode::DIY1:
            flags.reset();
            flags.czyDIY1 = true;
            break;
        case IRcode::DIY2:
            flags.reset();
            flags.czyDIY2 = true;
            break;
        case IRcode::DIY3:
            blink("FF0000");
            of.begin(timerTIME);
            // flags.reset();
            flags.czyDIY3 = true;
            break;
        case IRcode::JUMP3:
            flags.reset();
            flags.czyJump3 = true;
            break;
        case IRcode::JUMP7:
            flags.reset();
            flags.czyJump7 = true;
            break;
        case IRcode::FADE3:
            flags.reset();
            flags.czyFade3 = true;
            break;
        default:
            break;
        }
    }

    void operator()()
    {
        unsigned long curr_time = millis();
        // Serial.print(long(curr_time - timer));
        // Serial.print(" ");
        // Serial.println((long)(curr_time - timer) > 5L);
        if (this->flags.czyDIY3 == true)
        {
            DIY3();
        }
        
        if (this->flags.czyTecza == true && long(curr_time - timer) > speed)
        {
            tecza();
            timer = curr_time + speed;
        }
        if (this->flags.czyZmianaKol == true && long(curr_time - timer) > 1L)
        {
            Zmianakol();
            timer = curr_time + 1;
        }
        if (this->flags.czyDIY1 == true && long(curr_time - timer) > 400)
        {
            DIY1();
            timer = curr_time + 400;
        }
        if (this->flags.czyDIY2 == true && long(curr_time - timer) > speed)
        {
            DIY2();
            timer = curr_time + speed;
        }
        if (this->flags.czyJump3 == true && long(curr_time - timer) > 1000)
        {
            JUMP3();
            timer = curr_time + 1000;
        }
        if (this->flags.czyJump7 == true && long(curr_time - timer) > 1000)
        {
            JUMP7();
            timer = curr_time + 1000;
        }
        if (this->flags.czyFade3 == true && long(curr_time - timer) > 1000)
        {
            FADE3();
            timer = curr_time + 1000;
        }
        if (Serial.available())
        {
            
            while (Serial.available() > 0)
            {
                t += (char)Serial.read();
            }
            if(t.length() == 6)
            {
                Serial.println(t);
                flags.reset();
                hexToRGB(t, newKolor);
                flags.czyZmianaKol = true;
                // Zmianakol();
                set(newKolor.r,newKolor.g,newKolor.b);
                t = "";
            }
        }
        //FF5F3A
        //Serial.println(maxLight);
        // Serial.print("speed: ");
        // Serial.print(millis());
        // Serial.print(" ");
        // Serial.print(timer);
        // Serial.print(" ");
        // Serial.print(speed);
        // Serial.print(" ");
        // Serial.print(" R: ");
        // Serial.print(this->kolory.r);
        // Serial.print(" G: ");
        // Serial.print(this->kolory.g);
        // Serial.print(" B: ");
        // Serial.println(this->kolory.b);
    }
    void blink(String t){
        rgb_colors tmp;
        hexToRGB(t, tmp, 100);
        if (tmp.r == kolory.r && tmp.g == kolory.g && kolory.b == tmp.b)
        {
            temporaryset(0,0,0);
            delay(200);
        }        
        temporaryset(tmp.r, tmp.g, tmp.b);
        delay(200);
        if (tmp.r == kolory.r && tmp.g == kolory.g && kolory.b == tmp.b)
        {
            temporaryset(0,0,0);
            delay(200);
        }   
        set();

        Serial.println("Blinked");
    }
};

//
#endif // RGB_H
