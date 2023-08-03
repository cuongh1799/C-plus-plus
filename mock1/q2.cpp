#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

class Student{
    private:
        std::string name;
        int score[3];
    public:
        //DEFAULT CONSTRUCTOR
        Student(){}

        //CONSTRUCTOR, SET POINTER VALUE (PRIVATE) TO INPUT
        Student(std::string nameInput, int scoreInput1, int scoreInput2, int scoreInput3){
            this->name = nameInput;
            this->score[0] = scoreInput1;
            this->score[1] = scoreInput2;
            this->score[2] = scoreInput3;
        }

        //ASK USER FOR DATA
        void inputdata(){
            std::cout << "Please enter student's name, 1st score, 2nd score, 3rd score" << std::endl;
        }

        //OUTPUT OBJECT NAME AND SCORES
        void showinfo(){
            std::cout << "Student Name: " << name << std::endl;
            std::cout << "Score: " << score[0] << " " << score[1] << " " << score[2] << std::endl;
        }

        //FRIEND OPERATOR
        friend std::istream& operator >>(std::istream& inputStream, Student& test);
        friend std::ostream& operator <<(std::ostream& outputStream, Student& test);
        friend bool operator >(Student test1, Student test2);
        friend Student operator >>(std::string, Student test);
        friend Student operator +(int n, Student test);

        //SETTER
        void setName(std::string nameInput){
            this->name = nameInput;
        }

        void setScore1(int Input){
            this->score[0] = Input;
        }

        void setScore2(int Input){
            this->score[1] = Input;
        }

        void setScore3(int Input){
            this->score[2] = Input;
        }

};

//CIN >> OBJECT
//INPUT STREAM METHOD TYPE
//INPUT OBJECT "is"
//EXECUTE inputdata() METHOD 
//STORE DATAS FROM OBJECT "is" TO OBJECT "test" 
//RETURN is (?)
std::istream& operator>>(std::istream& inputStream, Student& test){
    test.inputdata();
    inputStream >> test.name >> test.score[0] >> test.score[1] >> test.score[2];
    return inputStream; 
}


//COUT << OBJECT
//OUTPUT STREAM METHOD TYPE
//RETURN os (?)
std::ostream& operator<<(std::ostream& outputStream, Student& test){
    test.showinfo();
    return outputStream;
}

//OBJECT1 > OBJECT2
//Total1 AND Total2 IS THE SUM OF OBJETC'S SCORE
//IF OBJECT1 > OBJECT2 RETURN TRUE, ELSE RETURN FALSE
bool operator >(Student test1, Student test2){
    double Total1 = test1.score[0] + test1.score[1] + test1.score[2];
    double result1 = Total1/3;

    double Total2 = test2.score[0] + test2.score[1] + test2.score[2];
    double result2 = Total2/3;

    if(result1 > result2){
        return true;
    }
    else return false;
}

//int n + OBJECT, INCREASE ALL SCORE BY n
Student operator +(int n, Student test){
    for(int i = 0; i < 3; i++){
        test.score[i] += n;
    }

    return test;
}

int main(int argc, char *argv[]){

//CREATE AN ARRAY OF 10 STUDENT THEN PRINT OUT HIGHEST AVG SCORE
    Student studArray[10];
    std::fstream myfile;
    myfile.open("data.txt", std::ios::in);
//FOR LOOP 10 TIMES
    for(int i = 0; i < 10; i++){
        //GETLINE AND STORE IT INTO tmp
        std::string tmp;
        std::getline(myfile, tmp);

        //COUNT HOW LONG IS THE NAME (nameLenght)
        //STOP THE COUNT WHEN MEET ','
        //THEN COPY STRINGS FROM tmp TO extractName
        //THEN SET STUDENT NAME TO extractName
        std::string extract;
        int position = 0;
        int nameLenght = 0;
        for(int j = 0; tmp[j] != ',' ; j++){
            position++;
            nameLenght++;
        }
        extract.assign(tmp, 0, nameLenght);
        studArray[i].setName(extract);

        //SKIP THE ","
        position += 1;

        //SETTING SCORES
        //ASSIGN TO A STRING, CHANGE THAT STRING INTO INTEGER
        //SET THE RESULT TO THE OBJECT USING SETTER
        for(int z = 0; z < 3; z++){
            //SKIP THE " "
            position += 1;         
            if(z == 0){
                std::string extractNum1;
                extractNum1.assign(tmp, position, 2);
                studArray[i].setScore1(std::stoi(extractNum1));
                position +=2 ;
                
            }
            else if(z == 1){
                std::string extractNum2;
                extractNum2.assign(tmp, position, 2);
                studArray[i].setScore2(std::stoi(extractNum2));
                position +=2 ;
            }
            else if(z == 2){
                std::string extractNum3;
                extractNum3.assign(tmp, position, 2);
                studArray[i].setScore3(std::stoi(extractNum3));
            }
        }    
    }
    //FIND THE HIGHEST AVG SCORE STUDENT
    Student HighestAvgStudent = studArray[0];
    for(int i = 1; i < 10; i++){
        if(studArray[i - 1] > HighestAvgStudent){
            HighestAvgStudent = studArray[i];
        }
    }
    HighestAvgStudent.showinfo();
}