#include <iostream>
#include <string>


class Employee{
    public:
    std::string name;
    double salary;

    Employee(std::string nameInput = "", double salaryInput = 0) : name(nameInput), salary(salaryInput){};
    
    void showInfo(){
        std::cout << "Employee's name: " << name << ", salary: " << salary << std::endl;
    }
};

class Manager : public Employee{
    public:
    double allowance;

    // call Employee constructor because Manager inherit from name, salary name from Employee
    // therefore to record the name, we must record it into Employee by using its constructor
    Manager(std::string nameInput = "", double salaryInput = 0, double allowanceInput = 0) 
    : Employee(nameInput, salaryInput), allowance(allowanceInput){};

    void showInfo(){
        std::cout << "Manager's name: " << name << ", salary: " << salary << std::endl;
    }
};

int main(int agr, char* argv[]){
    Employee employee1("John", 1000);
    employee1.showInfo();

    Manager manager0("Wick", 1000, 2000);
    manager0.showInfo();

    Manager* array = new Manager[5];
    array[0] = Manager("Joe", 1000, 3000);
    array[1] = Manager("Boe", 2000, 5000);
    array[2] = Manager("Doe", 3000, 3000);
    array[3] = Manager("Coe", 9000, 1000);
    array[4] = Manager("Loe", 6000, 2000);

    double total = 0;
    for(int i = 0; i < 5; i++){
        total += array[i].salary + array[i].allowance;
    }
    double result = total/5;
    std::cout << "Average total income: " << result;
}