#include <iostream>
#include <string>

class Book{
    private:
        std::string* name = new std::string;
        int price;

    public:
        Book(){}
        Book(std::string nameInput, int priceInput){
            std::cout << nameInput << std::endl;
            *name = nameInput ;
            this->price = priceInput;
        }
        friend std::istream& operator >>(std::istream& input, Book& test);
        friend bool operator >(Book& test1, Book& test2);
        
        void showInfo(){
            std::cout << "Book name: " << *name << ", price: " << price << std::endl;
        }

        void setName(std::string Input){
            *name = Input;
        }

        void setPrice(int Input){
            this->price = Input;
        }
    ~Book(){
        delete name;
        std::cout << "destructor called" << std::endl;
    }
};


std::istream& operator >>(std::istream& input, Book& test){
    std::string nameUserInput;
    std::getline(input, nameUserInput, ',');
    test.name = new std::string(nameUserInput);
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
    // Book test("Harry potter book", 19000);
    // test.showInfo();

    Book* ptr = new (std::nothrow) Book[3];
    if(ptr == nullptr){
            std::cerr << "Error, NULL function found.";
        }

    for(int i = 0; i < 1; i++){
        std::cout << "Enter book name, book price: ";
        std::cin >> ptr[i];
        std::cin.ignore(1, '\n');
    }

    for(int i = 0; i < 1; i++){
        ptr[i].showInfo();
    }

    // int n;
    // std::cout << "Please enter value for 'n': ";
    // std::cin >> n;
    // std::cin.ignore(1, '\n');

    // Book* ptrArray = new (std::nothrow) Book[n];
    // for(int i = 0; i < n; i++){
    //     std::cout << "Enter book name, book price: ";
    //     std::cin >> ptrArray[i];
    //     std::cin.ignore(1, '\n');
    // }

    // Book Highestprice = ptrArray[0];
    // for(int i = 0; i < n; i++){
    //     if(ptrArray[i] > Highestprice){
    //         Highestprice = ptrArray[i];
    //     }
    // }
    // Highestprice.showInfo();
    
}