#include <iostream>
#include <string>
#include <iomanip>

#define SIZE 100



int main(){
    char str[100];

    std::cout << "Input: ";
    std::cin.getline(str, SIZE);
    std::cout << str << "\n";

    std::cout << std::left << std::setw(9) << std::setfill('0') << "1.234" <<"\n";

    std::cout << std::fixed << std::setprecision(2) << 1.234;


    
    return 0;
}