#include <iostream>

class Broker{
    public:
    std::string name;
    int buyPrice;
    Broker* nextBuyer;

    Broker(std::string nameInput, int buyPriceInput) : name(nameInput), buyPrice(buyPriceInput) {};
};

void printFoward(Broker *temp){
    std::cout << temp->name << ": initially bought the house for $" << temp->buyPrice << std::endl;
    while(1){
        if(temp->nextBuyer != nullptr){
            std::cout << temp->name << " --> ";
            //advance the temp pointer by reassign it to nextBuyer, which contain the next node address
            temp = temp->nextBuyer;
            std::cout << temp->name << " : price = $" << temp->buyPrice << std::endl;
        }
        else if(temp->nextBuyer == nullptr){
            break;
        }   
    }
}

void lowestProfit(Broker *temp){
    Broker *lowestProfit = temp;
    while(1){
        if(temp->nextBuyer->nextBuyer != nullptr){
           if((temp->nextBuyer->buyPrice - temp->buyPrice) > (temp->nextBuyer->nextBuyer->buyPrice - temp->nextBuyer->buyPrice)){
                lowestProfit = temp->nextBuyer;
                temp = temp->nextBuyer;
           }

           else{
                temp = temp->nextBuyer;
            }
        }
        else if(temp->nextBuyer->nextBuyer == nullptr){
            break;
        }
        
        
    }
    std::cout << "Lowest profit: " << lowestProfit->name << std::endl;

}

int main(int argc, char* agrv[]){
    Broker node1("David", 800);
    Broker node2("John", 1000);
    Broker node3("Peter", 1200);
    Broker node4("Luna", 1800);
    Broker node5("Sophia", 3500);

    // pointer head have reference of node1
    // temp has the pointer head which has the address of node1
    Broker* head = &node1;
    Broker* temp = head;    

    // linkedlist
    node1.nextBuyer = &node2;
    node2.nextBuyer = &node3;
    node3.nextBuyer = &node4;
    node4.nextBuyer = &node5;
    node5.nextBuyer = nullptr;

    printFoward(temp);
    lowestProfit(temp);
}