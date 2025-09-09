#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string ISBN;
    string author;
    int quantity;
    
    Book(string t = "", string isb = "", string n = "", int q = 0) 
        : title(t), ISBN(isb), author(n), quantity(q) {};
};

class Inventory {
    Book* books;
    int count;
    int capacity;
    
    void resize() {
        capacity *= 2;
        Book* newBooks = new Book[capacity];
        for (int i = 0; i < count; ++i) {
            newBooks[i] = books[i];
        }
        delete[] books;
        books = newBooks;
    }
    
public: 
    Inventory() : books(nullptr), count(0), capacity(0) {};
    
    ~Inventory() {
        delete[] books;
    }

    void Add() {
        while (true) {
            cout << "Enter Book's title: ";
            string t;
            getline(cin, t);
            
            cout << "Enter ISBN: ";
            string isb;
            getline(cin, isb);
            
            cout << "Enter Author's name: ";
            string name;
            getline(cin, name);
            
            cout << "Enter quantity of the books to be added: ";
            int q;
            cin >> q;
            while (q < 0) {
                cout << "Sorry! Invalid quantity, Re-Enter: ";
                cin >> q;
            }
            cin.ignore(); 
            
            // Check if we need to resize the array
            if (count >= capacity) {
                if (capacity == 0) capacity = 1;
                resize();
            }
            
            // Add the new book
            books[count++] = Book(t, isb, name, q);
            
            cout << "Do you want to continue (Y/N): ";
            char flag;
            cin.get(flag);
            cin.ignore(); // Clear the input buffer
            
            if (flag == 'N' || flag == 'n') {
                break;
            }
        }
    }

    void Sell() {
        if (count == 0) {
            cout << "Inventory is empty. No books to sell.\n";
            return;
        }
        
        while (true) {
            cout << "Enter Book's title: ";
            string t;
            getline(cin, t);
            
            cout << "Enter quantity of the books to be sold: ";
            int q;
            cin >> q;
            while (q < 0) {
                cout << "Sorry! Invalid quantity, Re-Enter: ";
                cin >> q;
            }
            cin.ignore(); 
            
            bool found = false;
            for (int i = 0; i < count; ++i) {
                if (books[i].title == t) {
                    found = true;
                    if (books[i].quantity >= q) {
                        books[i].quantity -= q;
                        cout << "Sold " << q << " copies of " << t << endl;
                        cout << "Remaining quantity: " << books[i].quantity << endl;
                    } else {
                        cout << "Not enough stock. Only " << books[i].quantity << " available.\n";
                    }
                    break;
                }
            }
            
            if (!found) {
                cout << "Book not found in inventory.\n";
            }
            
            cout << "Do you want to continue (Y/N): ";
            char flag;
            cin.get(flag);
            cin.ignore(); 
            
            if (flag == 'N' || flag == 'n') {
                break;
            }
        }
    }

    void display() {
        if (count == 0) {
            cout << "Inventory is empty.\n";
            return;
        }
        
        cout << "\n--- Inventory List ---\n";
        for (int i = 0; i < count; ++i) {
            if (books[i].title != "") { // Skip deleted books
                cout << "Title: " << books[i].title << "\n"
                     << "ISBN: " << books[i].ISBN << "\n"
                     << "Author's name: " << books[i].author << "\n"
                     << "Quantity: " << books[i].quantity << "\n\n";
            }
        }
    }

    void search(string t) {
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (books[i].title == t && books[i].title != "") {
                cout << "Book found!\n";
                cout << "Title: " << books[i].title << "\n"
                     << "ISBN: " << books[i].ISBN << "\n"
                     << "Author's name: " << books[i].author << "\n"
                     << "Quantity: " << books[i].quantity << "\n";
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "Not Available\n";
        }
    }

    void deletebook(string t) {
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (books[i].title == t && books[i].title != "") {
                books[i].title = "";
                books[i].ISBN = "";
                books[i].author = "";
                books[i].quantity = 0;
                cout << "Book deleted successfully.\n";
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "Book not found in inventory.\n";
        }
    }

    void reporting() {
        if (count == 0) {
            cout << "Inventory is empty.\n";
            return;
        }
        
        cout << "\n--- Inventory Report ---\n";
        int totalBooks = 0;
        
        for (int i = 0; i < count; ++i) {
            if (books[i].title != "") { // Skip deleted books
                cout << "Title: " << books[i].title << "\n"
                     << "ISBN: " << books[i].ISBN << "\n"
                     << "Author's name: " << books[i].author << "\n"
                     << "Quantity: " << books[i].quantity << "\n\n";
                totalBooks += books[i].quantity;
            }
        }
        
        cout << "Total books in inventory: " << totalBooks << endl;
    }
};

int main() {
    Inventory invent;
    int choice;
    
    do {
        cout << "\nEnter your choice from below to proceed:\n"
             << "1. Add\n"
             << "2. Delete\n"
             << "3. Display\n"
             << "4. Search\n"
             << "5. Reporting\n"
             << "6. Sell\n"
             << "7. Exit\n"
             << "Choice: ";
             
        cin >> choice;
        cin.ignore(); // Clear the input buffer
        
        while (choice < 1 || choice > 7) {
            cout << "Invalid value! Re-Enter: ";
            cin >> choice;
            cin.ignore();
        }

        switch (choice) {
            case 1: 
                invent.Add();
                break;
            case 2: {
                cout << "Enter title of the book to delete: ";
                string n;
                getline(cin, n);
                invent.deletebook(n);
                break;
            }
            case 3: 
                invent.display();
                break;
            case 4: {
                cout << "Enter title of the book to search: ";
                string n;
                getline(cin, n);
                invent.search(n);
                break;
            }
            case 5: 
                invent.reporting();
                break;
            case 6:
                invent.Sell();
                break;
            case 7:
                cout << "Exiting program. Goodbye!\n";
                break;
            default: 
                cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
