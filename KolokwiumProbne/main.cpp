#include <iostream>

using namespace std;
class Samochod{
    public:
        virtual int spalanie(int x){return 0;}
        virtual double czasPrzejazdu(int x) {return 0;}
        virtual string dajNazwe(){return "nazwa";}
        virtual string dajRodzaj(){return "rodzaj";}
        void dane(){
            cout << "Nazwa samochodu: " << dajNazwe() << endl;
            cout << "Rodzaj samochodu: " << dajRodzaj() << endl;
            cout << "Czas przejazdu 100 km :" << czasPrzejazdu(100) << endl;
            cout << "Spalanie samochodu podczas 100km :" << spalanie(100) << endl;
            }
};
class Osobowy : public Samochod{
    private:
        string nazwa;
        double oszczednosc;
        string rodzaj;

    public:
        Osobowy(string nazwa, double oszczednosc): nazwa(nazwa), oszczednosc(oszczednosc){
        rodzaj = "Osobowy";
    }
    int spalanie(int x) {
        return oszczednosc * 7 * x;
    }
    double czasPrzejazdu(int x){
        return x/(oszczednosc*90);
    }
    string dajNazwe(){
        return nazwa;
    }
    string dajRodzaj(){
        return rodzaj;
    }

};

class Ciezarowy : public Samochod{
    private:
        string nazwa;
        double oszczednosc;
        string rodzaj;

    public:
        Ciezarowy(string nazwa, double oszczednosc): nazwa(nazwa), oszczednosc(oszczednosc){
        rodzaj = "Ciezarowy";
    }
    int spalanie(int x) {
        return oszczednosc * 25 * x;
    }
    double czasPrzejazdu(int x){
        return x/(oszczednosc*50);
    }
    string dajNazwe(){
        return nazwa;
    }
    string dajRodzaj(){
        return rodzaj;
    }
};

class Terenowy : public Samochod{
    private:
        string nazwa;
        double oszczednosc;
        string rodzaj;

    public:
        Terenowy(string nazwa, double oszczednosc): nazwa(nazwa), oszczednosc(oszczednosc){
        rodzaj = "Terenowy";
    }
    int spalanie(int x) {
        return oszczednosc * 12 * x;
    }
    double czasPrzejazdu(int x){
        return x/(oszczednosc*70);
    }
    string dajNazwe(){
        return nazwa;
    }
    string dajRodzaj(){
        return rodzaj;
    }
};


int main()
{
    int liczba;
    string nazwa, rodzaj;
    double oszczednosc;

    cout << "Podaj liczbe samochodow ktore chcesz dodaæ" << endl;
    cin >> liczba;
    Samochod * auta[liczba];

    for(int i = 0 ; i < liczba; i++){
        cout << "Podaj rodzaj samochodu [Osobowy,Ciezarowy,Terenowy]"<<endl;
        cin >> rodzaj;
        cout << "Podaj nazwa samochodu" << endl;
        cin >> nazwa;
        cout << "Podaj oszczednosc samochodu" <<endl;
        cin >> oszczednosc;
        if(rodzaj == "Osobowy"){
            auta[i] = new Osobowy(nazwa,oszczednosc);
        }
        else if(rodzaj == "Ciezarowy"){
            auta[i] = new Ciezarowy(nazwa,oszczednosc);
        }
        else if(rodzaj == "Terenowy"){
            auta[i] = new Terenowy(nazwa,oszczednosc);
        }
        else{
            cout << "Wprowadzono niepoprawne dane " << endl;
            break;
        }
    }

    for(int i = 0 ; i < liczba; i++){
        cout << "Samochod " << i + 1 <<endl;
        auta[i] -> dane();
        cout << endl;

    }

    delete * auta;
    for(int i = 0; i < liczba ; i++){
        delete auta[i];
    }
    return 0;
}
