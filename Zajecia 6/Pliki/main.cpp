#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
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

void emerytura(char nazwaPliku[]){
    ifstream plikWe(nazwaPliku);
    ofstream plikWyM("mezczyzni.txt");
    ofstream plikWyK("kobiety.txt");
    string dane [4];
    string line ;
    string slowo = "";

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



            int wiekEmerytalny = (dane[2] == "M") ? 65 : 60 ;
            int doEmerytury =  wiekEmerytalny >= stoi(dane[3])  ? (wiekEmerytalny - stoi(dane[3])) : 0;


            if(dane[2] == "M"){
                plikWyM << dane[1] << " " << dane[0] << " " << doEmerytury<<'\n';
            }
            else if(dane[2] == "K"){
                plikWyK << dane[1] << " " << dane[0] << " " << doEmerytury <<'\n';
            }


        }

    cout << "Zapisano do pliku" << endl;
    plikWe.close();
    plikWyM.close();
    plikWyK.close();

}

void sumujIZapisz(const char* nazwaPliku){
    fstream plik;
    plik.open(nazwaPliku,ios::in | ios::out);
    int suma = 0;
    int x;
    while(plik >> x) {
        cout << x << " " ;
        suma += x;
    }
    plik.close();
    plik.open(nazwaPliku,ios::app);
    plik <<'\n'<<suma;

    plik.close();

}

void szyfruj(string nazwaPlikuWe, int przesun){
    ifstream plikWe(nazwaPlikuWe);
    char c = nazwaPlikuWe[0];

    string nazwaPlikuWy = (c == '_') ? ("Rozszyfrowany" + nazwaPlikuWe) : ("_" + nazwaPlikuWe);
    ofstream plikWy(nazwaPlikuWy);

    string line,resultLine;
    int asciiStart = 0;

    while(getline(plikWe,line)){
            resultLine = "";
        for(int i =0; i < line.size();i++){
            if(line[i] >= 65 && line[i] <= 90){
                asciiStart = 65;
            }

            else if(line[i] >=97 && line[i] <= 122){
                asciiStart = 97;
            }

            if(isalpha(line[i])){
                resultLine += ((line[i] + 26 + przesun - asciiStart)% 26) + asciiStart;
            }
            else{
                resultLine += line[i];
            }

        }
        plikWy<<resultLine << endl;
    }

        plikWe.close();
        plikWy.close();
        cout << "Zapisano do pliku";


}

/*
maksymalne przesun = 26
*/

void deszyfruj(string nazwaPlikuWe, int przesun){
    szyfruj(nazwaPlikuWe, -przesun);
}

void toHTML(string nazwaPlikuWe){
    string nazwaPlikuWy = "HTML_" + nazwaPlikuWe;
    ifstream plikWe(nazwaPlikuWe);
    ofstream plikWy(nazwaPlikuWy);
    string line ;
    string daneHtml = "<html><body><table>";
    string slowo = "<td>";

    while(getline(plikWe,line)){
        //cout << line << endl;
        daneHtml += "<tr>";
        for(int i = 0; i < line.size(); i++){
            if(line[i] == ' '){
                daneHtml += slowo;
                daneHtml += "</td>";
                slowo = "<td>";

            }
            else{
                slowo += line[i];
            }

        }
        daneHtml += slowo;
        daneHtml += "</td>";
        daneHtml += "</tr>";
        plikWy << daneHtml << '\n' ;
        daneHtml = "";
        slowo = "<td>";
    }

    plikWy << "</table></body></html>";
    plikWy.close();
    cout << "Zapisano do pliku: " <<nazwaPlikuWy <<  endl;
}

void malujWykres(string nazwaPliku){
    ifstream plikWe(nazwaPliku);
    char znak;
    int alfabet [26];
    for(int i = 0; i < 26 ; i++){
        alfabet[i] = 0;
    }
    while(plikWe >> znak){
        if(isalpha(znak)){
            alfabet[(int) (tolower(znak) - 'a')] ++;
        }
    }
    int maximum = 0;

    for(int i = 0; i < 26; i++){
        if(alfabet[i] > maximum){
            maximum = alfabet[i];
        }
    }

   double range =  (double) maximum/ 50 ;


    for(int i = 0 ; i < 26; i++){
        cout << (char) ('a' + i) <<": ";

        for(double j = range ; j <= alfabet[i]; j+= range){
            cout << "*";
        }

        cout << " " << alfabet[i]  << endl;
        }
}
int main()
{
    malujWykres("book.txt");
    return 0;
}
