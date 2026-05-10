#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include "LibraryItem.h"
#include "Author.h"
#include "Category.h"
using namespace std;

// DERIVED CLASS  inherits from LibraryItem
class Book : public LibraryItem {
public:
    Author author;
    Category category;

    Book() {
        // calls LibraryItem default constructor automatically
    }

    Book(string t, Author a, Category c) : LibraryItem(t) {
        // LibraryItem(t) sets title and available
        author = a;
        category = c;
    }

    // override the base class display()  this is polymorphism
    void display(int i) {
        cout << "[" << i << "] " << title
             << " | " << author.getName()
             << " | " << category.getGenre()
             << " | " << (available ? "Available" : "Checked Out") << endl;
    }
};

#endif
