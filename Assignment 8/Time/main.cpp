#include <iostream>
#include <sstream>

using namespace std;


class Czas{
private:
    int godz;
    int minuty;
public :
    int getGodz(){
        return godz;
    }
    int getMinuty(){
    return minuty;
    }
    Czas(int g, int m){
        if(m >= 60){
            godz = g + m/60;
            minuty = m%60;
        }
        else if(g <24 && m < 60){
            godz = g;
            minuty = m;
        }
        else{
            cout <<"Nieprawidlowa wartosc " << endl;
        }
    }
    Czas(string a){
        int tablica [2] = {0,0};
        int pom = 0;
        string wartosc = "";
        for(int i = 0; i < a.length(); i++){
            if(isdigit(a[i])){
                while(isdigit(a[i])){
                    wartosc+=a[i];
                    i++;
                }
                tablica[pom] = stoi(wartosc);
                pom++;
                wartosc = "";


            }
        }
        godz = tablica[0];
        minuty = tablica[1];
    }

    string toString() const{
        stringstream ss;
        ss  << godz << " h " << minuty << " min ";
        return ss.str();

    }

    Czas dodaj(const Czas &t) const{
        return Czas(godz + t.godz, minuty + t.minuty);
    }
    Czas odejmij(const Czas &t) const{
        return Czas(godz - t.godz, minuty - t.minuty);
    }
    Czas pomnoz(int ile) const{
        int m,  h;
        m = minuty * ile;
        h = godz * ile;

        if(m >= 60){
            h = h + m/60;
            m = m%60;
        }

        return Czas(h,m);
    }

    static Czas sumuj(Czas *tab[], int n){
        Czas c(0,0);

        for(int i = 0; i < n; i++){
           c = c.dodaj(*tab[i]);
        }
        return c;
    }

};
int main()
{
Czas t1(10, 56);
Czas t2(0, 123);
cout << "t1 = " << t1.toString() << endl;
cout << "t2 = " << t2.toString() << endl;
cout << "t1 + t2 = " << t1.dodaj(t2).toString() << endl;
cout << "t1 - t2 = " << t1.odejmij(t2).toString() << endl;
cout << "t1 * 2 = " << t1.pomnoz(2).toString() << endl;

Czas *tab[] = { &t1, &t2, &t2 };
cout << "Czas::sumuj dla t1 + t2 + t2 = "<< Czas::sumuj(tab, 3).toString() << endl;
Czas t3("3 h 17 min");
cout << "Konstruktor z ³añcuchem: " << t3.toString() << endl;
return 0;

}
