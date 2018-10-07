#ifndef PRZECIWNIK1_H_INCLUDED
#define PRZECIWNIK1_H_INCLUDED


#include "przeciwnik.h"
class Przeciwnik2;


class Przeciwnik1 :public Przeciwnik
{   public:
        char symbol;
        int zycie;

public:
  // virtual void atak();
  Przeciwnik1(int=1, int=1, int=1,char='#');
  ~Przeciwnik1();
    Przeciwnik1 operator=(Przeciwnik2 a);

};

#endif // PRZECIWNIK1_H_INCLUDED
