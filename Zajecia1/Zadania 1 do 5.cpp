#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void zadanie1(){
 float temperatura;
    cout << "Podaj temperature w stopniach" <<endl;
    cin >> temperatura;
    cout << temperatura <<"C"<<" to " << (1.8*temperatura)+32<<"F"<<endl;
}
void zadanie2(){
    int a,b,c,maks,mini;
    cout << "Podaj pierwsza liczbe"<<endl;
    cin >> a ;
    cout << "Podaj druga liczbe"<<endl;
    cin >> b ;
    cout << "Podaj trzecia liczbe"<<endl;
    cin >> c ;

    if(a >= b && a >= c){
        maks = a ;
    }
    else if(b >= a && b >= c ){
        maks = b;
    }
    else{
        maks = c;
    }


    if(a <= b && a <= c){
        mini = a;
    }
    else if(b <= a && b <= c){
        mini = b;
    }
    else{
        mini = c;
    }

    cout << "Najwieksza liczba to " << maks << endl;
    cout << "Najmniejsza liczba to " << mini << endl;



}
void zadanie3(){
float waga,wzrost;
float bmi;
cout<<"Podaj swoja wage"<<endl;
cin >> waga;
cout<<"Podaj swoj wzrost w centrymetrach "<<endl;
cin >> wzrost;
bmi = (waga/((wzrost*wzrost)/100))*100;
cout<<bmi<<endl;
if(bmi < 18.5){
    cout << "niedowaga"<<endl;
}
else if(bmi >= 18.5 && bmi <= 24.9){
    cout<<"Waga prawid³owa"<<endl;
}
else if(bmi > 24.9){
    cout<<"nadwaga"<<
    endl;
}
}

void zadanie4(){
    double dochod,podatek;
    cout << fixed;
    cout << setprecision(2);
cout <<"Podaj swoj dochod roczny"<<endl;
cin >> dochod;
if(dochod < 85528){
    podatek = (0.18 * dochod) - 556.02 ;
}
else {
    podatek = 14839.02 + (0.32 * (dochod - 85528));
}
cout<<"Podatek wynosi " << podatek << endl;
}

void zadanie5(){

int randomNumber, guess ;

srand(time(NULL));

randomNumber = rand() % 100 + 1;

cout<<randomNumber<<endl;

do {
cout << "Wpisz liczbe " << endl;
cin >> guess ;

    if(guess > randomNumber){
        cout << "Podales za duza wartosc"<<endl;
    }
    else if(guess < randomNumber){
        cout << "Podales za mala wartosc"<<endl;
    }
    else {
        cout << "Gratulacje wygrales"<<endl;
    }
}while(randomNumber != guess);

}

int main()
{
   zadanie5();

}


