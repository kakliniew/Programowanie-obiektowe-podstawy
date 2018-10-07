#ifndef KSIAZKA_H_INCLUDED
#define KSIAZKA_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

class Osoba;

class Ksiazka
{
	string imie_autora;
	string nazwisko_autora;
	string tytul;
	string rok_wydania;
	string nr_wydania;
    char notatka[20];
    string *dostep;
    static int licznik;



public: 																	//
	void wczytaj_dane();
    void wypisz_dane();
    Ksiazka(string="imie", string="Nazwisko", string="tytul", string="Rok", string="nr wydania");
   ~Ksiazka();
    Ksiazka(const Ksiazka & WKsiazka);//kontruktor kopiujacy
    static void wypisz_licznik();
    Ksiazka & operator=(const Ksiazka &wzor);
    friend Osoba operator+(Osoba a, Ksiazka b);
};



#endif // KSIAZKA_H_INCLUDED
