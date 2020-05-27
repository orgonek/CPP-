/*
 * Do napisanego programu (gry w statki) dodaæ nastêpuj¹ce funkcje:
 *  // 1. Mo¿liwoœæ dodawania jednomasztowców, trójmasztowców i czteromasztowców.
 *  // 2. Dodaæ informacjê o zatopieniu statku (Statek).
 *  // 3. Dodaæ informacjê o zatopieniu wszystkich statków – koniec gry (Plansza).
 *  // 4. Mo¿liwoœæ dotykania przez statki œcian planszy.
 *  // 5. Pozwoliæ na pionowy uk³ad statków.
 *  // 6. Stworzyæ drug¹ planszê.
 *  // 7. Zezwoliæ u¿ytkownikowi na ustawienie statków (zadana liczba ka¿dego rodzaju) dla dwóch plansz.
 *  // 8. Pozwoliæ na grê pomiêdzy dwoma u¿ytkownikami.
 *   9. Pozwoliæ na inny uk³ad wiêkszych statków.
 */

#include <iostream>
using namespace std;

class Statek {
private:
    bool zatopiony;
    public:
        virtual void rysuj(int x, int y){}
        virtual void traf(int x, int y){};
        virtual bool czyCalyTrafiony(){};
        virtual bool czyZatopiony(){};
        virtual void rysujZatopiony(){};
};


class Jednomasztowiec : public Statek {
    private:
        int x, y;
        char poklad[1];
        bool zatopiony;
    public:
        Jednomasztowiec(int x, int y) : x(x), y(y) {
            poklad[0] = '_';
            zatopiony = false;
        }
       virtual void rysuj(int x, int y){
            cout << poklad[y - this->y];
        }
       virtual void traf(int x, int y){
            poklad[y - this->y] = 'T';
        }

       virtual bool czyCalyTrafiony(){
            bool value = true;
            if(poklad[y - this->y] != 'T' ){
                value = false;
            }
            if(value){
                zatopiony = true;
                rysujZatopiony();
            }

            return value;
        }
        virtual bool czyZatopiony(){
            return zatopiony;
        }
        virtual void rysujZatopiony(){
            poklad[0] = 'Z';
        }

};

class Dwumasztowiec : public Statek {
    private:
        int x, y;
        char poklad[2];
        bool zatopiony;
        char pozycja;
    public:
        Dwumasztowiec(int x, int y,char pozycja) : x(x), y(y), pozycja(pozycja) {
            poklad[0] = '_';
            poklad[1] = '_';
            zatopiony = false;
        }
        virtual void rysuj(int x, int y){
            if(pozycja == 'h'){
            cout << poklad[y - this->y];
            }
            else if(pozycja == 'v'){
                cout << poklad[x - this->x];
            }
        }
        virtual void traf(int x, int y){
            if(pozycja == 'h'){
            poklad[y - this->y] = 'T';
            }
            else if(pozycja == 'v'){
                poklad[x - this->x] = 'T';
            }
        }
        virtual void rysujZatopiony(){
            for(int i = 0 ;i < 2;i ++){
                poklad[i] = 'Z';
            }
        }
        virtual bool czyCalyTrafiony(){
            bool value = true;
            for(int i = 0 ; i < 2; i++){
                if(pozycja == 'h'){
                    if(poklad[(y - this->y) + i] != 'T' ){
                        value = false;
                        break;
                    }
                }
                else if(pozycja == 'v'){
                    if(poklad[(x - this->x) + i] != 'T' ){
                        value = false;
                        break;
                    }
                }

            }
            if(value){
                zatopiony = true;
                rysujZatopiony();
            }

            return value;

        }
        virtual bool czyZatopiony(){
            return zatopiony;
        }


};

class Trojmasztowiec : public Statek {
    private:
        int x, y;
        char poklad[3];
        bool zatopiony;
        char pozycja;
    public:
        Trojmasztowiec(int x, int y, char pozycja) : x(x), y(y), pozycja(pozycja) {
            poklad[0] = '_';
            poklad[1] = '_';
            poklad[2] = '_';
            zatopiony = false;
        }
         virtual void rysuj(int x, int y){
            if(pozycja == 'h'){
            cout << poklad[y - this->y];
            }
            else if(pozycja == 'v'){
                cout << poklad[x - this->x];
            }
        }
        virtual void traf(int x, int y){
            if(pozycja == 'h'){
            poklad[y - this->y] = 'T';
            }
            else if(pozycja == 'v'){
                poklad[x - this->x] = 'T';
            }
        }

        virtual void rysujZatopiony(){
            for(int i = 0 ;i < 3;i ++){
                poklad[i] = 'Z';
            }
        }
         virtual bool czyCalyTrafiony(){
            bool value = true;
            for(int i = 0 ; i < 3; i++){
                if(pozycja == 'h'){
                    if(poklad[(y - this->y) + i] != 'T' ){
                        value = false;
                        break;
                    }
                }
                else if(pozycja == 'v'){
                    if(poklad[(x - this->x) + i] != 'T' ){
                        value = false;
                        break;
                    }
                }

            }
            if(value){
                zatopiony = true;
                rysujZatopiony();
            }

            return value;

        }
        virtual bool czyZatopiony(){
            return zatopiony;
        }
};

class Czteromasztowiec : public Statek {
    private:
        int x, y;
        char poklad[4];
        bool zatopiony;
        char pozycja;
    public:
        Czteromasztowiec(int x, int y, char pozycja) : x(x), y(y), pozycja(pozycja) {
            poklad[0] = '_';
            poklad[1] = '_';
            poklad[2] = '_';
            poklad[3] = '_';
            zatopiony = false;
        }
       virtual void rysuj(int x, int y){
            if(pozycja == 'h'){
            cout << poklad[y - this->y];
            }
            else if(pozycja == 'v'){
                cout << poklad[x - this->x];
            }
        }
       virtual void traf(int x, int y){
            if(pozycja == 'h'){
            poklad[y - this->y] = 'T';
            }
            else if(pozycja == 'v'){
                poklad[x - this->x] = 'T';
            }
        }

       virtual void rysujZatopiony(){
            for(int i = 0 ;i < 4;i ++){
                poklad[i] = 'Z';
            }
        }
        virtual bool czyCalyTrafiony(){
            bool value = true;
            for(int i = 0 ; i < 4; i++){
                if(pozycja == 'h'){
                    if(poklad[(y - this->y) + i] != 'T' ){
                        value = false;
                        break;
                    }
                }
                else if(pozycja == 'v'){
                    if(poklad[(x - this->x) + i] != 'T' ){
                        value = false;
                        break;
                    }
                }

            }
            if(value){
                zatopiony = true;
                rysujZatopiony();
            }

            return value;

        }
        virtual bool czyZatopiony(){
            return zatopiony;
        }
};


char getChar(int z){
    return z+'a';
}

int getInt(char z){
    return z-'a';
}

class Plansza {
    private:
        int wys, szer;
        int lStatkow;
        Statek * statki[10];
        int ** mapa; //0 - wolne pole, -1 - pud³o, x - numer statku.
    public:
        Plansza(int wys, int szer);
        ~Plansza();
        int dajWys();
        int dajSzer();
        bool pustePole(int x, int y);
        void dodajStatek(int x, int y, int w,char pozycja);
        int dajLStatkow();
        void strzel(int w, int k);
        void rysuj();
        bool czyKoniec();
};

Plansza::Plansza(int wys, int szer){
    this->wys = wys;
    this->szer = szer;
    lStatkow = 0;

    mapa = new int*[wys];
    for(int i=0; i<szer; i++)
        mapa[i] = new int[szer];

    for(int i=0; i<wys; i++)
        for(int j=0; j<szer; j++)
            mapa[i][j]=-1;

   // dodajStatek(2,2, 3,'h'); //3 c
   // dodajStatek(3, 3, 2); //4 d Kolizja
    //dodajStatek(6, 3, 2,'v'); //7 d
   // dodajStatek(4, 1, 4,'v'); //5 b

}

Plansza::~Plansza(){
    for(int i=0; i<dajWys(); i++)
        delete [] mapa[i];
    delete [] mapa;
    for(int i=0; i<lStatkow; i++)
        delete statki[i];
}

int Plansza::dajWys(){
    return wys;
}

int Plansza::dajSzer(){
    return szer;
}

bool Plansza::pustePole(int x, int y){
    /*if(x<dajWys() && x>0 && y<dajSzer() && y>0){
        bool wynik = true;
        for(int i=x-1; i<x+2; i++)
            for(int j=y-1; j<y+2; j++)
                if(mapa[i][j]!=-1)
                    wynik=false;
        return wynik;
    }
    return false;
    */
    if(x >= 0 && x < dajSzer() && y >= 0 && y < dajWys()){
        return mapa[x][y] == -1;
    }
    return false;
}

void Plansza::dodajStatek(int x, int y, int w,char pozycja){
    bool wolne=true;

    if(x >= 0 && x < dajSzer() && y >= 0 && y < dajWys()){
        if(pozycja == 'h'){
            for(int i=0; i<w; i++)
                if(!pustePole(x,y+i))
                wolne=false;
        }
        else if(pozycja == 'v'){
            for(int i=0; i<w; i++)
                if(!pustePole(x+i,y))
                    wolne=false;

    }

    if(wolne){
        switch(pozycja){
            case 'h':
                for(int i = 0; i < w; i++){
                    mapa[x][y+i] = lStatkow;
                }
            break;
            case 'v':
                for(int i = 0; i < w; i++){
                    mapa[x+i][y] = lStatkow;
                }
                break;

        }

        Statek *st ;
        switch(w){
        case 1:
            st = new Jednomasztowiec(x,y);
            break;
        case 2:
            st = new Dwumasztowiec(x,y,pozycja);
            break;
        case 3:
            st = new Trojmasztowiec(x,y,pozycja);
            break;
        case 4:
            st = new Czteromasztowiec(x,y,pozycja);
            break;
        }
        statki[lStatkow++] = st;


    }
    else
        cout << endl << "B³êdna pozycja statku" << endl << endl;

    }
}

void Plansza::strzel(int w, int k){
    if(mapa[w][k]>=0){
        statki[mapa[w][k]]->traf(w,k);
        if(statki[mapa[w][k]]->czyCalyTrafiony()){
            cout << "Statek zatopiony" << endl;
        }
    }

    else
        mapa[w][k]=-2;
}

void Plansza::rysuj(){
    cout << ' ';
    for(int j=0; j<dajSzer(); j++)
        cout << ' ' << getChar(j);
    cout << endl;
    for(int i=0; i<dajWys(); i++){
        cout << i+1;
        for(int j=0; j<dajSzer(); j++)
            switch(mapa[i][j]) {
                    case -2: cout << ' ' << 'X'; break;
                    case -1: cout << ' ' << '_'; break;
                    default: cout << ' '; statki[mapa[i][j]]->rysuj(i, j);
            }
        cout << endl;
    }
    cout << "____________________" << endl << endl;
}
int Plansza::dajLStatkow(){
    return lStatkow;
}
bool Plansza::czyKoniec(){
    bool value = true;
    for(int i = 0 ; i < dajLStatkow();i++){
        if(!statki[i]->czyZatopiony()){
            value =  false;

        }

    }
     return value;
}

void ustawStatki(Plansza * plansza, int liczbaStatkow, int wielkoscStatku){
    int x = 0;
    char poz ,y;
    string statki[] = {"jednomasztowiec","dwumasztowiec","trójmasztowiec","czteromasztowiec"};

    do{
        cout << "Rozmieszczenie - " << statki[wielkoscStatku - 1] << endl;
        cout << "Wybierz orientacje statku (v - pionowa, h - pozioma) " << endl;
        cin >> poz;
        if(poz != 'v' && poz != 'h'){
            cout << "Nieprawidlowa pozycja statku" << endl;
            exit(0);
        }
        cout << "Podaj lokalizacje statku na planszy (wiersz - liczba, kolumna - znak np 1a,2b itd.) " << endl;
        cin >> x  >> y;


        cout << "Wartosc x " << x  << endl;
        cout << "Wartosc y " << y << endl;
        cout << getInt(y) << endl;

        plansza -> dodajStatek(x - 1,getInt(y),wielkoscStatku,poz);


        liczbaStatkow--;


    }while(liczbaStatkow > 0);
}
void start(Plansza * gracz1, Plansza * gracz2){
    Plansza * aktualna = gracz1;
    cout << "Plansza gracza 1:"<<endl;
    gracz1->rysuj();
     cout << "Plansza gracza 2:"<<endl;
    gracz2->rysuj();

    int kto = 0;

    while(!gracz1->czyKoniec() && !gracz2->czyKoniec()){
        int l;
        char z;
        cout <<" Strzel (wiersz - liczba, kolumna - znak) ruch a gracza : "  <<  endl;
        cin >> l >> z;
        aktualna -> strzel(l-1,getInt(z));
        cout << "Plansza gracza " << kto + 1 <<  endl;
        aktualna->rysuj();
        kto = ++kto%2;
        aktualna = kto%2 == 0 ? gracz1 : gracz2;
        cout << "Plansza gracza " << kto + 1 <<endl;
        aktualna->rysuj();



    }


    cout << "Koniec gry" <<endl;
    cout << "Wygrywa gracz " << kto + 1<< endl;

}


int main() {
    Plansza plansze[]{
        Plansza(8,8),
        Plansza(8,8)
    };
    int i = 1;
    cout << "Ustawianie statkow przez gracza " << i << endl;
    ustawStatki(&plansze[0],1,2);
  //  ustawStatki(&plansze[0],1,2);
  //  ustawStatki(&plansze[0],1,3);
   // ustawStatki(&plansze[0],1,4);
    i++;
    cout << "Ustawianie statkow przez gracza " << i << endl;
    ustawStatki(&plansze[1],1,2);
   // ustawStatki(&plansze[1],1,2);
   // ustawStatki(&plansze[1],1,3);
   // ustawStatki(&plansze[1],1,4);

    start(&plansze[0],&plansze[1]);






    return 0;
}
