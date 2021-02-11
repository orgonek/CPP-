#include <iostream>
#include <math.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>


using namespace std;

class Wektor{
    private:
        double x;
        double y;
    public :
        double getX(){
        return x;
        }

        double getY(){
        return y;
        }

        Wektor(){
            x = 0;
            y = 0;
        }
        Wektor(double x1, double y1){
            x = x1;
            y = y1;
        }
        Wektor pomnoz(double a){
            return Wektor(a*x, a*y);
        }
        Wektor dodaj(const Wektor &w){
            return Wektor(x + w.x, y + w.y);
        }
        Wektor odejmij(const Wektor &w){
            return Wektor(x - w.x, y - w.y);
        }
        Wektor normalizuj(){
            return Wektor(x/dlugosc(), y/dlugosc());
        }

        double dlugosc(){
            return sqrt((x*x) + (y*y));
        }



        string toString(){
            stringstream  format;
            format << "[" << std::setprecision(2) <<  x << ", " << std::setprecision(2) <<  y << "]";
            return format.str();

        }


};


int main()
{
    Wektor w1(2, 4),w2(1, 0);
cout << "w1 = " << w1.toString() << " w2 = " << w2.toString() << endl;
cout << "d³. w1 = " << w1.dlugosc() << " d³. w2 = " << w2.dlugosc() << endl;
cout << "w1 + w2 = " << w1.dodaj(w2).toString() << endl;
cout << "w1 - w2 = " << w1.odejmij(w2).toString() << endl;
cout << "w1 * -2 = " << w1.pomnoz(-2).toString() << endl;
cout << "w1 po normalizacji = " << w1.normalizuj().toString() << endl;
cout << "w2 po normalizacji = " << w2.normalizuj().toString() << endl;
cout << "w1 * 2 - w2 = " << w1.pomnoz(2).odejmij(w2).toString() << endl;
    return 0;
}
