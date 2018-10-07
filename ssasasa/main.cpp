#include <iostream>
#include <cstring>
#include "ksiazka.h"
#include "osoba.h"

using namespace std;

void wyswietlenie_ksiazek(Osoba o)  // funkcja wypisujaca ksiazki danej osoby, podobna do wypisz_dane();
{
    cout<<"Ksiazki "<<o.imie<<" "<<o.nazwisko<<" to:" <<endl;

    for(int i=0;i<2;i++)
    {
        o.spis_ksiazek[i].wypisz_dane();

    }

}

 Osoba operator+(Osoba a, Ksiazka b)
{
    b.imie_autora=a.spis_ksiazek[1].imie_autora;
	b.nazwisko_autora=a.spis_ksiazek[1].nazwisko_autora;
	b.tytul=a.spis_ksiazek[1].tytul;
	b.rok_wydania=a.spis_ksiazek[1].rok_wydania;
	b.nr_wydania=a.spis_ksiazek[1].nr_wydania;

    return a;
}

int main()
{
    Osoba o1[2];  //Stworzona osoba ma ustawione standardowo 2 ksiazki

    for(int i=0;i<2;i++)
    {
            //o1[i].wypozyczenie();
           // o1[i].Osoba::wypisz_dane();
    }

    Ksiazka::wypisz_licznik();

    cout<<"wyswietlenie ksiazek osoby drugiej: "<<endl;
     cout<<"----------------------------------"<<endl;

    wyswietlenie_ksiazek(o1[1]);

	return 0;
}
