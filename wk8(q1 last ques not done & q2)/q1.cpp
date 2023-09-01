#include <iostream>
#include <vector>

class Book{
    private:
    std::string title;
    int availableCopies;
    std::vector<std::string> namesOfBorrowers;

    public:
    
    //constructor
    Book(std::string titleInput = "", int availableCopiesInput = 0, std::vector<std::string> namesofBorrowersInput= {}) :
    title(titleInput), availableCopies(availableCopiesInput), namesOfBorrowers(namesofBorrowersInput){}; 
    int maxCopies = availableCopies;
    //get set
    std::string getTitle(){
        return title;
    }

    //reduce or increase copies
    void reduceCopies(){
        availableCopies--;
    }

    void increaseCopies(){
        availableCopies++;
    }

    //show name , availablecopies, and if availablecopies > 0 then for loop show the name
    void showInfo(){
        std::cout << "The book " << title << " has " << availableCopies << " copies was borrowed by " ;
        if(availableCopies != maxCopies){
            for(int i = 0; i < namesOfBorrowers.size(); i++){
            std::cout << namesOfBorrowers[i] << " ";
            }
        }else if(availableCopies == maxCopies) {
            std::cout << "none" << std::endl;
        }
        
    }
    friend class User;
};

class User{
    public:
    std::string name;
    std::vector<Book*> borrowedBooks;

    User(){};
    User(std::string nameInput, std::vector<Book*> borrowedBooksInput ){
        this->name = nameInput;
        this->borrowedBooks = borrowedBooksInput;
    };

    bool doBook(Book &abook){
        if(abook.availableCopies > 0){
            //add abook to user borrowedbook list
            //reduce abook copies
            //add user name to abook namesofBorrowers list
            borrowedBooks.push_back(&abook);
            abook.reduceCopies();
            abook.namesOfBorrowers.push_back(name);
            std::cout << "Borrowed successed" << std::endl;
            return true;
        }
        //if availablecopies = 0 then execute std::cout
        else if(abook.availableCopies = 0){
            std::cout << "No more copies left!";
            return false;
        }
        
    }

    void doReturn(Book &abook){
        //delete book from borrowedBook list
        //search abook title in borrowbooks list
        int found = 0;
        for(int i = 0; i < borrowedBooks.size(); i++){
            if(abook.getTitle() == borrowedBooks[i]->getTitle()){
                found++;
                borrowedBooks.erase(borrowedBooks.begin() + i);
            }
        }

        //if not found book title in borrowlist then std::cout didnt borrowed
        if(found == 0){
            std::cout << "Bro didn't borrowed the book :skull:" << std::endl;
        }
        else if(found > 0){
            //increase copies
            abook.increaseCopies();

            //remove name from namesOfBorrowers list
            for(int i = 0; i < abook.namesOfBorrowers.size(); i++){
                if(name == abook.namesOfBorrowers[i]){
                    abook.namesOfBorrowers.erase(abook.namesOfBorrowers.begin() + i);
                }
            }
            std::cout << "Return complete! " << std::endl;
        }
    }
};

int main(int argc, char* argv[]){
    std::vector<Book*> books = {
        new Book("Book1", 3, std::vector<std::string>{} ), 
        new Book("Book2", 3, std::vector<std::string>{} ),
        new Book("Book3", 3, std::vector<std::string>{} )
    };
    

   User user1("john", std::vector<Book*>{});
    user1.doBook(*books[0]);
    user1.doReturn(*books[0]);
    user1.doReturn(*books[2]);
   books[0]->showInfo(); 
}