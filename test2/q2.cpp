
/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2023-2
  Lab Assessment: 2
  Author: Huynh Bao Cuong
  ID: 3978719
  Compiler used:  8.1.0
  Created  date:  (e.g. 09/09/2023)
  Acknowledgement: List the resources that you use to complete this assessment (write 'None' if you don't use any).
*/

#include <iostream>
#include <vector>
#include <iomanip>
#define START 0

class Fruits{
    private:
    std::string name;
    double price;

    public:
    Fruits(std::string name = "", double price = 0) : name(name), price(price){};

    std::string returnName(){
        return name;
    }

    int returnPrice(){
        return price;
    }

    friend class Shop;
    friend class Bill;
};

class Shop {
    private:
    std::string shopName;
    std::vector<Fruits> ShopListFruits;

    public:
    Shop(std::string nameInput = "", std::vector<Fruits> ShopListFruits = {}) 
    : shopName(nameInput) , ShopListFruits(ShopListFruits){};

    void addFruits(Fruits FruitsExample){
        ShopListFruits.push_back(FruitsExample);
    }

    void showList(){
        for(int i = 0; i < ShopListFruits.size(); i++){
            std::cout << ShopListFruits[i].name << ", $" << std::fixed << std::setprecision(2) << ShopListFruits[i].price << std::endl; 
        }
    }

    int findFruitPositionInShopList(std::string userInput){
        int position = 0;
        for(int i = 0; i < ShopListFruits.size(); i++){
            if(userInput.compare(ShopListFruits[i].name) == 0){
                position == i;
                break;
            }
        }
        return position;
    }

    Fruits ReturnFruits(int position){
        return ShopListFruits[position];
    }

    std::string getName(){
        return shopName;
    }

};

class Bill{
    private:
    int billID;
    Fruits fruitBought;
    int quantity;

    public:
    Bill(){};
    Bill(int billIDInput, Fruits fruits){
        this->billID = billIDInput;
        this->fruitBought = fruits;
    }

    void setQuantity(int num){
        this->quantity = num;
    }

    int returnQuantity(){
        return quantity;
    }

    int returnBillID(){
        return billID;
    }

    Fruits returnFruitsBought(){
        return fruitBought;
    }

};

int main(int argc, char* argv[]){
    Fruits* allFruitsList = new Fruits[3];
    std::vector<Bill> theBill;
    allFruitsList[0] = {"Banana", 1.80};
    allFruitsList[1] = {"Apple", 0.90};
    allFruitsList[2] = {"Avocado", 3.00};
    
    Shop shop1("Fruit Store 1", {});
    shop1.addFruits(allFruitsList[0]);
    shop1.addFruits(allFruitsList[1]);
    shop1.addFruits(allFruitsList[2]);

    system("cls");
    std::cout << "Welcome to " << shop1.getName() << "\n" << "\n";
    std::cout << "List of all fruits available\n";
    std::cout << "============================\n";
    shop1.showList();
    std::cout << "============================" << "\n" << "\n";

    int startingpointID = 1;

    while(1){
    std::string userInput;
    std::cout << "Enter item ('Q' to quit) :";
    std::cin >> userInput;

    if(userInput == "Q"){
        double totalAmountPrice = 0;
        int totalAmountofFruits = 0;
        for(int i = 0; i < theBill.size(); i++){
            // std::cout << "Receipt ID: " << theBill[i].returnBillID() << std::endl;
            std::cout << "Bought fruits" << std::endl;
            std::cout << theBill[i].returnBillID() << ". Fruits: " << theBill[i].returnFruitsBought().returnName() << std::endl;
            std::cout << "Quantity: " << theBill[i].returnQuantity() << std::endl;
            totalAmountPrice += theBill[i].returnFruitsBought().returnPrice() * theBill[i].returnQuantity();
            totalAmountofFruits += theBill[i].returnQuantity();
        }

        std::cout << "Total number of item : " << totalAmountofFruits << std::endl;
        std::cout << "Total amount to be paid: $" << std::fixed << std::setprecision(2) << totalAmountPrice << std::endl;
        break;
    }
    else{
        int position = shop1.findFruitPositionInShopList(userInput);
        Fruits temp = shop1.ReturnFruits(position);
        Bill tempBill = {startingpointID, temp};
        startingpointID++;
        std::cout << "Enter quantity: ";
        int userquantityInput;
        std::cin.ignore(1,'\n');
        std::cin >> userquantityInput;
        tempBill.setQuantity(userquantityInput);
        theBill.push_back(tempBill);
        std::cout << std::endl;
        userInput.clear();
    }

    }
}