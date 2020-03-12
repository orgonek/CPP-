#include <iostream>
#include<algorithm>
#include <stdarg.h>
#include <math.h>

using namespace std;

double minElement(double tab [], int arraySize){
    double minimum = tab[0];
    for(int i = 1; i < arraySize; i++){
        if(tab[i] < minimum){
            minimum = tab[i];
        }
    }
    return minimum;
}
void max_ref(double tab[], int arraySize, double & wynik ){
     double maximum = tab[0];

    for(int i = 1; i < arraySize; i++){
        if(tab[i] > maximum){
            maximum = tab[i];
        }
    }
    wynik = maximum;
}


int analysis(int tab[],int arraySize,float & median, float & average){
    sort(tab, tab+arraySize);
    int sum = 0;

    if(arraySize % 2 != 0){
        median = tab[(arraySize+1)/2] - 1;
    }
    else{
        median = (tab[(arraySize-1)/2] + tab[(arraySize/2) ]) / 2.0 ;
    }

    for(int i = 0; i < arraySize; i++){
        sum+= tab[i];
        cout<<tab[i]<< " " ;

        }
        cout << "Sum:" << sum << endl;


}

double calculate_polygon(double x,int n, ...){
    double sum = 0, el = 0;
    va_list st;
    va_start(st,n);

    while(n > -1){
        el = va_arg(st,double);
        cout << el <<endl;
        sum += (pow(x,n) * el);
        n -- ;
    }
    va_end(st);
    return sum;
}
void combine(int arr [], int arr2 [], int * resultArr,int arrSize, int arr2Size,int resultArrSize){
    int j = 0;
    for(int i = 0; i < resultArrSize; i++){
        if(i < arrSize){
            resultArr[j] = arr[i];
            j++;
        }
        if(i < arr2Size){
            resultArr[j] = arr2[i];
            j++;

        }
    }

}

long factorial(long n){
    long result = 1;

    for(int i = 1; i <= n; i++){
        result *= i;
    }

    return result;
}

long factorialRecursive(long n){


if(n <= 1){
    return 1;
}
else{
    return factorialRecursive(n-1) * n;
}

}

unsigned fib(unsigned n){
    if(n <= 1){
        return n;
    }

    unsigned last = 1, actual = 1, temp = 0;

    for(int i = 2 ; i <= n; i++){
            temp = actual;
            actual += last;
            last = temp ;
    }
    return actual;
}
unsigned fibRecursive(unsigned n){
    if( n <= 1){
        return n;
    }

    return fibRecursive(n-2) + fibRecursive(n-1);

}



int main()
{

    return 0;
}
