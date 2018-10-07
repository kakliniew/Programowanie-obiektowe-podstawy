#ifndef RUNDA_H_INCLUDED
#define RUNDA_H_INCLUDED

#include "statek.h"
#include "przeciwnik.h"
#include "przeciwnik1.h"
#include "przeciwnik2.h"

class Statek;
class Runda
{
public:

   Przeciwnik1 p1[12];
   Przeciwnik2 p2[20];
   int czas;
   int l_przeciwnikow;
   static int l_rund;

   Runda(int=30,int=10);
   ~Runda();
   friend void edytowanie_gry(int numer_rundy,Runda runda_nr[],Statek &statek1,bool &koniec1);


};


#endif // RUNDA_H_INCLUDED
