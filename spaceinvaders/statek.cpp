#include "statek.h"

Statek::Statek(int pozx, int pozy, int zyc, int punk,char strz,char sym)
{
    x=pozx;
    y=pozy;
    zycie=zyc;
    punkty=punk;
    strzal=strz;
    symbol=sym;
};

Statek::~Statek()
{
    //pusto
};

int Statek::poruszanie_lewo()
{
    if(y>1) y--;
    return y;
};

int Statek::poruszanie_prawo()
{
    if(y<28)y++;

    return y;
};

