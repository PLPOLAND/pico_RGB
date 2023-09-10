#ifndef IRRemoteCode_h
#define IRRemoteCode_h

// enum IRConrolCodeOld
// {
//     NIC = 0,
//     POWTORZ = 16777215,

//     JASNIEJ = 16726725,
//     CIEMNIEJ = 16759365,
//     PAUZA_PLAY = 16745085,
//     WYL = 16712445,

//     R = 16718565,
//     G = 16751205,
//     B = 16753245,
//     W = 16720605,

//     C1 = 16722645,
//     C2 = 16755285,
//     C3 = 16749165,
//     C4 = 16716525,

//     C5 = 16714485,
//     C6 = 16747125,
//     C7 = 16757325,
//     C8 = 16724685,

//     C9 = 16726215,
//     C10 = 16758855,
//     C11 = 16742535,
//     C12 = 16775175,

//     C13 = 16718055,
//     C14 = 16750695,
//     C15 = 16734375,
//     C16 = 16767015,

//     RPLUS = 16722135,
//     GPLUS = 16754775,
//     BPLUS = 16738455,
//     QUICK = 16771095,

//     RMINUS = 16713975,
//     GMINUS = 16746615,
//     BMINUS = 16730295,
//     SLOW = 16762935,

//     DIY1 = 16724175,
//     DIY2 = 16756815,
//     DIY3 = 16740495,
//     AUTO = 16773135,

//     DIY4 = 16716015,
//     DIY5 = 16748655,
//     DIY6 = 16732335,
//     FLASH = 16764957,

//     JUMP3 = 16720095,
//     JUMP7 = 16752735,
//     FADE3 = 16736415,
//     FADE7 = 16769055
// };
enum IRControlCode
{
    NIC = 0,
    POWTORZ = 16777215,

    JASNIEJ = 2740780800,
    CIEMNIEJ = 2724069120,
    PAUZA_PLAY = 3191996160,
    WYL = 3208707840,

    R = 2807627520,
    G = 2790915840,
    B = 3125149440,
    W = 3141861120,

    C1 = 2874474240,
    C2 = 2857762560,
    C3 = 3058302720,
    C4 = 3075014400,

    C5 = 2941320960,
    C6 = 2924609280,
    C7 = 2991456000,
    C8 = 3008167680,

    C9 = 3810328320,
    C10 = 3793616640,
    C11 = 3776904960,
    C12 = 3760193280,

    C13 = 3877175040,
    C14 = 3860463360,
    C15 = 3843751680,
    C16 = 3827040000,

    RPLUS = 3944021760,
    GPLUS = 3927310080,
    BPLUS = 3910598400,
    QUICK = 3893886720,

    RMINUS = 4010868480,
    GMINUS = 3994156800,
    BMINUS = 3977445120,
    SLOW = 3960733440,

    DIY1 = 4077715200,
    DIY2 = 4061003520,
    DIY3 = 4044291840,
    AUTO = 4027580160,

    DIY4 = 4144561920,
    DIY5 = 4127850240,
    DIY6 = 4111138560,
    FLASH = 4094426880,

    JUMP3 = 4211408640,
    JUMP7 = 4194696960,
    FADE3 = 4177985280,
    FADE7 = 4161273600
};


#endif