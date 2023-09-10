#include "IRControl.h"

IRControl::IRControl(int pin)
{
    IrReceiver.begin(pin);
}

IRControl::~IRControl()
{
    IrReceiver.end();
}

IRControlCode IRControl::tick()
{
    if (IrReceiver.decode()) {
        Serial.print("IR HEX: ");
        Serial.println(IrReceiver.decodedIRData.decodedRawData);
        IrReceiver.resume();

        return (IRControlCode)IrReceiver.decodedIRData.decodedRawData; //TODO: return proper value
    }
    else{
        return IRControlCode::NIC;
    }
}
