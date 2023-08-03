#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#define SIZE 4

void ReturnInvalid(){
    std::cout << "Invalid value";

}

int main(int argc, char* argv[]) {

        //check if the argv lenght is 4 digit
        if(strlen(argv[1]) != 4){
            ReturnInvalid();
            return 1;
        }
    
        //first position
        if(argv[1][0] == '0' ){
        }
        else  {
            ReturnInvalid();
            return 1;
        }
                    
        //second position
        if(argv[1][1] == 'x' || argv[1][1] == 'X'){
        }
        else {
            ReturnInvalid();
            return 1;
        }
        for(int i = 2; i < 4; i++){
            //third position (i = 2)
            if(i == 2){
                if(isdigit(argv[1][i])){continue;} //if digit = pass
                else if(isalpha(argv[1][i])){ //if alphabet 
                    if(argv[1][i] > 'A' && argv[1][i] <= 'F'){ // if from A-F capital = pass
                        continue;
                    }
                else {
            ReturnInvalid();
            return 1;
        }
                }
            }
            //last position
            else if(i == 3){
                if(isdigit(argv[1][i])){ // if digit, cout argv[1]
                    std::cout << "> Got valid hexadecimal value: " << argv[1];
                }
                else if(isalpha(argv[1][i])){ //if alphabet
                    if(argv[1][i] >= 'A' && argv[1][i] <= 'F'){ // if from A-F capital , cout argv
                        std::cout << "> Got valid hexadecimal value: " << argv[1];
                    }
                else  {
            ReturnInvalid();
            return 1;
        }
                }
            }   
        }
    
    return 0;
}
