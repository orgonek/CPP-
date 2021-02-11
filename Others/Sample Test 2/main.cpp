#include <iostream>
#include <string.h>

using namespace std;

void convert(char arr[]){
    int counter = 0 ;
    bool isFirst = true ;
    int n = strlen(arr);
    cout << n << endl;
    for(int i = 0; arr[i] << n; i++){
        if(isdigit(arr[i])){
            if(arr[i] % 2 == 0){
                arr[i] = isFirst ? arr[0] : arr[n-1];
                counter ++ ;
                isFirst = !isFirst;
            }
            else{
            arr[i] = '*';
            counter ++ ;
                }
        }
        if(arr[i] == 'P' || arr[i] == 'p' || arr[i] == 'D' || arr[i] == 'd'){
            arr[i] = '.';
            counter++;
        }
    }
    cout << arr << endl;
    cout << "Changes: " << counter << endl;

}
void createAcronym(char str[]){
string acronym = "";
int n = strlen(str);

for(int i = 0; i < n; i++){
    if(isalpha(str[i])){
        acronym += isupper(str[i]) ? str[i] : str[i] - 32 ;
        i++;
        while(str[i] != ' '){
            i++;
        }
    }
}
cout << "Sentence: " << str << "    Acronym; " << acronym << endl;

}

int main()
{
   // char arr [] = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789";
   // convert(arr);
   createAcronym("Rzeczpospolita Polska");
   createAcronym("Wydzial Informatyki i Nauki o Materialach");
   createAcronym("Polski Zwiazek Pilki Noznej");


    return 0;
}
