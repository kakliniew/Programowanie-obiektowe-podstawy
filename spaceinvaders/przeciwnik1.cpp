#include "przeciwnik1.h"
#include "przeciwnik2.h"
#include <string.h>
Przeciwnik1::Przeciwnik1(int pox,int poy,int zyci,char znak)
:Przeciwnik(pox,poy)
{
  symbol=znak;
  zycie=zyci;
}


Przeciwnik1::~Przeciwnik1()
{
zycie=0;
 symbol=' ';


}

Przeciwnik1 Przeciwnik1::operator=(Przeciwnik2 a)
{
    symbol=a.symbol;
    zycie=a.zycie;

}


