#include <iostream>
#include <fstream>
#include <string>
/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2023-2
  Lab Assessment: 1
  Author: Huynh Bao Cuong
  ID: 3978719
  Compiler used: 8.1.0
  Created  date: 05/08/2023
  Acknowledgement:
https://www.w3schools.com/cpp/cpp_functions_recursion.asp, 
https://www.geeksforgeeks.org/converting-number-to-string-in-cpp/
https://www.w3schools.com/cpp/cpp_strings_length.asp
*/


int sumDigit(int num){
    if(num > 0){
        return num % 10 + sumDigit(num/10);
    }
    else return 0;
}

//TURN RESULT FROM sumDigit TO STRING, NAMED IT IntConvert
//CREATE ANOTHER STRING NAMED Reverse, COPY VALUE FROM IntConvert TO Reverse ()
bool checkPal(int num){
    int normalResult = sumDigit(num);
    std::string IntConvert = std::to_string(normalResult);
    int lenght = IntConvert.length();
    std::string Reverse;
    for(int i = lenght ; i >= 0; i--){
        Reverse.push_back(IntConvert[i]);
    }
    if(IntConvert == Reverse){
        return true;
    }
    else return false;

}

// std::string RecPal(int num){
//     //help
// }


int main(int argc, char* argv[]){
    int num = 2234;
    std::cout << sumDigit(2234) << std::endl;
    std::fstream myfile;
    myfile.open(argv[1], std::ios::in);
    for(int i = 0; i < 6; i++){
        std::string tmp;
        std::getline(myfile, tmp);
        
        // myfile >> tmp;
        // std::getline(std::cin, numtest);
        std::cout << tmp << ": ";
        int result = sumDigit(std::stoi(tmp));
        if(checkPal(result)){
            std::cout << "Result " <<  result << " is a palindrome." <<std::endl;
        }else std::cout << "Result " <<  result << " is a not palindrome." <<std::endl;
    }
    
  
}