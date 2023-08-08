#include <iostream>
#include <string>
class Student{
    public: 
        std::string name;
        int studentID;
};

class Staff{
    public:
        std::string name;
        int staffID;
};

class Tutor : protected Student, protected Staff{
    public:
        void consultation(){
            std::cout << "Doing consultation";
        }
};

int main(int argc, char *argv[]){

}