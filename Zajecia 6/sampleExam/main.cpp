#include <iostream>
#include <fstream>
#include<string.h>
#include <string>

using namespace std;

double przepisz(char* nazwaPliku, int wiek){

    ifstream plikWe(nazwaPliku);
    string nazwaPlec = nazwaPliku;
    ofstream plikMez("m"+nazwaPlec);
    ofstream plikKob("k"+nazwaPlec);
    string slowo = "", line = "";
    string dane[6];
    int wiekOsoby = 0, licznik = 0;
    double suma = 0;

    double nowaPensja = 0;
    double pensja = 0;

     while(getline(plikWe,line)){
            int i = 0;
            for(char c : line){
                if(c == ' '){
                    dane[i] = slowo;
                    i++;
                    slowo = "";
                }
                else{
                    slowo += c;
                }

            }
            dane[i] = slowo;
            slowo = "";

            wiekOsoby = stod(dane[3]);
            pensja = stod(dane[4]);
            if(dane[2] == "M"){
                nowaPensja = pensja + (pensja * wiekOsoby/100) ;
                plikMez << dane[0] << " " << dane[1] << " " << wiekOsoby << " " << nowaPensja<<endl;

                suma += wiekOsoby;
                licznik++;
            }
            else if(dane[2] == "K"){
                nowaPensja = (wiekOsoby > wiek) ? (pensja + 0.05 * pensja) : (pensja - (pensja * 0.03));
                plikKob << dane[0] << " " << dane[1] << " " << wiekOsoby << " " << nowaPensja<<endl;
            }
     }

        plikWe.close();
        plikMez.close();
        plikKob.close();
        cout << "Zapisano do pliku" << endl;

     return suma/licznik;

}
// szukanie pozycji (linii, w pliku) w której znajduje siê dany wyraz
int fif(char* pl, char* slowo, char* &wsk){
    ifstream plikWe(pl);
    string wyraz = "";
    string line = "";
    bool czyZnaleziono = false;
    int dlugoscMax = 0;
    string najdluzszyWyraz = "";
    int nrLinii = 1,  pozycja = -1;

    while(getline(plikWe,line)){
        for(int i = 0; i < line.size(); i++){
            while(isalpha(line[i]) || isdigit(line[i])){
                wyraz += line[i];
                i++;
            }
            if(wyraz.length() > najdluzszyWyraz.length()){
                najdluzszyWyraz = wyraz;
            }
            wyraz = "";
        }
        if((line.find(slowo) != string::npos)&& czyZnaleziono == false){
             czyZnaleziono = true;
             pozycja = nrLinii;

        }
        nrLinii++;
    }
    char * pomocnicza  = new char[najdluzszyWyraz.size() + 1 ];
    strcpy(pomocnicza, najdluzszyWyraz.c_str());
    wsk = pomocnicza;
    return pozycja;
}
int main()
{

    cout <<"srednia wieku mezczyzn to  " <<  przepisz("dane.txt",42) << endl;;
    char *x = new char;
    cout << "Podany wyraz znajduje sie w linii nr " << fif("text.txt","unknown",*&x) << " a najdluszy wyraz w pliku to " ;
    cout << x << endl;
    delete []x;
    return 0;
}
