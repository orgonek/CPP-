#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>


using namespace std;
int strpos(char tab[],char z){


    int pos = -1;
    for(int i = 0; tab[i] != '\0'; i++){
        if(tab[i] == z){
            pos = i ;
            break;

        }
    }
    return pos;
}
int strint(char tab[]){
    string x = "";
    int number  = 0;
    for(int i = 0; i < strlen(tab);i++){
        if(tab[i] == '-' && isdigit(tab[i+1])){
            x += '-';
        }


        if(isdigit(tab[i])){
            while(isdigit(tab[i])||tab[i] == 'e' || tab[i] == 'i'){
                 if(tab[i] == 'e' && tab[i+1] == '-' || (tab[i] == 'e' && isdigit(tab[i+1]))){
                    x += 'e';
                    i++;
                    }

                x += tab[i];
                i++;
            }

            break;
        }



    }
    try{
        number = stod(x);
    }
    catch(invalid_argument&){

    }

    return number;
    cout << strlen(tab) << endl;
}


int strfind(char where[],char what[]){

    int j = 0,index = -1,temp = -1;
    if(strcmp(where,what) == 0 || what == "" ){
        index = 0;
    }

    else{
    for(int i = 0; i < strlen(where); i++){
        if(what[j] == where[i]){
                index = i ;
                temp = i;
            while(what[j] == where[i] && j < strlen(what) ){
                i++;
                j++;
            }
            if(j == strlen(what)){
                break;
            }
            else{
                i = temp;
                index = -1;
                j = 0;
            }
        }
    }
    }
        return index;
}
void strcut(char * str, int start, int length){
char newStr [length + 1];

for(int i = 0;i < length; i++){
    newStr[i] = str[start+i];
    }

strcpy(str,newStr);
}


bool strprefix(char str1[], char str2[]){
 int i = 0;
    bool isPrefix = true;
    while(i < strlen(str2)){
        if(str1[i] != str2[i]){
            isPrefix = false;
            break;
        }
        i++;
    }
    return isPrefix;
}

int strcountfind(char * where, char * what){
    int whereLen = strlen(where);
    int whatLen = strlen(what);
    int index = -1;
    int counter = 0;

    for(int i = 0; whatLen + i <= whereLen; i++){
        index = i;

        for(int j = 0; j < whatLen; j++){
            if(where[i + j] != what[j]){
                index = -1;
                break;
            }
        }
        if(index != -1){
            counter++;
        }
    }
    return counter;
}


void encrypt(char * text, int shift, char result[]){
    int asciiStart = 0;
    for(int i =0; i < strlen(text);i++){
        if(text[i] >= 65 && text[i] <= 90){
            asciiStart = 65;
        }
        else if(text[i] >=97 && text[i] <= 122){
            asciiStart = 97;
        }

        if(isalpha(text[i])){
            result[i] = ((text[i] + 26 + shift - asciiStart)% 26) + asciiStart;
        }
        else{
        result[i] = text[i];
        }

    }
}
void decrypt(char * text, int shift, char result[]){
    encrypt(text,-shift,result);
}

int strfind2(char where[],char what[]){

    int j = 0,index = -1,temp = -1;
    if(strcmp(where,what) == 0 || what == "" ){
        index = 0;
    }

    else{
    for(int i = 0; i < strlen(where); i++){
        if(tolower(what[j]) == tolower(where[i])){
                index = i ;
                temp = i;
            while(tolower(what[j]) == tolower(where[i]) && j < strlen(what) ){
                i++;
                j++;
            }
            if(j == strlen(what)){
                break;
            }
            else{
                i = temp;
                index = -1;
                j = 0;
                }
            }
        }
    }
        return index;
}

void display(char * arr){
    for(int i = 0; i < strlen(arr);i++){
        cout << arr[i];
    }
}


int main()
{
   cout << strint("")   << endl;

   return 0;
}
