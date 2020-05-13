#include <iostream>
#include <fstream>

using namespace std;

class Lista{
private:
    int * liczby;
    int pojemnosc;
    int rozmiar;

    void aktualizuj(int n){
        n++;
        for(int i = n; i < rozmiar; i++){
            liczby[i-1] = liczby[i];
        }

        rozmiar = rozmiar - 1;
    }
public:
    Lista(int n){
        pojemnosc = n;
        liczby = new int[n];
        rozmiar = 0;
    }

    ~Lista(){
    delete []liczby;
    }

    void dodajElement(int liczba){
        if(pojemnosc > rozmiar){
            liczby[rozmiar] = liczba;
            rozmiar ++;
        }
        else{
            cout << "Nie mo¿na dodaæ wiêcej elementów, lista pe³na!" << endl;
        }
    }

    int znajdz(int liczba){
        int pozycja = -1;
        for(int i = 0 ; i < rozmiar; i++){
            if(liczby[i] == liczba){
                cout << " id " << i << endl;
                pozycja = i;
                break;
            }
        }

        return pozycja;
    }

     void pisz(){
        cout << "Lista:"<<endl;
        cout << "\tPojemnosc listy " << pojemnosc << endl;
        cout << "\tRozmiar listy " << rozmiar << endl;
        cout << "\tElementy : ";
        for(int i = 0 ; i < rozmiar; i++){
            cout << liczby[i] << " ";
        }
        cout << endl;

    }


    void usunPierwszy(int liczba){
        for(int i = 0; i < rozmiar; i++){
            if(liczby[i] == liczba){
                aktualizuj(i);
                break;
            }
        }

    }

    void usunPowtorzenia(){
        int j = 0;
        for(int i = 0 ; i < rozmiar; i++){
                j = i + 1;
                while(j < rozmiar){
                    if(liczby[i] == liczby[j]){
                        aktualizuj(j);
                        j;
                    }
                    j++;
                }

            }

    }

    void odwroc(){
        for(int i = 0; i < rozmiar/2; i++){
            int x = liczby[i];
            liczby[i] = liczby[rozmiar-1-i];
            liczby[rozmiar-1-i] = x;
        }
    }

    void zapiszDoPliku(string nazwaPliku){
        ofstream plik(nazwaPliku);
        for(int i = 0; i < rozmiar; i++){
            plik << liczby[i] << " " ;
        }
        plik << endl;
        plik.close();
        cout << "Zapisano do pliku";
    }





};
int main()
{
   const int N = 10;
Lista * l = new Lista(N);
for (int i = 0; i < N/2; ++i) {
l->dodajElement( (1 << i) );
}
l->dodajElement(2);
l->dodajElement(8);
l->pisz();
l->usunPierwszy(2);
l->pisz();
for (int i = 0; i < N/2; ++i) {
l->dodajElement( (1 << i) );
}
l->pisz();
cout << "Po usunięciu powtórzeń:" << endl;
l->usunPowtorzenia();
l->pisz();
l->zapiszDoPliku("plik.3txt");
cin.get();
return 0;
}
