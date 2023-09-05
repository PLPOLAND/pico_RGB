#include "IRDiode.h"

IRDiode::IRDiode(byte pin )
{
    IrReceiver.begin(pin);
}

IRDiode::~IRDiode()
{
    IrReceiver.end();
}

void IRDiode::operator()()
{
    if (IrReceiver.decode()) {
        Serial.print("IR HEX: ");
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
        IrReceiver.resume();
    }
    else{
        // Serial.println("No IR");
    }
}