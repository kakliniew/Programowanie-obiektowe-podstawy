#include <iostream>
#include <cstring>
#include "osoba.h"

using namespace std;

void Osoba::wypozyczenie()
{
    cout<<"Podaj imie osoby"<<endl;
    cin>>imie;
    cout<<"Podaj nazwisko osoby"<<endl;
    cin>>nazwisko;

    for(int i=0;i<2;i++)
    {
        spis_ksiazek[i].wczytaj_dane();


    }
}


Osoba::Osoba(string imi, string naz)

{
        imie=imi;
        nazwisko=naz;
        cout<<"Konstruktor osoby"<<endl;
}

void Osoba::wypisz_dane()
{
    cout<<"Imie osoby "<<imie<<endl;
    cout<<"Nazwisko osoby "<<nazwisko<<endl;

    for(int i=0;i<2;i++)
    {
        spis_ksiazek[i].wypisz_dane();
        cout<<endl;
    }


}

Osoba::~Osoba()
{
    cout<<"Destruktor osoby tu by³"<<endl;
}




