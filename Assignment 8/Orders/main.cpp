#include <iostream>
#include <sstream>

using namespace std;
class ElementZamowienia{
private :
    string nazwa;
    double cena;
    int liczbaSztuk;
public :
    ElementZamowienia(){
        nazwa = "nazwaProduktu";
        cena = 0;
        liczbaSztuk = 0;
    }
    ElementZamowienia(string n, double c, int l){
        nazwa = n;
        cena = c;
        liczbaSztuk = l;
    }

    string toString(){
        stringstream ss;
        ss << nazwa << " " <<  cena << " zl, " << liczbaSztuk << "szt, lacznie " << obliczKoszt() << " zl "<< endl;

        return ss.str();
    }

    double obliczRabat(){
        double rabat = liczbaSztuk >= 5 ? 0.1 : 0;
        return cena * liczbaSztuk * rabat;
    }
    double obliczKoszt(){
        return cena * liczbaSztuk - obliczRabat();
    }
};


class Zamowienie{
private :
    ElementZamowienia *elementy;
    int rozmiar;
    int maksRozmiar;

public:
    Zamowienie(int n){
        maksRozmiar = n;
        rozmiar = 0;
        elementy = new ElementZamowienia[n];
    }

    ~Zamowienie(){
        delete[]elementy;
    }

    bool dodaj(const ElementZamowienia &p){
        bool operacja = false;
        if(rozmiar < maksRozmiar){
        elementy[rozmiar] = p;
        rozmiar ++;
            operacja = true;
        }
        return operacja;
    }

    double obliczKoszt(){
        double kosztCalkowity = 0;
        for(int i = 0; i < rozmiar ; i++){
            kosztCalkowity += elementy[i].obliczKoszt();
        }

        return kosztCalkowity;
    }

    void pisz(){
        double rabatNaliczony = 0;
        for(int i =  0 ; i < rozmiar; i++){
            cout <<"  "<< i + 1 << " " << elementy[i].toString();
            rabatNaliczony += elementy[i].obliczRabat();
        }
        cout << "Koszt ca³kowity: " << obliczKoszt() <<endl;
        cout << "Nalicony rabat: " << rabatNaliczony << endl;
    }
};
int main()
{
    Zamowienie z(10);
    z.dodaj(ElementZamowienia("Chleb", 4.0, 2));
    z.dodaj(ElementZamowienia("Mleko", 2.5, 1));
    z.dodaj(ElementZamowienia("Cukier", 4.0, 5));
    z.dodaj(ElementZamowienia("Papierosy", 9.0, 1));
    z.pisz();
return 0;
}
