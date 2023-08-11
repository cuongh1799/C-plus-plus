#include <iostream>

int main(int argc, char *argv[]){
    unsigned a,b;
    std::cout << "Enter value for 'a': ";
    std::cin >> a;

    while(true){
        try{
            std::cout << "Enter value for 'b': ";
            std::cin.ignore(1,'\n');
            std::cin >> b;
            if(b==0){
                throw 22;
            }
        }
        catch(int errorcode){
            std::cout << "'b' cannot be 0, try again.\n";
        }
    }
}