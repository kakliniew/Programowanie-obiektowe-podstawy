#include <iostream>
#include <cstring>
#include "ksiazka.h"

using namespace std;


void Ksiazka::wczytaj_dane()
    {
        cout<<"Podaj imie autora ksiazki"<<endl;
        cin>>imie_autora;
        cout<<"Podaj nazwisko autora ksiazki"<<endl;
        cin>>nazwisko_autora;
        cout<<"Podaj tytul ksiazki"<<endl;
        cin>>tytul;
        cout<<"Podaj rok wydania"<<endl;
        cin>>rok_wydania;
        cout<<"Podaj nr wydania"<<endl;
        cin>>nr_wydania;

    }


    void Ksiazka::wypisz_dane()
    {
        cout<<"Podana ksiazka to: "<<tytul<<endl;
        cout<<"Autor: "<<imie_autora<<" "<<nazwisko_autora<<endl;
        cout<<"Wydana w: "<<rok_wydania<<endl;
        cout<<"Numer wydania to: "<<nr_wydania<<endl;
    }

 int Ksiazka::licznik;
    Ksiazka::Ksiazka(string im, string na, string ty, string r, string nr)
    {
        imie_autora=im;
        nazwisko_autora=na;
        tytul=ty;
        rok_wydania=r;
        nr_wydania=nr;
        licznik++;
        cout<<"Konstruktor ksiazki"<<endl;


    }
    Ksiazka::~Ksiazka()
    {
        cout<<"Destruktor ksiazki tu byl!"<<endl;
    }

    Ksiazka::Ksiazka(const Ksiazka & WKsiazka) //konstruktor kopiujacy
    {
    imie_autora=WKsiazka.imie_autora;
	nazwisko_autora=WKsiazka.nazwisko_autora;
	tytul=WKsiazka.tytul;
	rok_wydania=WKsiazka.rok_wydania;
	nr_wydania=WKsiazka.nr_wydania;
	strcpy(notatka,"konstruktor kopiujacy");
	cout<<"Konstruktor kopiujacy ksiazki"<<endl;


    }

    void Ksiazka::wypisz_licznik()
{
    cout<<"Liczba ksiazek= "<<licznik<<endl;
}

Ksiazka & Ksiazka::operator=(const Ksiazka &wzor)
{

	if(&wzor == this) return *this;



	delete dostep;


	imie_autora=wzor.imie_autora;
	nazwisko_autora=wzor.nazwisko_autora;
	tytul=wzor.tytul;
	rok_wydania=wzor.rok_wydania;
	nr_wydania=wzor.nr_wydania;


	cout << " (Pracuje operator= czyli operator przypisania)\n" ;
	return *this ;
}
