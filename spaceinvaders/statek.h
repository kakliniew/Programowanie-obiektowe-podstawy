#ifndef STATEK_H_INCLUDED
#define STATEK_H_INCLUDED
#include <string.h>
#include "runda.h"
class Runda;
class Statek
{
public:
    int x,y;
    int zycie;
    int punkty;
    char strzal;
    char symbol;

public:
   Statek(int=18, int=15, int=3, int=0,char='*',char='H');
    ~Statek();
    int poruszanie_lewo();
    int poruszanie_prawo();
    friend void edytowanie_gry(int numer_rundy,Runda runda_nr[],Statek &statek1,bool &koniec1);

};

#endif // STATEK_H_INCLUDED
