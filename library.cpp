#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

class Book {
    string title;
    string author;
    int publicationYear;

public:
    Book(string t, string a, int year) {
        title = t;
        author = a;
        publicationYear = year;
    }

    void displayDetails() const {
        cout << "Title: " << title << " | Author: " << author << " | Year: " << publicationYear << "\n";
    }

    string getTitle() const {
        return title;
    }
};

class Library {
    vector<Book> books;

public:
    void addBook(const Book& newBook) {
        books.push_back(newBook);
        cout << "\n[Success] Book added successfully!\n";
    }

    void displayLibrary() const {
        if (books.empty()) {
            cout << "\n[Info] The library is currently empty.\n";
            return;
        }

        cout << "\n================ LIBRARY CATALOG ================\n";
        for (size_t i = 0; i < books.size(); i++) {
            cout << i + 1 << ". ";
            books[i].displayDetails();
        }
        cout << "=================================================\n";
    }

    void searchBook(const string& searchTitle) const {
        bool found = false;
        cout << "\n--- Search Results for \"" << searchTitle << "\" ---\n";
        
        for (const auto& book : books) {
            if (book.getTitle().find(searchTitle) != string::npos) {
                book.displayDetails();
                found = true;
            }
        }

        if (!found) {
            cout << "[Info] No books found matching that title.\n";
        }
    }

    void removeBook(const string& targetTitle) {
        auto it = remove_if(books.begin(), books.end(), [targetTitle](const Book& book) {
            return book.getTitle() == targetTitle;
        });

        if (it != books.end()) {
            books.erase(it, books.end());
            cout << "\n[Success] Book(s) removed successfully!\n";
        } else {
            cout << "\n[Error] Book not found in the library.\n";
        }
    }

    bool isEmpty() const {
        return books.empty();
    }
};

void showMenu() {
    cout << "\n=================================\n";
    cout << "     LIBRARY MANAGEMENT SYSTEM   \n";
    cout << "=================================\n";
    cout << "1. Add a new book\n";
    cout << "2. Display all books\n";
    cout << "3. Search for a book by title\n";
    cout << "4. Remove a book by title\n";
    cout << "5. Exit\n";
    cout << "=================================\n";
    cout << "Enter your choice (1-5): ";
}

int main() {
    Library myLibrary;
    int choice = 0;

    do {
        showMenu();
        
        if (!(cin >> choice)) {
            cout << "\n[Error] Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(10000, '\n');

        switch (choice) {
            case 1: {
                string title, author;
                int year;

                cout << "\nEnter book title: ";
                getline(cin, title);

                cout << "Enter author name: ";
                getline(cin, author);

                cout << "Enter publication year: ";
                cin >> year;
                cin.ignore(10000, '\n');

                Book newBook(title, author, year);
                myLibrary.addBook(newBook);
                break;
            }
            case 2:
                myLibrary.displayLibrary();
                break;
            case 3: {
                string searchTitle;
                cout << "\nEnter title to search: ";
                getline(cin, searchTitle);
                myLibrary.searchBook(searchTitle);
                break;
            }
            case 4: {
                string removeTitle;
                cout << "\nEnter exact title of the book to remove: ";
                getline(cin, removeTitle);
                myLibrary.removeBook(removeTitle);
                break;
            }
            case 5:
                cout << "\nExiting program. Goodbye!\n";
                break;
            default:
                cout << "\n[Error] Invalid choice! Please select a valid option from 1 to 5.\n";
        }

    } while (choice != 5);

    return 0;
}