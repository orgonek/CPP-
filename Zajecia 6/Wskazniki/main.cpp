#include <iostream>
#include <string>
#include <string.h>

using namespace std;


void minMax(int tab[], int w, int* wmin, int* wmax){
    *wmin = tab[0];
    *wmax = tab[0];

    for(int i = 1; i < w; i++){
        if(tab[i] > *wmax){
            *wmax = tab[i];
        }
        if(tab[i] < *wmin){
            *wmin = tab[i];
        }
    }
}

void strls(char s1[], char s2[], char* &dluzszy, char* &krotszy){
    int sLen1 = strlen(s1);
    int sLen2 = strlen(s2);

    if(sLen1 >= sLen2){
        dluzszy = s1;
        krotszy = s2;
    }
    else{
        krotszy = s1;
        dluzszy = s2;
    }
}

void ptradv(int* wsk, int n){
    for(int i=0 ;i < n; i++){
        cout << wsk << " " << *wsk << endl;
        wsk++;
    }
    }

int * odwroc(int *tab, int rozmiar){
    int * newTab = new int[rozmiar];

    for(int i = rozmiar, j = 0; i > 0; i--, j++){
        newTab[j] = tab[i - 1];
    }

    return newTab;

}

void tabliczka(int r){
    char czyKoniec = 'n';
    int pierwszaLiczba = 1, drugaLiczba = 1;
    int ** tablica = new int*[r];

    for(int i = 0; i < r; i++){
        tablica[i] = new int[r];
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < r; j++){
            tablica[i][j] = (i + 1) * (j+1);
        }
    }


   do{
        cout <<"Mnozenie dwoch liczb (aby zakonczyc wpisz 0)" << endl;
        cout << "Podaj pierwsza liczbe";
        cin >> pierwszaLiczba;
        cout << "Podaj druga liczbe";
        cin >> drugaLiczba;
        cout << "Wynik mno¿enia " <<pierwszaLiczba << "*" << drugaLiczba << " = " << pierwszaLiczba * drugaLiczba <<endl;
        cout << "Czy kontynuowaæ (t/n)" << endl;
        cin >> czyKoniec;
   }while(czyKoniec != 'n');

   for(int i = 0; i < r; i++){
    for(int j = 0; j < r; j++){
        cout << tablica[i][j] << "\t";
    }
    cout << endl;
   }

   for(int i = 0; i < r; i++){
        delete[]tablica[i];
   }
   delete[] tablica;



}


string * podziel_na_slowa(char tekst[], int &ile_slow){
    bool ostatniBialy = true;
    string wyraz = "";
    int licznik = 0;

    ile_slow = 0;
    for(int i = 0; tekst[i] != '\0'; i++){
       if(isalpha(tekst[i])){
            while(isalpha(tekst[i])){
                i++;
            }
            ile_slow++;
       }
    }

    string * listaSlow = new string[ile_slow];

    for(int i = 0; tekst[i] != '\0'; i++){
        if(isalpha(tekst[i])){
            while(isalpha(tekst[i])){
                wyraz += tekst[i];
                i++;
            }
            listaSlow[licznik] = wyraz;
            licznik++;
            wyraz = "";

        }
    }



    return listaSlow;
}
int main()
{

    /*
    Zadanie 1

    int t[] = {-523, -4, 1, 0, 10, 5};
    int min, max;
    minMax(t, sizeof(t) / sizeof(t[0]), &min, &max);
    cout << "Najmniejszy i najwieksy element ci¹gu, to " << min<< ", " << max << endl;

    */

    /*
    #Zadanie 2

    char s1[100];
    char s2[100];
    cout << "Podaj pierwszy ciag: ";
    cin >> s1;
    cout << "Podaj drugi ciag: ";
    cin >> s2;
    char* krotszy;
    char* dluzszy;
    strls(s1, s2, dluzszy, krotszy);
    cout << "Dluzszy z podanych lancuchow to: " << dluzszy << endl<< "Krotszy z podanych lancuchow to: " << krotszy << endl;

    */

    /*

    Zadanie 3
    int t[] = { 1, 3, -6, 4};
    int* z;
    ptradv(t, 4);
    z = t;
    ptradv(z, 4);

    */

    /*
    Zadanie 4

    int liczby [] = { 1, 2, 3, 4, 5, 6 };
    int *odwrotnie = odwroc(liczby, 6);
    for (int i = 0; i < 6; ++i) {
    cout << odwrotnie[i] << " ";
    } // powinno wyœwietliæ: 6 5 4 3 2 1

    delete [] odwrotnie; // zwolnienie przydzielonej pamiêci

    */

    /*
    Zadanie 5

    int i;
    cout<<"Podaj wielkoœæ tabliczki mno¿enia: ";
    cin>>i;
    tabliczka(i);

    */

     char s[]= " Ala ma kota. \nKot ma mysz.                  PIES ";
    int ile_slow;
    string * slowa = podziel_na_slowa(s, ile_slow);
    for (int i = 0; i < ile_slow; ++i) {
    cout << i << " " << slowa[i] << endl;
    }
    delete [] slowa;
    return 0;
}
