#include <iostream>
#include <ctype.h>
#include <cstring>
#include <string>
using std::cin;
using std::cout;
#define SIZE 100


int main(){

    // string userinput;
    char userinput[SIZE];
    cout << "Please enter a string: ";
    cin.getline(userinput, SIZE);

    // for(int i = 0; i < userinput.length(); i++){
    //     if(islower(userinput[i])){
    //         userinput[i] = toupper(userinput[i]);
    //     }
    //     else if(isupper(userinput[i])){
    //         userinput[i] = tolower(userinput[i]);
    //     }
    //     else continue;
    // }

    // cout << userinput;

    for(int i = 0; userinput[i] != '\0'; i++ ){
        if( userinput[i] < 96){ 
            userinput[i] = userinput[i] + 32;
        }

        else if(userinput[i] > 96){ 
           userinput[i] = userinput[i] - 32;
        }
    }
        cout <<userinput;

    return 0;

}