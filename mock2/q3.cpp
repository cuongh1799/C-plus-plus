#include <iostream>
#include <vector>
#include <string>
#define SIZE 2
#define shopSIZE 3

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
    std::vector<Product> Cart;

    Customer_Account(std::string nameInput = "", std::string passwordInput = "", std::string AccountTypeInput = "")
: name(nameInput), password(passwordInput), AccountType(AccountTypeInput){};

    void addtoCart(Product productName){
        if(AccountType == "Gold"){
            Product temp = productName;
            temp.price -= temp.price * 5 / 100;
            Cart.push_back(temp);
        }
        else if (AccountType == "Normal"){
            Cart.push_back(productName);
        }
    }

    // void removefromCart(Product productName){
    //     for(int i = 0; i < Cart.size(); i++){
    //         if(Cart[i].name == productName.name){
    //             Cart.erase(Cart.begin() + i);
    //             break;
    //         }
    //     }
    // }

    void showCartList(){
        for(int i = 0; i < Cart.size(); i++){
            std::cout << i+1 << ". " << Cart[i].name << ", price: " << Cart[i].price << std::endl;
        }
    }
};

int main(int argc, char* argv[]){
    Product product1("Apple", 10000);
    Product product2("Banana", 20000);
    Product product3("Spicy Noodle", 30000);

    Shop* shopList = new Shop[shopSIZE];

    shopList[0] = Shop("Agatha", {});
    shopList[0].addProduct(product1);
    shopList[0].addProduct(product2);

    shopList[1] = Shop("Valhalla", {});
    shopList[1].addProduct(product1);

    shopList[2] = Shop("Vinmart", {});
    shopList[2].addProduct(product1);
    shopList[2].addProduct(product2);
    shopList[2].addProduct(product3);
    
    

    Customer_Account* accountlist = new Customer_Account[SIZE];
    accountlist[0] = Customer_Account("John", "testing123", "Gold");
    accountlist[1] = Customer_Account("Wick", "123testing", "Normal");

    // LINE 93 - 122: LOGIN SYSTEM
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
        system("cls");
        std::cout << "Signed in successfully!" << std::endl;
        std::cout << "You are now signed in as " << accountlist[accountID].name;
        std::cout << ". You have " << accountlist[accountID].AccountType << " membership!" <<std::endl;
    } else {
        std::cout << "Sign in failed!";
        return -1;
    }

    // SHOP VIEWING SYSTEM
    int shopchoice;
    for(int i = 0; i < shopSIZE; i++){
        std::cout << i+1 << ". " << shopList[i].name << std::endl;
    }
    std::cout << "What shop do you want to view ? ";
    
    std::cin.ignore(1, '\n');
    std::cin >> shopchoice;
    shopchoice--;
    
    system("cls");
    if(shopchoice <= 3 & shopchoice >= 0){
        std::cout << "You are now viewing " << shopList[shopchoice].name << "!" << std::endl;
        shopList[shopchoice].listProduct();
    }
    else{
        std::cout << "Error!";
        return -1;
    }
    
    // BUYING SYSTEM
    int userchoice;
    std::cout << "Type 1-3 to add product to cart, 0 to exit, 4 to checkout";
}