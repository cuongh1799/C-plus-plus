#include <iostream>
#include <string>

class BankAcc{
    public:
    std::string name;
    float amount;

    BankAcc(std::string nameInput, float amountInput){
        name = nameInput;
        amount = amountInput;
    }

    void showInfo(){
        std::cout << "Account name : " << name << " , amount is " << amount << std::endl;
    }

    void withDraw(float num){
        if(amount >= num){
            amount = amount - num;
        }
        else if (amount < num){
            std::cerr << "Withdrawal amount exceeds current balance\n";
            std::cout << "Error! ";
        }
    }
};

int main(int argc, char const *argv[]){
    // BankAcc acc1("John", 19000);
    // acc1.withDraw(10000);
    // acc1.showInfo();

    // BankAcc acc2("Dave", 29000);
    // acc2.withDraw(10000);
    // acc2.showInfo();

    BankAcc acc3("Jake", 53000);
    acc3.withDraw(60000);
    acc3.showInfo();

}