#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <math.h>
#include <cstring>




using namespace std;
void exercise1(){
double numbers [10];
srand(time(NULL));
double sum = 0 ;
double average = 0;
int moreThanAverage = 0, lessThanAverage = 0;

for(int i = 0; i < 10; i++){
    numbers[i] = ((double) rand()*(6.0)/(double)RAND_MAX+3.0);
    sum+= numbers[i];
}

    average = sum/10;
    cout << "Average " << average << endl;

for(int i = 0; i < 10; i++){

    if(numbers[i] > average){
        moreThanAverage++;
    }
    else if(numbers[i] < average){
        lessThanAverage++;
    }


    cout << numbers[i] << " " ;

}
cout<<endl;
for(int i=9;i>=0;i--){
    cout << numbers[i] << " ";
}
cout <<endl;
cout<<"More than average " <<moreThanAverage << endl;
cout<<"Less than average " <<lessThanAverage << endl;


}

int countBits(int number){
    return log2(number)+1;
}

void exercise2(){
    int number;
    cout << "Enter integer  "<<endl;
    cin >> number;
    int decimal = number;
    number = abs(number);
    int tabLength = countBits(number);
    char binaryArray[tabLength];

    int i = 0;
    while(number > 0){
        if(number % 2 == 0){
            binaryArray[i] = '0';
        }
        else {
            binaryArray[i] = '1';
        }
        number = number / 2;
        i++;
    }
    string result ;

    if(decimal > 0){
        result = "0.";
    }
    else if(decimal < 0 ) {
        result = "1.";
    }
    for(int j = tabLength - 1 ; j >= 0; j--){
        result += binaryArray[j];
    }

    cout << "Number " << decimal << " is " << result <<  " in binary" << endl;


}


void exercise3(){
int matrix [5][5];
int mini[5] ;

srand(time(NULL));
for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
        matrix[i][j] = rand()% (11) - 5 ;
    }
}

for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
        cout << matrix[i][j] << "\t" ;
    }
    cout << endl;
}
cout << endl;

int primaryDiagonalMax = matrix[0][0];
int secondaryDiagonalMax = matrix[0][4];

for(int i = 0; i < 5; i++){
    mini[i] = matrix[0][i];


    for(int j = 0; j < 5; j++){
        if(matrix[j][i] < mini[i]){
            mini[i] = matrix[j][i];
        }

        if(i == j && matrix[i][j] > primaryDiagonalMax){
                primaryDiagonalMax = matrix[i][j];
            }

        if ((i + j) == 4 && matrix[i][j] > secondaryDiagonalMax) {
            secondaryDiagonalMax = matrix[i][j];
        }

    }

printf("Smallest element in %d column is %d\n",i+1,mini[i]);

    }
    printf("Maximum value on primary diagonal is %d \n",primaryDiagonalMax);
    printf("Maximum value on secondary diagonal is %d \n",secondaryDiagonalMax);

}
bool isVowel(char x){
    bool result = false;
    x = tolower(x);
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y'){
        result = true;
    }
    return result;
}
void exercise4(){
char sign;
int whitespaceCounter = 0, letterCounter = 0, vowelCounter = 0,digitSum = 0;
int number ;

cout << "Enter a text" << endl;
while(cin.get(sign)){

    if(isspace(sign)){
        whitespaceCounter++;
    }
    if(isalpha(sign)){
        letterCounter++;
    }
    if(isVowel(sign)){
        vowelCounter++;
    }
    if(isdigit(sign)){
        number = sign - '0';
        digitSum += number ;
    }

}
printf("Whitespace characters : %d\n",whitespaceCounter-1);
printf("Letters : %d\n",letterCounter);
printf("Vowels : %d\n",vowelCounter);
printf("Sum of digits: %d\n",digitSum);
}


void exercise5(){
string text;
do{
    cout << "Input text" << endl;
    getline(cin,text);
}while(text.size() > 40);

int counter = 0;



for(int i = 0, j = text.length()-1; i < j ; i++, j-- ){
        if(tolower(text[i]) != tolower(text[j])){
            counter ++ ;
        }
}

if(counter == 0){
    cout << "Text is palindrome" << endl;
}
else{
    printf("To get palindrome you have to replace %d letter(s)", counter);
}


}
int main()
{

    exercise5();
    return 0;
}
