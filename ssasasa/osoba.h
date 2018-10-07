#ifndef OSOBA_H_INCLUDED
#define OSOBA_H_INCLUDED

#include <iostream>
#include <cstring>
#include "ksiazka.h"


using namespace std;


class Osoba
{
	Ksiazka spis_ksiazek[3];
	string imie;
	string nazwisko;


    void wypisz_dane();

	public:
    void wypozyczenie();
    //void wypisz_dane();   //zakryte,przerzucone do prywatnych w celu zastosowania funkcji zaprzyjaznionej
    Osoba(string="Imie", string="Nazwisko");
    ~Osoba();
    static void wypisz_licznik();
    friend void wyswietlenie_ksiazek(Osoba o);
    friend Osoba operator+(Osoba a, Ksiazka b);

};



#endif // OSOBA_H_INCLUDED

