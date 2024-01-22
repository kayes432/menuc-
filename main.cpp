
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int Menu()
{
    int x;
    HANDLE hOut;

    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << endl;
    cout << "1. Dodaj element tablicy" << endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "2. Wstaw element tablicy" << endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << "3. Usun element tablicy" << endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "4. Wyswietl elementy tablicy" << endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "5. Zapisz do pliku" << endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "6. Wczytaj z pliku" << endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << "7. Wyjscie z programu" << endl;
    cin >> x;
    cout << endl;
    return x;
}

int main()
{
   int m;
    int *p = NULL;
    int n = 0;
    const char* nazwaPliku = "dane.txt";
    while(true)
    {
        m = Menu();
        switch(m)
        {
        case 7:
            {
                return 0;
            }
        case 1:
            {
                int * tmp = NULL;
                tmp = new int[n+1];
                if(p != NULL)
                {
                    for(int i=0;i<n;i++)
                    {
                        tmp[i] = p[i];
                    }

                    delete[] p;

                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[n];
                p = tmp;
                n++;
                break;
            }
        case 2:
        {
            if (n > 0) {
                int wstaw;
                cout << "Podaj indeks na ktory chcesz wstawic element: ";
                cin >> wstaw;

                if (wstaw >= 0 && wstaw <= n) {
                    int* tmp = new int[n + 1];

                    for (int i = 0, j = 0; i < n + 1; i++) {
                        if (i == wstaw) {
                            cout << "Podaj element do wstawienia: ";
                            cin >> tmp[i];
                        }
                        else {
                            tmp[i] = p[j++];
                        }
                    }

                    delete[] p;
                    p = tmp;
                    n++;

                    cout << "Wstawiono element do tablicy" << endl;
                }
                else {
                    cout << "Podano nieprawidlowy indeks" << endl;
                }
            }
            else {
                cout << "Tablica jest pusta" << endl;
            }
            break;
        }
        case 3:
        {
            if (n > 0) {
                int usun;
                cout << "Podaj indeks elementu do usuniecia: ";
                cin >> usun;

                if (usun >= 0 && usun < n) {
                    int* tmp = new int[n - 1];

                    for (int i = 0, j = 0; i < n; i++) {
                        if (i != usun) {
                            tmp[j++] = p[i];
                        }
                    }

                    delete[] p;
                    p = tmp;
                    n--;

                    cout << "Usunieto element z tablicy" << endl;
                }
                else {
                    cout << "Podano nieprawidlowy indeks" << endl;
                }
            }
            else {
                cout << "Tablica jest pusta" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Zawartosc tablicy:" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << p[i] << ", ";
            }
            cout << endl;
            break;
        }
        case 5:
        {
            ofstream plik(nazwaPliku);
            if (plik.is_open())
            {
                plik << n << endl;

                for (int i = 0; i < n; i++)
                {
                    plik << p[i] << " ";
                }

                plik.close();
                cout << "Zapisano do pliku" << endl;
            }
            else
            {
                cout << "Brak" << endl;
            }
            break;
        }
        case 6:
        {
            ifstream plik(nazwaPliku);
            if (plik.is_open())
            {
                plik >> n;


                delete[] p;


                p = new int[n];


                for (int i = 0; i < n; i++)
                {
                    plik >> p[i];
                }

                plik.close();
                cout << "Wczytano z pliku" << endl;
            }
            else
            {
                cout << "bladd" << endl;
            }


            break;
        }
        default:
        {
            cout << "Nieprawidlowa opcja" << endl;
        }
        }
    }



    return 0;
}

