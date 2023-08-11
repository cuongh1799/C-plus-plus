#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

// void constructorCalled(){
//     std::cout << "Constructor called\n";
// }

// void destructorCalled(){
//     std::cout << "Destructor called\n";
// }

class Student{
    public: 
        std::string name;
        int studentID;

        Student(){
            // constructorCalled();
        };
        Student(std::string nameInput, int idInput){
            // constructorCalled();
            name = nameInput;
            studentID = idInput;
        }

        std::string toString(){
            return "Student name: " + name + ", studentID: " + std::to_string(studentID) + "\n";
        }

        std::string toString2(){
            return name + ", " + std::to_string(studentID) + "\n";
        }

        friend std::istream& operator >>(std::istream& input, Student& test);
        friend std::ostream& operator <<(std::ostream& output, Student& test);

        ~Student(){
            // destructorCalled();
        }
};

std::istream& operator >>(std::istream& input, Student& test){
    std::getline(input ,test.name, ',');
    input >> test.studentID;
    return input;
}

std::ostream& operator <<(std::ostream& output, Student& test){
    output << test.name << test.studentID;
    return output;
}

class SchoolSystem : public Student{
    public:
        std::vector<Student> students;

        void addStudent(){
            std::cout << "Input student name, student ID: ";
            Student tmp;
            std::cin >> tmp;
            std::cin.ignore();
            students.push_back(tmp);
        }

        void removeStudent(){
            int ID;
            std::cout << "Input studentID of student you want to remove: ";
            std::cin >> ID;
            int size = students.vector::size();
            for(int i = 0; i < size; i++){
                if(students[i].studentID == ID){
                    students.erase(students.begin()+i);
                }
            }

        }

        void showVector(){
            int size = students.vector::size();
            for(int i = 0; i < size; i++){
                std::cout << "Student name: " << students[i].name << ", studentID: " << students[i].studentID << std::endl;
            }
        }
};


int main(int argc, char *argv[]){
    SchoolSystem test;
    // test.addStudent();
    // test.addStudent();

    
    unsigned choice;

    std::cout << "School Management System\n";
    std::cout << "1. View all students\n" << "2. Add Student\n" << "3. Remove Student\n" << "4. Exit\n" << "Enter your Choice: ";
    std::cin >> choice;
    std::cin.ignore(1, '\n');

    if(choice == 1){
        std::string tmp;
        std::fstream myfile;
        myfile.open("students.dat", std::ios::in);
        while(std::getline(myfile, tmp, ',')){
            Student tmpStudent;
            tmpStudent.name = tmp;
            myfile >> tmpStudent.studentID;
            myfile.ignore();
            test.students.push_back(tmpStudent);
        }
        for(int i = 0; i < test.students.size() - 1; i++){
            std::cout << test.students[i].toString();
        }

    }
    
    if((choice == 2)){
        std::string tmp;
        std::fstream myfile;
        myfile.open("students.dat", std::ios::in);

        while(1){
            if(myfile.peek() != EOF){
            std::getline(myfile, tmp, ',');
            Student tmpStudent;
            tmpStudent.name = tmp;
            myfile >> tmpStudent.studentID;
            myfile.ignore();
            test.students.push_back(tmpStudent);
            }
            else if(myfile.peek() == EOF){
                break;
            }
        }

        while(std::getline(myfile, tmp, ',')){
            Student tmpStudent;
            tmpStudent.name = tmp;
            myfile >> tmpStudent.studentID;
            myfile.ignore();
            test.students.push_back(tmpStudent);
        }
        myfile.close();
        test.addStudent();
        for(int i = 0; i < test.students.size(); i++){
            std::cout << test.students[i].toString();
        }
        
    }

}