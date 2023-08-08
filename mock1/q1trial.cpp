#include <iostream>
#include <iomanip>
#include <string>
int doubleVal(int num){
    return 2 * num;
}

float doubleVal(float num){
    return 2 * num;
}

int doubleVal(std::string str){
    int num;
    std::string userInput = str;
    num = std::stoi(userInput , nullptr, 16);
    // std::stringstream stringStream;
    // stringStream << std::hex << str;
    // stringStream >> num;
    return 2 * num;
}

int main(int argc, char* argv[]){
    std::string userInput = argv[1];
    if(userInput.substr(0,2) == "0x"){
        std::cout << "0x" << std::hex << doubleVal(userInput);
    }
    else if(userInput.find(',')){
        float num = atof(argv[1]);
        std::cout << std::fixed << std::setprecision(2) <<doubleVal(num);
    }else std::cout << doubleVal(std::stoi(argv[1]));
}