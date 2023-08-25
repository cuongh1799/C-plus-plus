#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    int availableCopies;
    vector<string> namesOfBorrowers;

public:
    Book()
    {
    }
    Book(string title, int availableCopies, vector<string> namesOfBorrowers) : title(title), availableCopies(availableCopies), namesOfBorrowers(namesOfBorrowers)
    {
    }
    friend class User;
};

class User{
private:
    string name;
    vector<Book *> borrowedBooks;

public:
    User()
    {
    }
    User(string name, vector<Book *> borrowedBooks) : name(name), borrowedBooks(borrowedBooks)
    {
    }
    bool doBorrow(Book &abook)
    {
        if (abook.availableCopies == 0)
        {
            cout << "No more copy";
            return false;
        }
        else
        {
            borrowedBooks.push_back(&abook);
            abook.namesOfBorrowers.push_back(name);
            abook.availableCopies--;
            return true;
        }
    }

	int lenght = borrowedBooks.size();
    void doReturn(Book &abook) {
        for (int i = 0; i < borrowedBooks.size(); i++) {
            if (borrowedBooks[i]->title.compare(abook.title)==0) {
                for (int j = 0; j < abook.namesOfBorrowers.size(); j++) {
                    if (abook.namesOfBorrowers[j].compare(name) == 0) {
                        borrowedBooks.erase(borrowedBooks.begin() + i);
                        abook.namesOfBorrowers.erase(abook.namesOfBorrowers.begin() + j);
                        abook.availableCopies++;
                        cout << "Book: " << abook.title << " has returned" << endl;
                    }
                    else {
                        cout << "Name is not match " << endl;
                    }
                }
            }
            else {
                cout << "There is no book in the list" << endl;
            }
        }
    }
};
int main()
{
    vector<Book *> obj = {new Book("harry pot to", 3, vector<string>{}), new Book("harry", 4, vector<string>{}), new Book("hello", 5, vector<string>{})};
    User user1("Bum", vector<Book *>{});
    User user2("Bem", vector<Book *>{});
    user1.doBorrow(*obj[0]);
    user2.doBorrow(*obj[2]);
    user1.doReturn(*obj[2]);
}