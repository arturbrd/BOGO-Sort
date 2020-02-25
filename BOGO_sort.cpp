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
    int wprowadzoneLiczby[10];
    bool jestLiczba;

    bool posortowane;
    clock_t start, stop;
    long double czas;
    string wykonajPonownie;

    srand(time(NULL));

    do {
        system("cls");

        cout << "BOGO-SORT ORIGINAL" << endl;


        cout << "Podaj 10 liczb do sortowania (zatwierdzaj kazda liczbe enterem):" << endl;
        for (int i = 0; i < 10; i++)
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

        start = clock();
        do
        {
            losuj(wprowadzoneLiczby);
            posortowane = sprawdz(losowo);
            licznik++;
        } while (posortowane == false);
        stop = clock();
        czas = (stop - start) / CLOCKS_PER_SEC;

        for (int j = 0; j < 10; j++)
        {
            cout << losowo[j] << " ";
        }

        cout << setprecision(1000);
        cout << endl << "Liczba prob: " << licznik << endl;
        cout << "Czas sortowania: " << czas << "s." << endl;
        
        cout << "Aby wyjsc wpisz 'x': ";
        cin >> wykonajPonownie;

    } while (wykonajPonownie != "x");
}