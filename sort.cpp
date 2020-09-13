#pragma comment(lib, "winmm.lib")
#include "sort.h"
#include <ctime>
#include <iostream>
#include <windows.h>
#include <utility>

using namespace std;

long double licznik = 0;

void czolowka()
{
    PlaySound(TEXT("losu.wav"), NULL, SND_FILENAME | SND_ASYNC);

    cout << "B";
    Sleep(300);
    cout << "O";
    Sleep(300);
    cout << "G";
    Sleep(300);
    cout << "O";
    Sleep(300);
    cout << "-";
    Sleep(300);
    cout << "S";
    Sleep(300);
    cout << "O";
    Sleep(300);
    cout << "R";
    Sleep(300);
    cout << "T ";
    Sleep(300);
    cout << "E";
    Sleep(300);
    cout << "N";
    Sleep(300);
    cout << "T";
    Sleep(300);
    cout << "." << endl;
    Sleep(1500);

    cout << "PREZENTUJE:" << endl;
    Sleep(2000);
}

int* losuj(int liczby[], int ilosc)
{
    int* losowo = new int[ilosc];


    for (int i = 0; i < ilosc; i++)
    {
        losowo[i] = liczby[i];
    }

    int x;
    for (int i = 0; i < ilosc; i++)
    {
        x = rand() % ilosc;
        swap(losowo[i], losowo[x]);
    }
    /*int indeks;
    bool* zajety = new bool[ilosc];
    for (int i = 0; i < ilosc; i++) {
        zajety[i] = false;
    };
    bool powtarzaj;

    for (int i = 0; i < ilosc; i++)
    {
        do
        {
            indeks = rand() % ilosc;
            if (zajety[indeks] == true) powtarzaj = true;
            else powtarzaj = false;
        } while (powtarzaj == true);
        losowo[indeks] = liczby[i];
        zajety[indeks] = true;
    }

    delete[] zajety;*/
    return losowo;
}

bool sprawdz(int liczby[], int ilosc)
{
    for (int i = 0; i < ilosc - 1; i++)
    {
        if (liczby[i] > liczby[i + 1]) return false;
    }

    return true;
}
