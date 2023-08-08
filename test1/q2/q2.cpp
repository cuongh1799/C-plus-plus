#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2023-2
  Lab Assessment: 1
  Author: Huynh Bao Cuong
  ID: 3978719
  Compiler used: 8.1.0
  Created  date: 05/08/2023
  Acknowledgement: 
    https://www.tutorialspoint.com/print-leading-zeros-with-cplusplus-output-operator
*/
class Time{
    private:
    unsigned hour, minute;

    public:
    Time(){
        hour = 0;
        minute = 0;
    }

    Time(int hourInput, int minuteInput){
        if(hourInput > 23){
            hour = 0;
        }
        else hour = hourInput;

        if(minuteInput > 59){
            minute = 0;
        }    
        else minute = minuteInput;
    }

    //SETTER AND GETTER
    void setHour(int num){
        hour = num;
    }

    void setMinute(int num){
        minute = num;
    }

    int getHour(){
        return hour;
    }
    int getMinute(){
        return minute;
    }

    void showInfo(){
        std::cout << hour << ":" << minute << std::endl;
    }

    friend Time operator+(Time test1, Time test2);
    friend std::ostream& operator<<(std::ostream& output, Time test);
};

Time operator+(Time test1, Time test2){
    Time result;
    if(test1.minute + test2.minute > 59){
        result.minute = test1.minute + test2.minute - 60;
        result.hour += 1;
    }
    else if(test1.minute + test2.minute <= 59){
        result.minute = test1.minute + test2.minute;
    }

    if(test1.hour + test2.hour > 23){
        result.hour += test1.hour + test2.hour - 24;
    }
    else if(test1.hour + test2.hour <= 23){
        result.hour += test1.hour + test2.hour;
    }
    return result;
}

std::ostream& operator <<(std::ostream& output, Time test){
    output << std::setw(2) << std::setfill('0') <<test.hour << ":" << std::setw(2) << std::setfill('0') << test.minute;
    return output;
}

//LATER DO THE FORMAT EXAMPLE 5:30 TO 05:30
int main(int argc, char* argv[]){
    Time test1(3, 47);
    Time test2(5, 58);
    Time test3 = test1 + test2;
    std::cout << test1 << " + " << test2 << " = " << test3 << std::endl;

    Time arr[4];
    std::fstream myfile;
    myfile.open("data2-1.dat", std::ios::in);
    for(int i = 0; i < 4; i++){
        //CREATE tmp STRING
        //GETLINE AND RECORD IT INTO tmp
        //EXTRACT HOUR AND MINUTE AND RECORD IT INTO hourString and minuteString
        //LET THE stoi() do the trick and use setters
        std::string tmp;
        std::getline(myfile, tmp);

        std::string hourString;
        std::string minuteString;
        hourString.assign(tmp, 0, 2);
        minuteString.assign(tmp, 3, 2);

        arr[i].setHour(std::stoi(hourString));
        arr[i].setMinute(std::stoi(minuteString));

        std::cout << "Time " << i + 1 << " = " << arr[i] << std::endl;
    }

    Time LowestTime = arr[0];
    for(int i = 0; i < 4; i++){
        if(LowestTime.getHour() > arr[i].getHour()){
            LowestTime = arr[i];
        }
        else if(LowestTime.getHour() == arr[i].getHour()){
            if(LowestTime.getMinute() > arr[i].getMinute()){
                LowestTime = arr[i];
            }
        }
    }
    std::cout << "Lowest time = " << LowestTime;
}