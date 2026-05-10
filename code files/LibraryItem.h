#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H
#include <iostream>
#include <string>
using namespace std;

// BASE CLASS
// Book will inherit from this class
class LibraryItem {
public:
    string title;
    bool available;

    LibraryItem() {
        title = "";
        available = true;
    }

    LibraryItem(string t) {
        title = t;
        available = true;
    }

    // virtual means derived classes can override this function
    // this is polymorphism
    virtual void display(int i) {
        cout << "[" << i << "] " << title
             << " | " << (available ? "Available" : "Checked Out") << endl;
    }

    // virtual destructor is good practice with inheritance
    virtual ~LibraryItem() {}
};

#endif
