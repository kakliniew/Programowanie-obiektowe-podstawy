#include "runda.h"
#include "przeciwnik1.h"
#include "przeciwnik2.h"
#include "statek.h"

int Runda::l_rund=0;

Runda::Runda(int cza,int prze)
{   l_rund++;
    czas=cza;
    l_przeciwnikow=prze;
};

Runda::~Runda()
{
 l_rund--;
 l_przeciwnikow=0;
};


