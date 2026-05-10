#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include "Book.h"
#include "Member.h"
#include "Reservation.h"
#include "Transaction.h"
using namespace std;

class Library {
public:
    Book        catalog[50];
    Member      members[50];
    Reservation reservations[50];
    Transaction tx;
    int bookCount;
    int memberCount;
    int resCount;

    Library() {
        bookCount   = 0;
        memberCount = 0;
        resCount    = 0;
    }

    void addBook(Book b) {
        catalog[bookCount] = b;
        bookCount++;
    }

    void addMember(Member m) {
        members[memberCount] = m;
        memberCount++;
    }

    void showCatalog() {
        cout << "\n=== Book Catalog (" << bookCount << " books) ===" << endl;
        for (int i = 0; i < bookCount; i++) {
            catalog[i].display(i);
        }
    }

    void showMembers() {
        cout << "\n=== Members (" << memberCount << ") ===" << endl;
        for (int i = 0; i < memberCount; i++) {
            members[i].display(i);
        }
    }

    void showReservations() {
        cout << "\n=== Reservations (" << resCount << ") ===" << endl;
        if (resCount == 0) {
            cout << "No reservations yet." << endl;
            return;
        }
        for (int i = 0; i < resCount; i++) {
            reservations[i].display(i);
        }
    }
};

#endif
