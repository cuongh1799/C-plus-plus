#include <iostream>
#include <string>

//wtf cau c Clueless

void constructorCalled(){
    std::cout << "Constructor called\n";
}

void destructorCalled(){
    std::cout << "Destructor called\n";
}

class Student{
    public: 
        std::string name;
        int studentID;

        Student(){
            constructorCalled();
        };
        Student(std::string nameInput, int idInput){
            constructorCalled();
            name = nameInput;
            studentID = idInput;
        }

        std::string toString(){
            return "Student name: " + name + ", studentID: " + std::to_string(studentID) + "\n";
        }

        ~Student(){
            destructorCalled();
        }
};

class Staff{
    public:
        std::string name;
        int staffID;
    
        Staff(){
            constructorCalled();
        };
        Staff(std::string staffInput, int idInput){
            constructorCalled();
            name = staffInput;
            staffID = idInput;
        }

        std::string toString(){
            return  "Staff name: " + name + ", staffID: " + std::to_string(staffID) + "\n";
        }

        ~Staff(){
            destructorCalled();
        }
};

class Tutor : public Student, public Staff{
    public:
        // Tutor(){
        //     constructorCalled();
        // };

        Tutor(std::string name = "", int tutorID = 0):Student(name, tutorID){
            constructorCalled();
        }

        void consultation(){
            std::cout << Student::name << " is doing consultation" << std::endl;
        }

        void setname(std::string nameTutor){
            Student::name = nameTutor;
        }
        ~Tutor(){
            destructorCalled();
        }
};

void showinfoStudent(Student &stu){
    std::cout << stu.toString();
}

void showinfoStaff(Staff &sta){
    std::cout << sta.toString();
}

int main(int argc, char *argv[]){

    Student test("john", 1);
    showinfoStudent(test);
    
    Staff test2("steve", 4);
    showinfoStaff(test2);
    
    Tutor test3;
    test3.setname("Meow");
    std::cout << test3.Student::name << std::endl;
    test3.consultation();
    showinfoStudent(test);
}