//POP projekt 1 CodeBlocks 17.12 TDM-GCC 5.1.0
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include <cmath>

#define PI 3.14

void litery()
{
    char letter = 'A';

    for (int i = 0; i < 10; i++)
    {
        std::cout << letter << " ";
        letter++;
    }
    std::cout << "  ";

    for (int i = 0; i < 10; i++)
    {
        std::cout << letter << " ";
        letter++;
    }
    std::cout << std::endl;
}

using namespace std;

int main()
{

    while (true)
    {
        //przygotowanie planszy w tabeli

        char tab[100];

        strcpy(tab, "- ");
        for (int i = 0; i < 9; i++)
        {
            strcat(tab, "- ");
        }
        strcat(tab, "| ");
        for (int i = 0; i < 10; i++)
        {
            strcat(tab,"- ");
        }

        srand(time(NULL));


        //Player 1 losowanie pola
        int los1;
        los1 = rand() % 10 + 1;

        switch (los1)
        {
        case 1:
            tab[0] = 'X';
            break;
        case 2:
            tab[2] = 'X';
            break;
        case 3:
            tab[4] = 'X';
            break;
        case 4:
            tab[6] = 'X';
            break;
        case 5:
            tab[8] = 'X';
            break;
        case 6:
            tab[10] = 'X';
            break;
        case 7:
            tab[12] = 'X';
            break;
        case 8:
            tab[14] = 'X';
            break;
        case 9:
            tab[16] = 'X';
            break;
        case 10:
            tab[18] = 'X';
            break;
        }

        //Player 2
        int los2;
        los2 = rand() % 10 + 11;

        switch (los2)
        {
        case 11:
            tab[22] = 'X';
            break;
        case 12:
            tab[24] = 'X';
            break;
        case 13:
            tab[26] = 'X';
            break;
        case 14:
            tab[28] = 'X';
            break;
        case 15:
            tab[30] = 'X';
            break;
        case 16:
            tab[32] = 'X';
            break;
        case 17:
            tab[34] = 'X';
            break;
        case 18:
            tab[36] = 'X';
            break;
        case 19:
            tab[38] = 'X';
            break;
        case 20:
            tab[40] = 'X';
            break;
        }


        //warunek obu petli
        bool game_on = false;
        bool game_on_ai = false;


        //wybór trybu gry
        int wybor;
        cout << "Wybierz tryb gry: 1.gracz+gracz lub 2.gracz+komputer - wpisz cyfre odpowiadajaca twojemu wyborowi ";
        cin >> wybor;
        if (wybor == 1)
        {
            game_on = true;
        }
        else if (wybor == 2)
        {
            game_on_ai = true;
        }
        else
        {
            cout << "wpisz cyfre!" << endl;
        }


        //print planszy
        cout << tab << endl;


        //printowanie liter pod plansza
        litery();


        //loop dla gry
        while (game_on)
        {

            //Podawanie predkosci V i katu wystrzelenia alfa - gracz 1

            cout << "Gracz 1" << endl;

            double player1_v;
            double player1_k;
            cout << "Podaj predkosc pocisku: ";
            cin >> player1_v;
            cout << endl;

            cout << "Podaj kat wystrzelenia pocisku: ";
            cin >> player1_k;
            cout << endl;

            double z;
            int g;

            g = 10;

            z = (pow(player1_v, 2)*2*sin(player1_k*PI/180))/g;

            cout << "Dlugosc trajektorii pocisku: " << z << " ";

            int z_rounded = (int) z;

            //Random wiatr
            int wiatr = rand() % 10 + 1;
            int wiatr_kierunek = rand() % 2;

            cout << "Wiatr: " << wiatr;

            if (wiatr_kierunek == 0)
            {
                z_rounded -= wiatr;
                cout << "L ";
            }
            else
            {
                z_rounded += wiatr;
                cout << "P ";
            }


            cout << "Dlugosc trajektorii po zaokragleniu: " << z_rounded << " ";

            //sprawdzenie wygranej
            if (z_rounded + los1 == los2)
            {
                cout << "Pocisk trafil w przeciwnika!";
                game_on = false;
                break;
            }
            else
            {
                cout << "Pocisk nie trafil w przeciwnika" << endl;
            }
            cout << endl;
            z_rounded = 0;


            //Podawanie predkosci V i katu wystrzelenia alfa - gracz 2
            cout << "Gracz 2" << endl;

            double player2_v;
            double player2_k;
            cout << "Podaj predkosc pocisku: ";
            cin >> player2_v;
            cout << endl;

            cout << "Podaj kat wystrzelenia pocisku: ";
            cin >> player2_k;
            cout << endl;

            z = (pow(player2_v, 2)*2*sin(player2_k*PI/180))/g;

            cout << "Dlugosc trajektorii pocisku: " << z << " ";

            z_rounded = (int) z;

            //Random wiatr
            int wiatr1 = rand() % 10 + 1;
            int wiatr_kierunek1 = rand() % 2;

            cout << "Wiatr: " << wiatr1;

            if (wiatr_kierunek1 == 0)
            {
                z_rounded += wiatr1;
                cout << "L ";
            }
            else
            {
                z_rounded -= wiatr1;
                cout << "P ";
            }


            cout << "Dlugosc trajektorii po zaokragleniu: " << z_rounded << " ";

            //sprawdzenie wygranej
            if (los2 - z_rounded == los1)
            {
                cout << "Pocisk trafil w przeciwnika!";
                game_on = false;
                break;
            }
            else
            {
                cout << "Pocisk nie trafil w przeciwnika" << endl;
            }
            cout << endl;
            z_rounded = 0;
        }


        while (game_on_ai)
        {

            //Podawanie predkosci V i katu wystrzelenia alfa - gracz 1

            cout << "Gracz" << endl;

            double player_v;
            double player_k;
            cout << "Podaj predkosc pocisku: ";
            cin >> player_v;
            cout << endl;

            cout << "Podaj kat wystrzelenia pocisku: ";
            cin >> player_k;
            cout << endl;

            double z;
            int g;

            g = 10;

            z = (pow(player_v, 2)*2*sin(player_k*PI/180))/g;

            cout << "Dlugosc trajektorii pocisku: " << z << " ";

            int z_rounded = (int) z;

            //Random wiatr
            int wiatr = rand() % 10 + 1;
            int wiatr_kierunek = rand() % 2;

            cout << "Wiatr: " << wiatr;

            if (wiatr_kierunek == 0)
            {
                z_rounded -= wiatr;
                cout << "L ";
            }
            else
            {
                z_rounded += wiatr;
                cout << "P ";
            }



            cout << "Dlugosc trajektorii po zaokragleniu: " << z_rounded << " ";

            //sprawdzenie wygranej
            if (z_rounded + los1 == los2)
            {
                cout << "Pocisk trafil w przeciwnika!";
                game_on = false;
                break;
            }
            else
            {
                cout << "Pocisk nie trafil w przeciwnika" << endl;
            }
            cout << endl;
            z_rounded = 0;


            //Podawanie predkosci V i katu wystrzelenia alfa - gracz 2
            cout << "Gracz SI" << endl;

            double ai_v;
            double ai_k;

            ai_v = rand() % 10 + 1;
            ai_k = rand() % 60 + 1;

            z = (pow(ai_v, 2)*2*sin(ai_k*PI/180))/g;

            cout << "Dlugosc trajektorii pocisku: " << z << " ";

            z_rounded = (int) z;

            //Random wiatr
            int wiatr1 = rand() % 10 + 1;
            int wiatr_kierunek1 = rand() % 2;

            cout << "Wiatr: " << wiatr1;

            if (wiatr_kierunek1 == 0)
            {
                z_rounded += wiatr1;
                cout << "L ";
            }
            else
            {
                z_rounded -= wiatr1;
                cout << "P ";
            }


            cout << "Dlugosc trajektorii po zaokragleniu: " << z_rounded << " ";

            //sprawdzenie wygranej
            if (los2 - z_rounded == los1)
            {
                cout << "Pocisk trafil w przeciwnika!";
                game_on = false;
                break;
            }
            else
            {
                cout << "Pocisk nie trafil w przeciwnika" << endl;
            }
            cout << endl;
            z_rounded = 0;
        }
        cout << endl;
        cout << "Koniec gry!";
        break;
    }
}
