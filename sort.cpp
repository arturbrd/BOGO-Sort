#pragma comment(lib, "winmm.lib")
#include "sort.h"
#include <ctime>
#include <iostream>
#include <windows.h>

using namespace std;

int losowo[10];
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

void losuj(int liczby[])
{

	int indeks;
	bool zajety[10] = { false, false, false, false, false,
	false, false, false, false, false };
	bool powtarzaj;

	for (int i = 0; i < 10; i++)
	{
		do
		{
			indeks = rand() % 10;
			if (zajety[indeks] == true) powtarzaj = true;
			else powtarzaj = false;
		} while (powtarzaj == true);
		losowo[indeks] = liczby[i];
		zajety[indeks] = true;
	}
}

bool sprawdz(int liczby[])
{
	for (int i = 0; i < 9; i++)
	{
		if (liczby[i] > liczby[i + 1]) return false;
	}

	return true;
}
