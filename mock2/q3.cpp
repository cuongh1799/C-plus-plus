#include <iostream>
#include <vector>
#include <string>
#define SIZE 2

// Shop's product must have its name and unit price recorded
class Product{
    public:
    std::string name;
    int price;

    Product(std::string nameInput = "", int priceInput = 0) 
: name(nameInput), price(priceInput){};
};

class Shop{
    public:
    std::string name;
    std::vector<Product> ProductList;

    Shop(std::string nameInput = "", std::vector<Product>ProductlistInput = {}) 
: name(nameInput), ProductList(ProductlistInput){};

    void addProduct(Product sample){
        ProductList.push_back(sample);
    }

    void listProduct(){
        std::cout << "Here are the shop's list of product: " << std::endl;
        for(int i = 0; i < ProductList.size(); i++){
            std::cout << i+1 << ". " << ProductList[i].name << ", price: " << ProductList[i].price << std::endl;
        }
    }
};

class BoughtProduct{
    public:
    int orderID;
    std::string Product_name;
};

// Account must have name and list of order
// Info of order must have order_id start from 1, list of bought product, total expense
// normal account = no discount
// gold membership = 5% discount all product
// after buying, customer can return product -> update
// accountID is to pinpoint what location in accountlist and use it's data
class Customer_Account{
    public:
    std::string name;
    std::string AccountType;
    std::string password;

    Customer_Account(std::string nameInput = "", std::string passwordInput = "", std::string AccountTypeInput = "")
: name(nameInput), password(passwordInput), AccountType(AccountTypeInput){};
};

int main(int argc, char* argv[]){
    Product product1("Apple", 10000);
    Product product2("Banana", 20000);
    Shop shop1("Agatha", {});
    Shop shop2("Valhalla", {});
    shop1.addProduct(product1);
    shop1.addProduct(product2);
    shop2.addProduct(product1);

    Customer_Account* accountlist = new Customer_Account[SIZE];
    accountlist[0] = Customer_Account("John", "testing123", "Gold");
    accountlist[1] = Customer_Account("Wick", "123testing", "Normal");

    // LINE 71 - 107: LOGIN SYSTEM
    std::cout << "Please enter your Username: ";
    std::string usernameInput;
    int accountID = 0;
    std::cin >> usernameInput;

    // scan if usernameInput is available in accountList
    // every missmatch increment usernamenotMatch
    // If match, meaning usernamenotMatch cant be equal to SIZE, ask for password, else stop program
    int usernamenotMatch = 0;
    for(int i = 0; i < SIZE ; i++){
        if(usernameInput.compare(accountlist[i].name) == 0){
            accountID = i;
            break;
        }
        else usernamenotMatch++;
    }
    if(usernamenotMatch != SIZE){
        std::cout << "Username found!" << std::endl;
        usernameInput.clear();
    }
    else if(usernamenotMatch == SIZE){
        std::cerr << "Username not found!" << std::endl;
        return -1;
    }
    
    std::string passwordInput;
    std::cout << "Please enter your password: ";
    std::cin.ignore(1, '\n');
    std::cin >> passwordInput;

    if(passwordInput.compare(accountlist[accountID].password) == 0){
        std::cout << "Signed in successfully!" << std::endl;
        std::cout << "You are now signed in as " << accountlist[accountID].name;
        std::cout << ". You have " << accountlist[accountID].AccountType << " membership!" <<std::endl;
    } else std::cout << "Sign in failed!";

    //shop1.listProduct();
}