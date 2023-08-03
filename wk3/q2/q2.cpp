#include <iostream>
#include <string>
#include <fstream>

class Student{
    private:
    int studentScore;
    std::string password;

    public:
    std::string studentName;
   
    Student(std::string name, int score){
        studentName = name;
        studentScore = score;
        std::cout << "Student name: " << name << "\n";
        std::cout << "Student score: " << score << "\n";
    }

    //get score private
    int getScore(){
        return studentScore;
    }

    //get password private
    std::string getPassword(){
        return password;
    }

    //change password
    void changePwd(){
        std::string inputPassword;
        std::fstream myfile;
        myfile.open(studentName + ".dat", std::ios::in);

        if(!myfile || myfile.peek() == std::ifstream::traits_type::eof()){
            std::cout << "The password file is missing or password is blank! \n";
            std::cout << "please create a password: ";
            std::getline(std::cin, inputPassword);
            std::ofstream outfile(studentName + ".dat");
            outfile << inputPassword;
        }
        else{
        //get the password since its private
        getPassword();
        std::getline(myfile, password); //then copy the text in myfile to the password

        std::cout << "please enter password: ";
        std::cin >> inputPassword;
        std::cin.ignore(1000,'\n');

            if(inputPassword == password){
                myfile.close();

                std::cout << "enter new password: ";
                std::getline(std::cin, inputPassword);

                myfile.open(studentName + ".dat", std::ios::out);
                myfile << inputPassword;
                std::cout << "Sucess!";
            } 
            else{
                myfile.close();
                std::cout << "Incorrect password";
            }

        }

    }

};

int main(){
    /* 2a
    Student student1("John", 8), student2("James", 10);
    */
    
    Student studentArray[3] = {Student("Dave", 12), Student("Joe", 1), Student("Donald", 9)};

    /* 2c
    Student HighestScoreST = studentArray[0];
    for(int i = 0; i < 3; i++){
        if(studentArray[i].getScore() > HighestScoreST.getScore()){
            HighestScoreST = studentArray[i];
        }
        else continue;
    }
    
    std::cout << "Student with the highest score is " << HighestScoreST.studentName;
    */


   //   3 test password
    int numchoice;
    std::cout << "who do you want to change their password? (choose number)\n" << "1. Dave\n" << "2. Joe\n" << "3. Donald\n";
    std::cin >> numchoice;
    if(numchoice == 1){
        studentArray[0].changePwd();
    }
    else if (numchoice== 2){
        studentArray[1].changePwd();
    }
    else if (numchoice == 3){
        studentArray[2].changePwd();
    }
    else std::cout << "Error";
    
    return 0;
}