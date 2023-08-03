#include <iostream>
#include <string>

class Book{
    private:
        std::string name;
        int price;

    public:
        Book(){}
        Book(std::string nameInput, int priceInput){
            this->name = nameInput;
            this->price = priceInput;
        }
        friend std::istream& operator >>(std::istream& input, Book& test);
        friend bool operator >(Book& test1, Book& test2);
        
        void showInfo(){
            std::cout << "Book name: " << name << ", price: " << price << std::endl;
        }

        void setName(std::string Input){
            this->name = Input;
        }

        void setPrice(int Input){
            this->price = Input;
        }
    ~Book(){
        std::cout << "destructor called" << std::endl;
    }
};


std::istream& operator >>(std::istream& input, Book& test){
    std::getline(input, test.name, ',');
    input >> test.price;
    return input;
}

bool operator >(Book& test1, Book& test2){
    if(test1.price > test2.price){
        return true;
    }
    else return false;
}

int main(int argc, char *argv[]){
    // Book* ptr = new (std::nothrow) Book[3];
    // if(ptr == nullptr){
    //         std::cerr << "Error, NULL function found.";
    //     }

    // for(int i = 0; i < 3; i++){
    //     std::cout << "Enter book name, book price: ";
    //     std::cin >> ptr[i];
    //     std::cin.ignore(1, '\n');
    // }

    // for(int i = 0; i < 3; i++){
    //     ptr[i].showInfo();
    // }

    int n;
    std::cout << "Please enter value for 'n': ";
    std::cin >> n;
    std::cin.ignore(1, '\n');

    Book* ptrArray = new (std::nothrow) Book[n];
    for(int i = 0; i < n; i++){
        std::cout << "Enter book name, book price: ";
        std::cin >> ptrArray[i];
        std::cin.ignore(1, '\n');
    }

    Book Highestprice = ptrArray[0];
    for(int i = 0; i < n; i++){
        if(ptrArray[i] > Highestprice){
            Highestprice = ptrArray[i];
        }
    }
    Highestprice.showInfo();
    
}