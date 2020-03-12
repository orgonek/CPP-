#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>


using namespace std;

int strpos(char tab[],char z){

//to do
    int pos = -1;
    for(int i = 0; tab[i] != '\0'; i++){
        if(tab[i] == z){
            pos = i ;

        }
    }
    return pos;
}
int strint(char tab[]){

    string x  = "";
    for(int i = 0; tab[i] != '\0'; i++){
            if(tab[i] == '-'){
                x += '-';
            }

        }
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
void strcut(char str[], int od, int ile){


}
bool strprefix(char str1[], char str2[]){

int strcountfind(char where[], char what[]){
    int j = 0,counter = 0,temp = 0;

    for(int i = 0; i < strlen(where); i++){
        if(where[i] == what[j]){
            while()
        }
    }
}
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
int main()
{



    return 0;
}
