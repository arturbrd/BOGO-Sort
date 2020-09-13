#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>
#include <windows.h>
#include <iomanip>
#include <cctype>
#include "sort.h"

using namespace std;



int main()
{
    czolowka();

    string kontener;
    int ileLiczb;

    bool jestLiczba;

    bool posortowane;
    clock_t start, stop;
    long double czas;
    string wykonajPonownie;

    srand(time(NULL));

    do {
        system("cls");

        cout << "BOGO-SORT ORIGINAL" << endl;

        cout << "Ile liczb chcesz podac: ";
        cin >> ileLiczb;

        int* wprowadzoneLiczby = new int[ileLiczb];
        cout << "Podaj liczby do sortowania (zatwierdzaj kazda liczbe enterem):" << endl;
        for (int i = 0; i < ileLiczb; i++)
        {
            cin >> kontener;
            jestLiczba = true;

            for (int j = 0; j < kontener.length(); j++)
            {
                if (!(isdigit(kontener[j]))) jestLiczba = false;
            }

            if (jestLiczba) wprowadzoneLiczby[i] = stoi(kontener);
            else
            {
                cout << "To nie jest liczba draniu." << endl;
                i--;
            }
        }

        cout << "Liczby zapisane. Teraz nastapi sortowanie." << endl;

        PlaySound(TEXT("losu.wav"), NULL, SND_FILENAME | SND_ASYNC);


        int* losowo = new int[ileLiczb];
        start = clock();

        do
        {
            losowo = losuj(wprowadzoneLiczby, ileLiczb);
            posortowane = sprawdz(losowo, ileLiczb);
            if (posortowane == false) { delete[] losowo; }
            licznik++;
        } while (posortowane == false);
        stop = clock();
        czas = (stop - start) / CLOCKS_PER_SEC;

        for (int j = 0; j < ileLiczb; j++)
        {
            cout << *(losowo + j) << " ";
        }


        delete[] losowo;
        delete[] wprowadzoneLiczby;
        cout << setprecision(1000);
        cout << endl << "Liczba prob: " << licznik << endl;
        cout << "Czas sortowania: " << czas << "s." << endl;

        do
        {
            cout << "Kontynuowac? (t/n): ";
            cin >> wykonajPonownie;
            if (wykonajPonownie != "t" && wykonajPonownie != "n") cout << "Wpisz t lub n" << endl;
        } while (wykonajPonownie != "t" && wykonajPonownie != "n");

    } while (wykonajPonownie == "t");
}