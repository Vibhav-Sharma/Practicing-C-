#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool available;
    string dueDate;
    double finePerDay;

public:
    Book(string title, string author, string ISBN, string dueDate)
        : title(title), author(author), ISBN(ISBN), dueDate(dueDate), available(true), finePerDay(0.50) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
    bool isAvailable() const { return available; }

    void checkout() {
        if (available) {
            available = false;
            cout << "Book '" << title << "' checked out successfully." << endl;
        } else {
            cout << "Book '" << title << "' is not available for checkout." << endl;
        }
    }

    void returnBook() {
        if (!available) {
            cout << "Book '" << title << "' returned. No fine calculation implemented." << endl;
            available = true;
        } else {
            cout << "Book '" << title << "' is already available." << endl;
        }
    }

    void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Status: " << (available ? "Available" : "Checked Out") << endl;
    }
};

class Library {
private:
    Book* books[100];
    int numBooks;

public:
    Library() : numBooks(0) {
        for (int i = 0; i < 100; ++i) {
            books[i] = nullptr;
        }
    }

    ~Library() {
        for (int i = 0; i < numBooks; ++i) {
            delete books[i];
        }
    }

    void addBook() {
        if (numBooks >= 100) {
            cout << "Library is full. Cannot add more books." << endl;
            return;
        }

        string title, author, ISBN, dueDate;
        cout << "Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Author name: ";
        getline(cin, author);
        cout << "ISBN: ";
        getline(cin, ISBN);
        cout << "Due Date (MM/DD/YYYY): ";
        getline(cin, dueDate);

        books[numBooks++] = new Book(title, author, ISBN, dueDate);
        cout << "Book added successfully!" << endl;
    }

    void searchBookByTitle(const string& title) const {
        bool found = false;
        for (int i = 0; i < numBooks; ++i) {
            if (books[i] != nullptr && books[i]->getTitle() == title) {
                books[i]->displayDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }

    void checkoutBook(const string& title) {
        bool found = false;
        for (int i = 0; i < numBooks; ++i) {
            if (books[i] != nullptr && books[i]->getTitle() == title) {
                books[i]->checkout();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }

    void returnBook(const string& title) {
        bool found = false;
        for (int i = 0; i < numBooks; ++i) {
            if (books[i] != nullptr && books[i]->getTitle() == title) {
                books[i]->returnBook();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }
};

int main() {
    Library library;

    int numBooks;
    cout << "How many books do you want to add: ";
    cin >> numBooks;
    cin.ignore(); // Ignore the newline character left in the buffer

    for (int i = 0; i < numBooks; ++i) {
        library.addBook();
    }

    string searchTitle;
    cout << "\nEnter title to search: ";
    getline(cin, searchTitle);
    library.searchBookByTitle(searchTitle);

    string checkoutTitle;
    cout << "\nEnter title to checkout: ";
    getline(cin, checkoutTitle);
    library.checkoutBook(checkoutTitle);

    string returnTitle;
    cout << "\nEnter title to return: ";
    getline(cin, returnTitle);
    library.returnBook(returnTitle);

    return 0;
}
