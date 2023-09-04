/*
  16726725 - jasniej
  16759365 - ciemniej
  16745085 - pauza/play
  16712445 - wylacz

  16718565 - R
  16751205 - G
  16753245 - B
  16720605 - W

  16752645
  16755285
  16749165
  16716525

  16714485
  16747125
  16757325
  16754685

  16726215
  16758855
  16742535
  16775175

  16718055
  16750695
  16734375
  16767015

  16722135 - R+
  16754775 - G+
  16738455 - B+
  16771095 - QUICK

  16713975 - R-
  16746615 - G-
  16730295 - B-
  16762935 - SLOW

  16724157 - DIY1
  16756815 - DIY2
  16740495 - DIY3
  16773135 - AUTO

  16716015 - DIY4
  16748655 - DIY5
  16732335 - DIY6
  16764957 - FLASH

  16720095 - JUMP 3
  16752735 - JUMP 7
  16796415 - FADE 3
  16769055 - FADE 7
*/
#include <IRremote.h>

#if !defined(IRcode_h)
#define IRcode_h

class IRcode
{
public:
  enum kodIR
  {
    NIC = 0,
    POWTORZ = 16777215,

    JASNIEJ = 16726725,
    CIEMNIEJ = 16759365,
    PAUZA_PLAY = 16745085,
    WYL = 16712445,

    R = 16718565,
    G = 16751205,
    B = 16753245,
    W = 16720605,

    C1 = 16722645,
    C2 = 16755285,
    C3 = 16749165,
    C4 = 16716525,

    C5 = 16714485,
    C6 = 16747125,
    C7 = 16757325,
    C8 = 16724685,

    C9 = 16726215,
    C10 = 16758855,
    C11 = 16742535,
    C12 = 16775175,

    C13 = 16718055,
    C14 = 16750695,
    C15 = 16734375,
    C16 = 16767015,

    RPLUS = 16722135,
    GPLUS = 16754775,
    BPLUS = 16738455,
    QUICK = 16771095,

    RMINUS = 16713975,
    GMINUS = 16746615,
    BMINUS = 16730295,
    SLOW = 16762935,

    DIY1 = 16724175,
    DIY2 = 16756815,
    DIY3 = 16740495,
    AUTO = 16773135,

    DIY4 = 16716015,
    DIY5 = 16748655,
    DIY6 = 16732335,
    FLASH = 16764957,

    JUMP3 = 16720095,
    JUMP7 = 16752735,
    FADE3 = 16736415,
    FADE7 = 16769055
  };

public:
  IRcode(byte t = 2) : ir(t), val(NIC){};
  void init()
  {
    ir.enableIRIn();
    read();
  };

  kodIR read()
  {
    decode_results odczyt;
    //kodIR val;
    if (ir.decode(&odczyt))
    { // sprawdza, czy otrzymano sygnał IR
      ir.resume();
      Serial.println(odczyt.value);
      switch (odczyt.value)
      {
      case POWTORZ:
        return POWTORZ;
        break;
      case JASNIEJ:
        return JASNIEJ;
        break;
      case CIEMNIEJ:
        return CIEMNIEJ;
        break;
      case PAUZA_PLAY:
        return PAUZA_PLAY;
        break;
      case WYL:
        return WYL;
        break;
      case R:
        return R;
        break;
      case G:
        return G;
        break;
      case B:
        return B;
        break;
      case W:
        return W;
        break;
      case C1:
        //Serial.println("C1");
        return C1;
        break;
      case C2:
        //Serial.println("C2");
        return C2;
        break;
      case C3:
        // Serial.println("C3");
        return C3;
        break;
      case C4:
        //Serial.println("C4");
        return C4;
        break;
      case C5:
        //Serial.println("C5");
        return C5;
        break;
      case C6:
        //Serial.println("C6");
        return C6;
        break;
      case C7:
        //Serial.println("C7");
        return C7;
        break;
      case C8:
        //Serial.println("C8");
        return C8;
        break;
      case C9:
        //Serial.println("C9");
        return C9;
        break;
      case C10:
        //Serial.println("C10");
        return C10;
        break;
      case C11:
        //Serial.println("C11");
        return C11;
        break;
      case C12:
        //Serial.println("C12");
        return C12;
        break;
      case C13:
        //Serial.println("C13");
        return C13;
        break;
      case C14:
        //Serial.println("C14");
        return C14;
        break;
      case C15:
        //Serial.println("C15");
        return C15;
        break;
      case C16:
        //Serial.println("C16");
        return C16;
        break;
      case RPLUS:
        return RPLUS;
        break;
      case GPLUS:
        return GPLUS;
        break;
      case BPLUS:
        return BPLUS;
        break;
      case QUICK:
        return QUICK;
        break;
      case RMINUS:
        return RMINUS;
        break;
      case GMINUS:
        return GMINUS;
        break;
      case BMINUS:
        return BMINUS;
        break;
      case SLOW:
        return SLOW;
        break;
      case DIY1:
        return DIY1;
        break;
      case DIY2:
        return DIY2;
        break;
      case DIY3:
        return DIY3;
        break;
      case AUTO:
        return AUTO;
        break;
      case DIY4:
        return DIY4;
        break;
      case DIY5:
        return DIY5;
        break;
      case DIY6:
        return DIY6;
        break;
      case FLASH:
        return FLASH;
        break;
      case JUMP3:
        return JUMP3;
        break;
      case JUMP7:
        return JUMP7;
        break;
      case FADE3:
        return FADE3;
        break;
      case FADE7:
        return FADE7;
        break;
      default:
        return NIC;
        break;
      }
    }
    return (NIC);
  }
  IRrecv ir;
  kodIR val;
  void operator()()
  {
    val = read();
    // switch (val=read()){
    // case POWTORZ:
    //   // return POWTORZ;
    //   break;
    // case JASNIEJ:
    //   // return JASNIEJ;
    //   break;
    // case CIEMNIEJ:
    //   // return CIEMNIEJ;
    //   break;
    // case PAUZA_PLAY:
    //   // return PAUZA_PLAY;
    //   break;
    // case WYL:
    //   // return WYL;
    //   break;
    // case R:
    //   // return R;
    //   break;
    // case B:
    //   // return B;
    //   break;
    // case W:
    //   // return W;
    //   break;
    // case C1:
    //   // return C1;
    //   break;
    // case C2:
    //   // return C2;
    //   break;
    // case C3:
    //   // return C3;
    //   break;
    // case C4:
    //   // return C4;
    //   break;
    // case C5:
    //   // return C5;
    //   break;
    // case C6:
    //   // return C6;
    //   break;
    // case C7:
    //   // return C7;
    //   break;
    // case C8:
    //   // return C8;
    //   break;
    // case C9:
    //   // return C9;
    //   break;
    // case C10:
    //   // return C10;
    //   break;
    // case C11:
    //   // return C11;
    //   break;
    // case C12:
    //   // return C12;
    //   break;
    // case C13:
    //   // return C14;
    //   break;
    // case C15:
    //   // return C15;
    //   break;
    // case C16:
    //   // return C16;
    //   break;
    // case RPLUS:
    //   // return RPLUS;
    //   break;
    // case GPLUS:
    //   // return GPLUS;
    //   break;
    // case BPLUS:
    //   // return BPLUS;
    //   break;
    // case QUICK:
    //   // return QUICK;
    //   break;
    // case RMINUS:
    //   // return RMINUS;
    //   break;
    // case GMINUS:
    //   // return GMINUS;
    //   break;
    // case BMINUS:
    //   // return BMINUS;
    //   break;
    // case SLOW:
    //   // return SLOW;
    //   break;
    // case DIY1:
    //   // return DIY1;
    //   break;
    // case DIY2:
    //   // return DIY2;
    //   break;
    // case DIY3:
    //   // return DIY3;
    //   break;
    // case AUTO:
    //   // return AUTO;
    //   break;
    // case DIY4:
    //   // return DIY4;
    //   break;
    // case DIY5:
    //   // return DIY5;
    //   break;
    // case DIY6:
    //   // return DIY6;
    //   break;
    // case FLASH:
    //   // return FLASH;
    //   break;
    // case JUMP3:
    //   // return JUMP3;
    //   break;
    // case JUMP7:
    //   // return JUMP7;
    //   break;
    // case FADE3:
    //   // return FADE3;
    //   break;
    // case FADE7:
    //   // return FADE7;
    //   break;
    // default:
    //   // return NIC;
    //   break;
    // }
  }
  kodIR get() { return val; }

private:
};

#endif // IRremote_h
