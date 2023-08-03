#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char const *argv[]){
    int choice;
    std::string pwd; 
    std::string inputpwd;
    std::fstream myfile;

    std::cout << "Password management program:" << "\n";
    std::cout << "1. Save your password\n" << "2. Read your password\n";
    std::cout << "Your choice: ";
    std::cin >> choice;
    std::cin.ignore(1000, '\n');
    if(choice ==1){
        myfile.open("mypassword.dat", std::ios::out);
        std::cout << "Enter the password: ";
        std::getline(std::cin, inputpwd);
        myfile << inputpwd;
        std::cout << "Saved to the file!";
        myfile.close();
    }
    else if(choice == 2){
        myfile.open("mypassword.dat", std::ios::in);
        std::getline(myfile, pwd);
        std::cout << "Your password is: " << pwd;
        myfile.close();
    }
    
    return 0;
}