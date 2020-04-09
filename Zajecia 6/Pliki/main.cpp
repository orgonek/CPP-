#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
/*
Dane w formacie typu lista.txt
*/
int licz(char nazwaPliku[], int &biale_znaki, int &slowa){
    char ostatniZnak;
    int wszystkieZnaki = 0;
    ifstream file(nazwaPliku);
    slowa = 1;
    char znak ;

    file.get(ostatniZnak);
    file.seekg(0,ios::beg);

    while(file.get(znak)){
        if(znak == EOF){
            break;
        }
        if(iswspace(znak)){
            biale_znaki++;
        }
        if((znak == ' ' || znak == '\n')&&(ostatniZnak != '\n') && ostatniZnak != ' '){
            slowa++;
        }

        wszystkieZnaki++;
        ostatniZnak = znak;
    }

    return wszystkieZnaki;
    file.close();
}

/*
Bez uwzglednienia wielkosci
Uzycie find
*/
void szukaj(char nazwaPlikWe[], char nazwaPlikuWy[],char slowo[]){
    int numerLinii = 1;
    string line;
    ifstream plikWe(nazwaPlikWe);
    ofstream plikWy(nazwaPlikuWy);

    while(getline(plikWe,line)){
        if(line.find(slowo) != string::npos){
            plikWy << numerLinii << ". " <<line << endl;
        }
        numerLinii++;
    }
    cout << "Zapisano do pliku" << endl;
    plikWe.close();
    plikWy.close();
}

/*
Z uwzglednieniem wielkosci liter
*/

void szukaj2(char nazwaPlikWe[], char nazwaPlikuWy[],char slowo[]){
    int pomocznicza = 0;
    int numerLinii = 1;
    int j = 0;
    int n = strlen(slowo);
    string line;
    ifstream plikWe(nazwaPlikWe);
    ofstream plikWy(nazwaPlikuWy);


    while(getline(plikWe,line)){
        j = 0;
        for(int i = 0; i < line.size(); i++){
            if(tolower(line[i]) == tolower(slowo[j])){
                pomocznicza = i;
                while(tolower(line[i]) == tolower(slowo[j]) && j < n){
                    i++;
                    j++;
                }
                if(j == n){
                    plikWy << numerLinii << ": " <<line << endl;
                    line = "";
                    break;
                }
                else{
                    i = pomocznicza;

                }
            }
        }
        numerLinii++;
    }
    plikWe.close();
    plikWy.close();
    cout << "Zapisano do pliku" << endl;
}
int main()
{

    return 0;
}


