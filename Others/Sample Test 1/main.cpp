#include <iostream>
#include <string>
#include <string.h>


using namespace std;
void convert(char arr[]){
    int counter = 0;
    for(int i = 0; arr[i] != '\0'; i++){
        if(isdigit(arr[i])){
            if(arr[i] % 2 == 0){
                arr[i] = '.';
                counter++;
            }
            else if(arr[i+1] != '\0'){
                arr[i] = arr[i + 1];
                counter ++ ;
            }
        }
        if(arr[i] == 'P' || arr[i] == 'p' || arr[i] == 'D' || arr[i] =='d'){
            arr[i] = '*';
            counter++;
        }
    }
    cout << arr << endl;
    cout << "Change counter: " << counter << endl;

}

int sum(char s[]){
    int result = 0, temp;

    for(int i = 0; s[i] != '\0'; i++){
         if(isdigit(s[i])){
            temp = s[i] - '0';
            result += temp;
         }
    }
    return result;
}
int main()
{
    //char x [65] = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789";
    //convert(x);

    cout << sum("0123") << endl;
    cout << sum("01010101") << endl;
    cout << sum("a 1 b 2 c 3 d 4 g 5 i 6 k 7 m") << endl;


    return 0;
}
