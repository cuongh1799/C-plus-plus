#include <iostream>

class Student {
public:
    int score;
};

int main() {
    int size;
    std::cout << "Enter total number of students: ";
    std::cin >> size;

    //memory allocation for an array
    Student* ptr = new Student[size];

    //store and read values
    std::cout << "Enter scores of students:" << "\n";

    for (int i = 0; i < size; ++i) {
        std::cout << "Student" << i + 1 << ": ";
        std::cin >> ptr[i].score; //store values
        std::cout << "> Stored: " << ptr[i].score << "\n"; //read values
    }

    //free up memory location (allocated for ptr before)
    delete[] ptr;
    return 0;
}