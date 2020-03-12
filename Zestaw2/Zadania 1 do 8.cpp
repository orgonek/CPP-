#include <iostream>
#include <limits.h>

using namespace std;
void zadanie1(){
    float a, b ;
char znakDzialania;
cout << "Podaj pierwsza liczbe" << endl;
cin >> a;
cout << "Jaka operacje chcesz wykonac (+ - * -)";
cin >> znakDzialania;
cout << "Podaj druga liczbe" << endl;
cin >> b ;

switch(znakDzialania){
case '+':
    cout << a + b << endl;
    break;
case '-':
    cout << a - b << endl;
    break;
case '*':
    cout << a * b << endl;
    break;
case '/':
    if(b == 0){
        cout << "Niedozwolona operacja" << endl;
    }
    else{
        cout << a/b <<endl;
    }
    break;
default:
    cout << "Podano nieprawidlowy operator " << endl;
    break;

}

}

void zadanie2(){
int a,b,suma = 0 ,licznik = 0;
cout << "Podaj liczbe" <<endl;
cin >> a ;
do{
cout << "Podaj druga liczbe" <<endl;
cin >> b ;
}while(b < a);

for(int i=a; i <= b ;i++){
    suma += i;
}
cout << suma << endl;

suma = 0;

licznik = a;
while(licznik <= b){
    suma += licznik ;
    licznik++;
}
cout << suma << endl;

suma = 0 ;
licznik = a ;
do{
    suma += licznik;
    licznik++;
}while(licznik <= b);
cout << suma << endl;
}

void zadanie3(){
int maximum = INT_MIN, minimum = INT_MAX, licznik = 0,suma = 0;
int x;
while(true){
    cout << "Podaj liczbe" <<endl;
    cin >> x ;
    if(x == 0){
        break;
    }

    if(x > maximum){
        maximum = x;
    }
    if(x < minimum){
        minimum = x;
    }
    suma += x ;
    licznik++;

}
cout << "Suma min i max to " << minimum + maximum <<endl;
cout << "Srednia wynosi "<< suma/licznik << endl;
}

void zadanie4(){
    char zn;
    int x,y,a,b;
    cout << "Podaj znak wypelnienia"<<endl;
    cin >> zn;
    cout << "Podaj pozycje lewego gornego rogu prostokata x,y "<<endl;
    cin >> x;
    cin >> y;
    cout<<"Podaj dlugosc boku a"<<endl;
    cin >> a;
    cout<<"Podaj dlugosc boku b"<<endl;
    cin >> b;

for(int i = 0; i < y; i++){
    cout<<endl;
}
for(int i = 0; i < a; i++){
    for(int j = 0; j < x -1 ; j++){
        cout << " ";
    }
    for(int k = 0; k < b ; k++){
        cout <<zn;
    }
    cout << endl;
}

}

void zadanie5(){
    int n;
    cout <<"Podaj n " << endl;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            cout<<" ";
        }
        for(int k = 0; k < i*2+1; k++){
            cout<<"*";
        }
        cout<<endl;
    }

}

void zadanie6(){
int n,licznikParzyste = 0,licznikNieparzyst = 0, sumaParzyste = 0, sumaNieparzyste = 0;

cout << "Podaj liczbe" << endl;
cin >> n;

while(n > 0){

    if((n%10)%2 == 0){
        sumaParzyste += n%10;
        licznikParzyste++;
    }
    else{
        sumaNieparzyste += n%10;
        licznikNieparzyst++;
    }
    n = n/10;

}
cout<<"suma cyfr tej liczby wynosi "<< sumaParzyste + sumaNieparzyste<<endl;
cout<<"Stosunek sredniej parzystych do nieparzystych " << (float)(sumaParzyste/licznikParzyste)/ (sumaNieparzyste/licznikNieparzyst);

}

void zadanie7(){
int n, odwrocona = 0, x = 0;
cout << "Podaj liczbe " << endl;
cin >> n;
int wartosc = n;

while(n > 0){
    x = n%10 ;
    n = n/10;
    odwrocona = odwrocona*10 + x;
}
if(wartosc == odwrocona){
    cout << "Cyfry tworza palindrom" << endl;
}
else{
    cout <<"Nie tworza palindromu" <<endl;
}
}

bool czyPierwsza(int n){
bool pierwsza = true;
if(n == 1){
    pierwsza = false;
}
else{
    for(int i = 2;i < n; i++){
        if(n % i == 0){
            pierwsza = false ;
            break;
        }
    }
}
return pierwsza;
}
void zadanie8(){

int n;
    cout << "Podaj liczbe " << endl;
    cin >> n ;

    if(czyPierwsza(n)){
        cout << "Liczba jest pierwsza";
    }
    else{
        cout << "Liczba nie jest pierwsza";
    }
}
int main()
{
zadanie8();

    return 0;
}
