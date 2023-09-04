#include <ARGBControl.h>

#define COLORSPAN 2
#define RAINBOWDELAY 100

bool inline isCyfraHex(char t)
{

    if ((t >= '0' && t <= '9') || (t >= 'A' && t <= 'F'))
        return true;
    else
        return false;
}
byte inline isCyfraHex_to_dec(char t)
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
int rFromHex(char *t)
{
    int r = 0;
    char *wsk = nullptr;
    wsk = t;
     Serial.println(*wsk);
    if (isCyfraHex(*wsk))
    {
        r = isCyfraHex_to_dec(*wsk) * 16;
    }
    wsk++;
     Serial.println(*wsk);
    if (isCyfraHex(*wsk))
    {
        r += isCyfraHex_to_dec(*wsk);
    }
    else
    {
        Serial.println("Blad1");
    }
    return r;
}
int gFromHex(char *t)
{
    int g = 0;
    char *wsk = nullptr;
    wsk = t;

    wsk++;
    wsk++;
     Serial.println(*wsk);
    if (isCyfraHex(*wsk))
    {
        g = isCyfraHex_to_dec(*wsk) * 16;
        Serial.print("g:");
        Serial.println(g);
    }
    wsk++;
     Serial.println(*wsk);
    if (isCyfraHex(*wsk))
    {
        g += isCyfraHex_to_dec(*wsk);
        Serial.print("g:");
        Serial.println(g);
    }
    else
    {
        Serial.println("Blad2");
    }
    return g;
}
int bFromHex(char *t)
{
    int b = 0;
    char *wsk = nullptr;
    wsk = t;

    wsk++;
    wsk++;
    wsk++;
    wsk++;
     Serial.println(*wsk);
    if (isCyfraHex(*wsk))
    {
        b = isCyfraHex_to_dec(*wsk) * 16;
    }
    wsk++;
     Serial.println(*wsk);
    if (isCyfraHex(*wsk))
    {
        b += isCyfraHex_to_dec(*wsk);
    }
    else
    {
        Serial.println("Blad3");
    }
    return b;
}

ARGBControl::ARGBControl()
{
    Serial.println("Started");
    strip = new Adafruit_NeoPixel(15, 12, NEO_GRB + NEO_KHZ800);
    strip->begin();
    strip->show();
    strip->setBrightness(255);

    timer.begin(1);

}

ARGBControl::~ARGBControl()
{
    delete strip;
}

void ARGBControl::rainbowStep(){

    if (!timer.available())
    {
        return;
    }

    timer.begin(RAINBOWDELAY);

    static int r = 255;
    static int g = 0;
    static int b = 0;
    const byte COLORSTEP = 20;

        uint32_t color = strip->getPixelColor(0);
        r = (color >> 16) & 0xff;
        g = (color >> 8) & 0xff;
        b = color &0xff;
        
        {
            if (g < 255 && b == 0)
            {
                r -= COLORSTEP;
                g += COLORSTEP;
            }
            if (b < 255 && r == 0)
            {
                g -= COLORSTEP;
                b += COLORSTEP;
            }
            if (r < 255 && g == 0)
            {
                r += COLORSTEP;
                b -= COLORSTEP;
            }

            if (r > 255)
            {
                r = 255;
            }
            if (g > 255)
            {
                g = 255;
            }
            if (b > 255)
            {
                b = 255;
            }
            if (r < 0)
            {
                r = 0;
            }
            if (g < 0)
            {
                g = 0;
            }
            if (b < 0)
            {
                b = 0;
            }
        }
        // Serial.println("r \t g \t b ");
        // Serial.print(r);
        // Serial.print("\t");
        // Serial.print(g);
        // Serial.print("\t");
        // Serial.print(b);
        Serial.println("\t");
        for (size_t i = 0; i < 15; i = i + COLORSPAN)
        {
            for (size_t j = i; j < i+COLORSPAN && j<15; j++)
            {
                strip->setPixelColor(j, strip->Color(r, g, b));
            }
            // Serial.println("r \t g \t b ");
            // Serial.print(r);
            // Serial.print("\t");
            // Serial.print(g);
            // Serial.print("\t");
            // Serial.print(b);
            // Serial.println("\t");
            if (g < 255 && b == 0)
            {
                r -= COLORSTEP;
                g += COLORSTEP;
            }
            if (b < 255 && r == 0)
            {
                g -= COLORSTEP;
                b += COLORSTEP;
            }
            if (r < 255 && g == 0)
            {
                r += COLORSTEP;
                b -= COLORSTEP;
            }

            if (r > 255)
            {
                r = 255;
            }
            if (g > 255)
            {
                g = 255;
            }
            if (b > 255)
            {
                b = 255;
            }
            if (r < COLORSTEP)
            {
                r = 0;
            }
            if (g < COLORSTEP)
            {
                g = 0;
            }
            if (b < COLORSTEP)
            {
                b = 0;
            }
        }
    strip->show();
    
}

void ARGBControl::off(){
    // if (strip->getBrightness() == 0)
    // {
    //     strip->setBrightness(250);
    // }
    // else{
    //     strip->setBrightness(0);
    // }
    strip->clear();
    strip->show();
}
void ARGBControl::alarm(){
    for (size_t i = 0; i < 15; i++)
    {
        for (size_t j = 0; j < 15; j++)
        {
            if (i==j || j-1==i || j+1 == i)
            {
                strip->setPixelColor(j,255,0,0);
            }
            else{
                strip->setPixelColor(j,0,0,0);
            }
            
        }
        strip->show();
        delay(50);
    }
    strip->clear();
    strip->show();
}

void ARGBControl::setFullColor(int r, int g, int b){
    for (size_t i = 0; i < 15; i++)
    {
        strip->setPixelColor(i,r,g,b);
    }
    strip->show();
}
void ARGBControl::setFullColor(char* str){

    int r = 0;
    int g = 0;
    int b = 0;
    r = rFromHex(str);
    g = gFromHex(str);
    b = bFromHex(str);
    Serial.println("r \t g \t b ");
    Serial.print(r);
    Serial.print("\t");
    Serial.print(g);
    Serial.print("\t");
    Serial.print(b);
    setFullColor(r,g,b);
}

void ARGBControl::operator()(){
    if (rainbow)
    {
        rainbowStep();
    }
    
}

void ARGBControl::ObslozIR(IRcode::kodIR kod)
{
    
    
    switch (kod)
    {
    case IRcode::WYL :
        this->off();
        rainbow = false;
        break;
    case IRcode::AUTO :
        rainbow = true;
        break;
    case IRcode::JASNIEJ:
    {
        strip->setBrightness(strip->getBrightness()+10);
        strip->show();
        rainbow = false;
    }
    case IRcode::CIEMNIEJ:
    {
        strip->setBrightness(strip->getBrightness()-10);
        strip->show();
        rainbow = false;
    }
    break;
    case IRcode::W:
    {
        setFullColor("FFFFFF");
        rainbow = false;
    }
    break;
    case IRcode::R:
    {
        setFullColor("FF0000");
        rainbow = false;
    }
    break;

    case IRcode::G:
    {
        setFullColor("00FF00");
        rainbow = false;
    }
    break;

    case IRcode::B:
    {
        setFullColor("0000FF");
        rainbow = false;
    }
    break;

    case IRcode::C1:
    {
        setFullColor("FF0F00");
        rainbow = false;
    }
    break;

    case IRcode::C2:
    {
        setFullColor("05FF05");
        rainbow = false;
    }
    break;

    case IRcode::C3:
    {
        setFullColor("0A0AFF");
        rainbow = false;
    }
    break;

    case IRcode::C4:
    {
        setFullColor("FF1464");
        rainbow = false;
    }
    break;

    case IRcode::C5:
    {
        setFullColor("FF1600");
        rainbow = false;
    }
    break;

    case IRcode::C6:
    {
        setFullColor("5959FF");
        rainbow = false;
    }
    break;

    case IRcode::C7:
    {
        setFullColor("B300FF");
        rainbow = false;
    }
    break;

    case IRcode::C8:
    {
        setFullColor("FF3277");
        rainbow = false;
    }
    break;

    case IRcode::C9:
    {
        setFullColor("FF2600");
        rainbow = false;
    }
    break;

    case IRcode::C10:
    {
        setFullColor("004F00");
        rainbow = false;
    }
    break;

    case IRcode::C11:
    {
        setFullColor("B300CF");
        rainbow = false;
    }
    break;

    case IRcode::C12:
    {
        setFullColor("4949FF");
        rainbow = false;
    }
    break;

    case IRcode::C13:
    {
        setFullColor("FF6600");
        rainbow = false;
    }
    break;

    case IRcode::C14:
    {
        setFullColor("001F00");
        rainbow = false;
    }
    break;

    case IRcode::C15:
    {
        setFullColor("E600FF");
        rainbow = false;
    }
    break;

    case IRcode::C16:
    {
        setFullColor("6969FF");
        rainbow = false;
    }
    default:
        break;
    }
}