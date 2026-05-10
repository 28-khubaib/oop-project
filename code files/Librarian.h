#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include <iostream>
#include "Person.h"
#include "Book.h"
#include "Member.h"
#include "Notification.h"

#include "Transaction.h"
using namespace std;

// DERIVED CLASS  inherits from Person
class Librarian : public Person {
public:

    Librarian() {}

    Librarian(string n, int i) : Person(n, i) {
        // Person(n, i) sets name and id
    }

    // override base class display()  polymorphism
    void display(int i) {
        cout << "[" << i << "] Librarian: " << name
             << " | ID: " << id << endl;
    }

    void issueBook(Book& book, Member& member, Transaction& tx) {
        if (!book.available) {
            cout << "Sorry! That book is already checked out." << endl;
            return;
        }
        book.available = false;
        member.borrowedCount++;
        tx.record("Issued [" + book.title + "] to " + member.name);
        Notification n;
        n.send(member.name, "You borrowed: " + book.title);
    }

    void returnBook(Book& book, Member& member, int days, Transaction& tx) {
        book.available = true;
        if (member.borrowedCount > 0) {
            member.borrowedCount--;
        }
    }
};

#endif
