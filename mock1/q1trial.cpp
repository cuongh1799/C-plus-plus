#include <iostream>
#include <iomanip>
#include <string>

//b and a(string)

int doubleVal(int Input){
    return 2 * Input;
}

double doubleVal(double Input){
    return 2 * Input;
}

std::string doubleVal(std::string Input){
    return Input;
}

int main(int argc, char *argv[]){
    std::string charToString = argv[1];

    if(charToString.find('.') != std::string::npos){
        std::cout << std::fixed << std::left << std::setprecision(2) <<doubleVal(std::stod(charToString));
    }
    else if(charToString.substr(0,2) == "0x"){
        std::cout << "0x" << std::dec << doubleVal(charToString.substr(2,2));
    }
    
    else std::cout << doubleVal(std::stoi(charToString));
}