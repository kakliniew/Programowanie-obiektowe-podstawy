#ifndef PRZECIWNIK2_H_INCLUDED
#define PRZECIWNIK2_H_INCLUDED
#include "przeciwnik.h"

class Przeciwnik1;

class Przeciwnik2 :public Przeciwnik
{
    public:
    char symbol;
    int zycie;

public:
    //virtual void oberwal();
    Przeciwnik2(int=1, int=1, int=2,char='@');
  ~Przeciwnik2();
   Przeciwnik2 operator=(Przeciwnik1 a);

};


#endif // PRZECIWNIK2_H_INCLUDED
