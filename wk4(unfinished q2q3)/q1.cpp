#include <iostream>
#include <cmath>

class ComplNum {
    private:
    double real;
    double imag;

    public:
    //get real
    int getReal(){
        return real;
    }

    //get imag
    double getImag(){
        return imag;
    }

    //default constructor (0,0)
    ComplNum(){ 
        this->real = 0;
        this->imag = 0;
    }

    //assigning attribute constructor
    ComplNum(double realInput, double imagInput){
        this->real = realInput;
        this->imag = imagInput;
    }
    
    //print out the complex number
    void printCompl(){
        if(imag >= 0){
            std::cout << "your number is " << real << "+" << imag << "i\n";
        }
        else if(imag < 0){
            std::cout << "your number is " << real << imag << "i\n";
        }
        
    }

    //overloading operator
    friend ComplNum operator -(ComplNum num1, ComplNum num2);
    friend ComplNum operator -(ComplNum num1, double num2);
    friend ComplNum operator -(double num1, ComplNum num2);

    //decrement
    ComplNum operator --(){
        real--;
        return *this;
    };

    ComplNum operator --(int){
        real--;
        return *this;
    };


    
};

// object - object
ComplNum operator -(ComplNum num1, ComplNum num2){
    ComplNum temp;
    temp.real = num1.getReal() - num2.getReal();
    temp.imag = num1.getImag() - num2.getImag();
    return temp;
}

//object - double
ComplNum operator -(ComplNum num1, double num2){
    double real = (num1.getReal()) - num2;
    ComplNum temp(real, num1.getImag());
    return temp;
}

//double - object
ComplNum operator -(double num1, ComplNum num2){
    double real = num1 - num2.getReal();
    ComplNum temp(real, num2.getImag());
    return temp;
}


//absolute value
int complAbsolute(ComplNum num1){
        int result = num1.getReal() * num1.getReal() + num1.getImag() * num1.getImag();
        int final = sqrt(result);
        return final;
    }    

int main(int argc, char const *argv[]){

    ComplNum test;
    ComplNum test2(1, 3.2);
    ComplNum test3(3, 2.4);

    ComplNum result3 = test3 - 2.7;
    result3.printCompl();
    std::cout << "Absolute value is " << complAbsolute(test3);

    ComplNum test4 = test2--;
    test4.printCompl();

    ComplNum test5 = --test2;
    test5.printCompl();
    return 0;
}