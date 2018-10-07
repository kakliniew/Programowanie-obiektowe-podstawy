#include <iostream>  // wejscie wyjscie standardowe
#include "runda.h"
#include "statek.h"
#include "przeciwnik.h"
#include "przeciwnik1.h"
#include "przeciwnik2.h"
#include <windows.h> //od sleep
#include <cstdlib> //czyszczenie
#include <conio.h>  //getch
#include <string>
#include <cstdlib>  //rand();


using namespace std;

void gotoxy(int x, int y) {  //Funkcja pozycjonuj¹c kursor. Mo¿na zamiast niej u¿yæ po prostu "system("cls")" ale to powoduje miganie konsoli i liczne bugi
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int lot_pociskow(string tab[])  //oraz liczenie ilosc przeciwnikow
{ int ilosc=0;
    for(int i=1;i<20;i++)
        {
            for(int j=1;j<30;j++)
            {
                if(tab[i][j]=='.')
                {
                    if(tab[i-1][j]==' '){     //przemieszczanie kropki
                            tab[i-1][j]='.';
                            tab[i][j]=' ';
                    }
                    else if (tab[i-1][j]=='@' || tab[i-1][j]=='#')
                        {
                            tab[i][j]=' ';
                        }
                        else tab[i][j]=' ';

                }  //koniec lotu strzalu


                if(tab[i][j]=='@' || tab[i][j]=='#')  // liczenie pozostalych przeciwnikow
                {
                    ilosc++;
                }

            }
        }

         for(int i=19;i>0;i--)   // przemieszcznanie ataku wroga
        {
            for(int j=29;j>0;j--)
            {

                if(tab[i][j]==',')  // pocisk przeciwnikow
                {
                     if(tab[i+1][j] ==' ')// ' ' -> przemieszcza
                     {
                         tab[i+1][j]=',';
                         tab[i][j]=' ';
                     }
                     else if (tab[i+1][j]=='@' || tab[i+1][j]=='#')  // $ @  -> omija
                    {
                        tab[i+2][j]=',';
                        tab[i][j]=' ';
                    }
                    else tab[i][j]=' ';


                }
            }
        }
        return ilosc;
}


void edytowanie_gry(int numer_rundy,Runda runda_nr[],Statek &statek1,bool &koniec1)

{   system("cls");
    int numer;
    int pomocnicza;
    cout<<"Co chcesz zmienic? "<<endl;
    cout<<"1. Zycie przeciwnikow slabszych "<<endl;
    cout<<"2. Zycie przeciwnikow mocniejszych "<<endl;
    cout<<"3. Czas rundy"<<endl;
    cout<<"4. Moje zycie"<<endl;
    cout<<"5. Swiat"<<endl;
    cout<<"6. Koniec gry"<<endl;
    cin>>numer;

    switch(numer)
    {
        case 1:
                {       cout<<"Podaj ile hp ma miec przeciwnik " <<endl;
                        cin>>pomocnicza;

                        for(int i=0;i<12;i++)
                                {
                                runda_nr[numer_rundy-1].p1[i].zycie=pomocnicza;
                                } };break;

        case 2: {       cout<<"Podaj ile hp ma miec przeciwnik " <<endl;
                        cin>>pomocnicza;

                        for(int i=0;i<20;i++)
                            {
                            runda_nr[numer_rundy-1].p2[i].zycie=pomocnicza;
                            } };break;


        case 3:{
                        cout<<"Podaj jaki czas chcesz ustawic " <<endl;
                        cin>>pomocnicza;
                        runda_nr[numer_rundy-1].czas=pomocnicza;
                        };break;

        case 4:{
                        cout<<"Ile zycia chcesz miec? " <<endl;
                        cin>>pomocnicza;
                        statek1.zycie=pomocnicza;
                        };break;

        case 5:{
                        cout<<"Tez chcialbym zmienic swiat, ale nie jest to takie latwe :(  " <<endl;
                        getch();

                        };break;

        case 6: { koniec1 = true;};break;


    }

    system("cls");

}


int main()
{

    bool koniec=false;
    bool ladowanie_rundy=true;
    Runda r[2];
    int klikniecia=0;

    Statek s1;
    int losowa;
    int pomoc=1;
    int nr_rundy=1;
    string imie;
    cout<<"####################"<<endl;
    cout<<"#  SPACE INVADERS  #"<<endl;
    cout<<"#  BY KAROL K 1.1  #"<<endl;
    cout<<"####################"<<endl;
    cout<<"Aby kontynuowac wcisnij klawisz"<<endl;
    getch();
    system("cls");
    cout<<"Podaj swoje imie i wcisnij ENTER, po tym gra wystartuje, przygotuj sie!"<<endl;
    cin>>imie;

    system("cls");


    string wyswietlacz[30]=
                            {
                            "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$                            $",
                            "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
                            };


    while(!koniec)
    {   gotoxy(1, 1);

        if(ladowanie_rundy)
        {
            switch(nr_rundy)
            {
                case 1: {
                            r[0].czas=20;
                            r[0].l_przeciwnikow=22;
                            wyswietlacz[s1.x][s1.y]=s1.symbol;

                            for(int i=0;i<12;i++)
                                {
                                r[0].p1[i].x=3;
                                r[0].p1[i].y=3+2*i;
                                wyswietlacz[r[0].p1[i].x][r[0].p1[i].y]=r[0].p1[i].symbol;
                                }

                                for(int i=0;i<10;i++)
                                {
                                r[0].p2[i].x=5;
                                r[0].p2[i].y=5+2*i;
                                wyswietlacz[r[0].p2[i].x][r[0].p2[i].y]=r[0].p2[i].symbol;
                                }

                            }; break;

                case 2:
                        {
                            r[1].czas=25;
                            r[1].l_przeciwnikow=30;
                            wyswietlacz[s1.x][s1.y]=s1.symbol;

                            for(int i=0;i<12;i++)
                                {
                                r[1].p1[i].x=3;
                                r[1].p1[i].y=3+2*i;
                                wyswietlacz[r[1].p1[i].x][r[1].p1[i].y]=r[1].p1[i].symbol;
                                }

                                for(int i=0;i<10;i++)
                                {
                                r[1].p2[i].x=5;
                                r[1].p2[i].y=5+2*i;
                                wyswietlacz[r[1].p2[i].x][r[1].p2[i].y]=r[1].p2[i].symbol;
                                }

                                for(int i=10;i<18;i++)
                                {
                                r[1].p2[i].x=7;
                                r[1].p2[i].y=7+2*(i-10);
                                wyswietlacz[r[1].p2[i].x][r[1].p2[i].y]=r[1].p2[i].symbol;
                                }

                            }; break;

 //gra stan deweloperski

                }




            ladowanie_rundy=false;
        }




        if(s1.zycie>0 && r[nr_rundy-1].l_przeciwnikow>0 && nr_rundy<=Runda::l_rund && r[nr_rundy-1].czas>0)
        {

             r[nr_rundy-1].l_przeciwnikow=lot_pociskow(wyswietlacz);
                losowa=rand();
                cout<<"Zmienna losowa: "<<losowa%10<<endl;
                 cout<<"Zmienna pomocnicza: "<<pomoc<<endl;
                 cout<<"Ilosc zyc: "<<s1.zycie<<endl;
                cout<<"Czas: "<<r[nr_rundy-1].czas<<endl;
                for(int i=0;i<20;i++)
                {
                cout<<wyswietlacz[i]<<endl;
                }
        /////////////////////////////////////////////////////////////
          if(kbhit()!=0)  {
              unsigned char znak = getch();
                switch( znak )
                {
                case 0: //klawisze specjalne (czasem zero czasem 224 - zale¿ne od pc'ta chyba)
                case 224: //klawisze specjalne
                    znak = getch();
                    switch( znak )
                    {


                    case 75:   //strzalka lewo
                        {
                                wyswietlacz[s1.x][s1.y]=' ';
                                wyswietlacz[s1.x][s1.poruszanie_lewo()]=s1.symbol;
                                klikniecia++;

                        }
                        break;
                    case 77:   // strzalka prawo
                            {
                                wyswietlacz[s1.x][s1.y]=' ';
                                wyswietlacz[s1.x][s1.poruszanie_prawo()]=s1.symbol;
                                klikniecia++;
                            }
                        break;
                    }
                    znak = 0;
                    break;
                case 13: //ENTER

                    break;
                case 32: //spacja
                   {

                    wyswietlacz[s1.x-1][s1.y]='.';
                    klikniecia++;
                   }
                   break;
                case 27: //ESC
                    //koniec = true;
                    edytowanie_gry(nr_rundy,r,s1,koniec);
                    break;
                }
          }
        //////////////////////////////// sterowanie


             // lot_pociskow(wyswietlacz);
                for(int i=0;i<12;i++)   // zabieranie hp jak pocisk trafi, niszczenie obiektu ewentualne p1
                {
                    if(wyswietlacz[r[nr_rundy-1].p1[i].x+1][r[nr_rundy-1].p1[i].y]=='.') r[nr_rundy-1].p1[i].zycie--;
                    if( r[nr_rundy-1].p1[i].zycie==0){ wyswietlacz[r[nr_rundy-1].p1[i].x][r[nr_rundy-1].p1[i].y]=' ';
                                            wyswietlacz[r[nr_rundy-1].p1[i].x+1][r[nr_rundy-1].p1[i].y]=' ';
                                           ;
                                            }




                }

                for(int i=0;i<18;i++)   // zabieranie hp jak pocisk trafi, niszczenie obiektu ewentualne p2
                {
                    if(wyswietlacz[r[nr_rundy-1].p2[i].x+1][r[nr_rundy-1].p2[i].y]=='.') r[nr_rundy-1].p2[i].zycie--;
                    if( r[nr_rundy-1].p2[i].zycie==0){
                    wyswietlacz[r[nr_rundy-1].p2[i].x+1][r[nr_rundy-1].p2[i].y]=' ';
                    wyswietlacz[r[nr_rundy-1].p2[i].x][r[nr_rundy-1].p2[i].y]=' ';

                    }

                }

                  if(pomoc==25)
                   {  if( r[nr_rundy-1].p1[losowa%12].zycie>0)
                       wyswietlacz[r[nr_rundy-1].p1[losowa%12].x+1][r[nr_rundy-1].p1[losowa%12].y]=',';

                   }


                   if(pomoc==2)
                   {    if( r[nr_rundy-1].p2[losowa%(10+(nr_rundy-1)*8)].zycie>0)
                       wyswietlacz[r[nr_rundy-1].p2[losowa%(10+(nr_rundy-1)*8)].x+1][r[nr_rundy-1].p2[losowa%(10+(nr_rundy-1)*8)].y]=',';

                   }


                //////
                if(wyswietlacz[s1.x-1][s1.y]==',' )s1.zycie--;
                pomoc++;
                pomoc=pomoc%30;
                if(pomoc==2)r[nr_rundy-1].czas--;


              //  r[nr_rundy-1].l_przeciwnikow=lot_pociskow(wyswietlacz);


                //gotoxy(1, 1);
               // cout<<r1.l_przeciwnikow<<endl;

                Sleep(50);
        }  // koniec if

        if(s1.zycie>0 && r[nr_rundy-1].l_przeciwnikow==0 && nr_rundy< Runda::l_rund  && r[nr_rundy-1].czas>0)
        {    gotoxy(1, 10);

            nr_rundy++;
               cout<<"$     Nastepny poziom: "<<nr_rundy<<endl;
               cout<<"$ Wcisnij klawisz, aby start"<<endl;
               getch();
            ladowanie_rundy=true;


        }

        if( s1.zycie>0 && r[nr_rundy-1].l_przeciwnikow==0 && nr_rundy==Runda::l_rund  && r[nr_rundy-1].czas>0)
        {
            gotoxy(1, 10);
                cout<<"$    Przeszedles gre "<<endl;
                cout<<"$    Gratulacje "<<imie<<endl;
                cout<<"$    Kliknij KLAWISZ"<<endl;
                cout<<"$    aby zobaczyc statystyki"<<endl;
               getch();
               gotoxy(1, 1);
               system("cls");
               cout<<"!!Statystyki!!"<<endl;
               cout<<"Podane imie: "<<imie<<endl;
               cout<<"Ilosc klikniec sterowania: "<<klikniecia<<endl;
               cout<<"Zabite stwory: " <<52<<endl;
               cout<<"Skonczone mapy: "<<nr_rundy<<endl;
               cout<<endl<<"Kliknij, aby zakonczyc"<<endl;

               getch();
               koniec = true;
        }

        if( s1.zycie==0 || r[nr_rundy-1].czas==0)
        {
            gotoxy(1, 10);
                cout<<"$    Przegrales  "<<endl;
                cout<<"$    :( "<<imie<<endl;
                cout<<"$    Kliknij KLAWISZ"<<endl;
                cout<<"$    aby zobaczyc statystyki"<<endl;
               getch();
               gotoxy(1, 1);
               system("cls");
               cout<<"!!Statystyki!!"<<endl;
               cout<<"Podane imie: "<<imie<<endl;
               cout<<"Ilosc klikniec sterowania: "<<klikniecia<<endl;
               cout<<"Zabite stwory: " <<(nr_rundy+1)%2*22+30-r[nr_rundy-1].l_przeciwnikow<<endl;
               cout<<"Skonczone mapy: "<<nr_rundy-1<<endl;
               cout<<endl<<"Kliknij, aby zakonczyc"<<endl;

               getch();
               koniec = true;
        }




    } // koniec gry
    cout<<"KONIEC GRY!"<<endl;
    return 0;
}
