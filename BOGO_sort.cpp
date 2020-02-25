#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>
#include <windows.h>
#include <iomanip>
#include "sort.h"

using namespace std;

int main()
{
    czolowka();

    int kontener;
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
            if (cin.fail() == 1)
            {
                cout << "To nie jest liczba draniu. Work in progress." << endl;
                cin.ignore();
                cin.clear();
                i--;
            }
            else if (cin.fail() == 0) wprowadzoneLiczby[i] = kontener;
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