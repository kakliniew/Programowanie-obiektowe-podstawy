#include "przeciwnik2.h"
#include "przeciwnik1.h"

Przeciwnik2::Przeciwnik2(int pox,int poy,int zyci,char znak)
:Przeciwnik(pox,poy)
{
  symbol=znak;
  zycie=zyci;
}


Przeciwnik2::~Przeciwnik2()
{
 zycie=0;
 symbol=' ';

}


Przeciwnik2 Przeciwnik2::operator=(Przeciwnik1 a)
{
    symbol=a.symbol;
    zycie=a.zycie;

}
