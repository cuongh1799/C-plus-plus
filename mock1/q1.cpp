#include <iostream>
#include <string>
#include <iomanip>

int doubleVal(int x) {
    return 2 * x;
}

double doubleVal(double x) {
    return 2.0 * x;
}

int doubleVal(const std::string& x) {
    return 2 * std::stoi(x, nullptr, 16); //nullptr IS TO IGNORE THE size_t, BASE 16
}

int main(int argc, char* argv[]) {
    // if (argc != 2) {
    //     std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
    //     return 1;
    // }
    
    // std::string input = argv[1];
    
    // try {
    //     if (input.substr(0, 2) == "0x") {
    //         std::cout << "0x" << std::hex << std::uppercase << doubleVal(input.substr(2, 2)) << std::endl;
    //     } else if (input.find('.') != std::string::npos) {
    //         std::cout << std::fixed << std::setprecision(2) << doubleVal(std::stod(input)) << std::endl;
    //     } else {
    //         std::cout << doubleVal(std::stoi(input)) << std::endl;
    //     }
    // } catch (const std::exception& e) {
    //     std::cerr << "Invalid input: " << e.what() << std::endl;
    //     return 1;
    // }
    std::cout << doubleVal("0xAC");
    return 0;
}
