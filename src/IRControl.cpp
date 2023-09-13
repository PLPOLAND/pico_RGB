#include "IRControl.h"

IRControl::IRControl(int pin)
{
    IrReceiver.begin(pin);
}

IRControl::~IRControl()
{
    IrReceiver.end();
}

Task* IRControl::tick()
{
    if (IrReceiver.decode()) {
        Serial.print("IR HEX: ");
        Serial.println(IrReceiver.decodedIRData.decodedRawData);
        IrReceiver.resume();
        switch ((IRControlCode)IrReceiver.decodedIRData.decodedRawData)
        {
        case WYL:
            return Task::OnOff();
            break;
        case AUTO:
            return Task::Rainbow();
            break;
        case DIY1:
            return Task::DIY1();
            break;
        case DIY2:
            return Task::DIY2();
            break;
        case DIY3:
            return Task::DIY3();
            break;
        case DIY4:
            return Task::DIY4();
            break;
        case DIY5:
            return Task::DIY5();
            break;
        case DIY6:
            return Task::DIY6();
            break;
        case R:
            return Task::ChangeColor(Color::Red());
            break;
        case G:
            return Task::ChangeColor(Color::Green());
            break;
        case B:
            return Task::ChangeColor(Color::Blue());
            break;
        case W:
            return Task::ChangeColor(Color::White());
            break;
        case C1:
            return Task::ChangeColor(Color::C1());
            break;
        case C2:
            return Task::ChangeColor(Color::C2());
            break;
        case C3:
            return Task::ChangeColor(Color::C3());
            break;
        case C4:
            return Task::ChangeColor(Color::C4());
            break;
        case C5:
            return Task::ChangeColor(Color::C5());
            break;
        case C6:
            return Task::ChangeColor(Color::C6());
            break;
        case C7:
            return Task::ChangeColor(Color::C7());
            break;
        case C8:
            return Task::ChangeColor(Color::C8());
            break;
        case C9:
            return Task::ChangeColor(Color::C9());
            break;
        case C10:
            return Task::ChangeColor(Color::C10());
            break;
        case C11:
            return Task::ChangeColor(Color::C11());
            break;
        case C12:
            return Task::ChangeColor(Color::C12());
            break;
        case C13:
            return Task::ChangeColor(Color::C13());
            break;
        case C14:
            return Task::ChangeColor(Color::C14());
            break;
        case C15:
            return Task::ChangeColor(Color::C15());
            break;
        case C16:
            return Task::ChangeColor(Color::C16());
            break;
        case RPLUS:
            return Task::RedUp();
            break;
        case GPLUS:
            return Task::GreenUp();
            break;
        case BPLUS:
            return Task::BlueUp();
            break;
        case QUICK:
            return Task::Quick();
            break;
        case RMINUS:
            return Task::RedDown();
            break;
        case GMINUS:
            return Task::GreenDown();
            break;
        case BMINUS:
            return Task::BlueDown();
            break;
        case SLOW:
            return Task::Slow();
            break;
        case FLASH:
            return Task::Blink();
            break;
        case JUMP3:
            return Task::Jump3();
            break;
        case JUMP7:
            return Task::Jump7();
            break;
        case FADE3:
            return Task::Fade3();
            break;
        case FADE7:
            return Task::Fade7();
            break;
        case JASNIEJ:
            return Task::Brighter();
            break;
        case CIEMNIEJ:
            return Task::Darker();
            break;
        default :
            return nullptr;
            break;
        }
    }
    else{
        return nullptr;
    }
}
