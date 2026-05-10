#include <iostream>
#include <string>
#include "Library.h"
#include "Librarian.h"
using namespace std;

void showMenu() {
    cout << "\n=============================" << endl;
    cout << "  LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "=============================" << endl;
    cout << "1.  View All Books"      << endl;
    cout << "2.  Add a Book"          << endl;
    cout << "3.  View All Members"    << endl;
    cout << "4.  Add a Member"        << endl;
    cout << "5.  Issue a Book"        << endl;
    cout << "6.  Return a Book"       << endl;
    cout << "7.  Reserve a Book"      << endl;
    cout << "8.  View Reservations"   << endl;
    cout << "9.  Update Reservation"  << endl;
    cout << "10. Transaction History" << endl;
    cout << "0.  Exit"                << endl;
    cout << "=============================" << endl;
    cout << "Enter choice: ";
}

// POLYMORPHISM  takes a Person base pointer,
// calls the correct display() for Member OR Librarian automatically
void showPersonInfo(Person* p, int i) {
    p->display(i);
}

// POLYMORPHISM  takes a LibraryItem base pointer,
// calls the correct display() for Book automatically
void showItemInfo(LibraryItem* item, int i) {
    item->display(i);
}

// Uses polymorphism to print all books via LibraryItem* pointer
void showAllBooks(Library& lib) {
    cout << "\n Book Catalog (" << lib.bookCount << " books) " << endl;
    for (int i = 0; i < lib.bookCount; i++) {
        LibraryItem* item = &lib.catalog[i];   // base pointer to derived Book
        showItemInfo(item, i);                  // polymorphic call
    }
}

// Uses polymorphism to print all members via Person* pointer
void showAllMembers(Library& lib) {
    cout << "\n Members (" << lib.memberCount << ") " << endl;
    for (int i = 0; i < lib.memberCount; i++) {
        Person* p = &lib.members[i];           // base pointer to derived Member
        showPersonInfo(p, i);                   // polymorphic call
    }
}

int main() {
    Library lib;
    Librarian librarian("TOM CRUISE", 9001);

    // Pre-loaded books
    lib.addBook(Book("C++ Primer",              Author("Stanley Lippman"),     Category("Programming")));
    lib.addBook(Book("Clean Code",              Author("Robert C. Martin"),    Category("Programming")));
    lib.addBook(Book("1984",                    Author("George Orwell"),       Category("Fiction")));
    lib.addBook(Book("Brave New World",         Author("Aldous Huxley"),       Category("Fiction")));
    lib.addBook(Book("Sapiens",                 Author("Yuval Harari"),        Category("History")));
    lib.addBook(Book("A Brief History of Time", Author("Stephen Hawking"),     Category("Science")));
    lib.addBook(Book("The Great Gatsby",        Author("F. Scott Fitzgerald"), Category("Classic")));
    lib.addBook(Book("Thinking Fast and Slow",  Author("Daniel Kahneman"),     Category("Psychology")));
    lib.addBook(Book("Design Patterns",         Author("Gang of Four"),        Category("Software Eng.")));
    lib.addBook(Book("Intro to Algorithms",     Author("Thomas Cormen"),       Category("Computer Science")));

    // Pre-loaded members
    lib.addMember(Member("Khubaib Gul", 1));
    lib.addMember(Member("Zaid Saleh",  2));
    lib.addMember(Member("Ayesha Khan", 3));
    lib.addMember(Member("Ali Raza",    4));


    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            showAllBooks(lib);
        }

        else if (choice == 2) {
            string t, a, g;
            cout << "Enter title  : "; getline(cin, t);
            cout << "Enter author : "; getline(cin, a);
            cout << "Enter genre  : "; getline(cin, g);
            lib.addBook(Book(t, Author(a), Category(g)));
            cout << "Book added!" << endl;
        }

        else if (choice == 3) {
            showAllMembers(lib);
        }

        else if (choice == 4) {
            string n;
            int id;
            cout << "Enter name : "; getline(cin, n);
            cout << "Enter ID   : "; cin >> id; cin.ignore();
            lib.addMember(Member(n, id));
            cout << "Member added!" << endl;
        }

        else if (choice == 5) {
            showAllBooks(lib);
            cout << "Pick book number: ";
            int bi; cin >> bi; cin.ignore();
            showAllMembers(lib);
            cout << "Pick member number: ";
            int mi; cin >> mi; cin.ignore();
            if (bi >= 0 && bi < lib.bookCount && mi >= 0 && mi < lib.memberCount) {
                librarian.issueBook(lib.catalog[bi], lib.members[mi], lib.tx);
            } else {
                cout << "Invalid selection." << endl;
            }
        }

        else if (choice == 6) {
            showAllBooks(lib);
            cout << "Pick book number to return: ";
            int bi; cin >> bi; cin.ignore();
            showAllMembers(lib);
            cout << "Pick member number: ";
            int mi; cin >> mi; cin.ignore();
            cout << "Overdue days (0 = none): ";
            int days; cin >> days; cin.ignore();
            if (bi >= 0 && bi < lib.bookCount && mi >= 0 && mi < lib.memberCount) {
                librarian.returnBook(lib.catalog[bi], lib.members[mi], days, lib.tx);
            } else {
                cout << "Invalid selection." << endl;
            }
        }

        else if (choice == 7) {
            showAllBooks(lib);
            cout << "Pick book number: ";
            int bi; cin >> bi; cin.ignore();
            showAllMembers(lib);
            cout << "Pick member number: ";
            int mi; cin >> mi; cin.ignore();
            if (bi >= 0 && bi < lib.bookCount && mi >= 0 && mi < lib.memberCount) {
                lib.reservations[lib.resCount].set(lib.members[mi].name, lib.catalog[bi].title);
                lib.resCount++;
                cout << "Reservation placed!" << endl;
            } else {
                cout << "Invalid selection." << endl;
            }
        }

        else if (choice == 8) {
            lib.showReservations();
        }

        else if (choice == 9) {
            lib.showReservations();
            if (lib.resCount == 0) {
                continue;
            }
            cout << "Pick reservation number: ";
            int ri; cin >> ri; cin.ignore();
            if (ri < 0 || ri >= lib.resCount) {
                cout << "Invalid." << endl;
                continue;
            }
            cout << "1. Confirm  2. Cancel : ";
            int ch; cin >> ch; cin.ignore();
            if (ch == 1) {
                lib.reservations[ri].confirm();
                cout << "Confirmed!" << endl;
            } else {
                lib.reservations[ri].cancel();
                cout << "Cancelled!" << endl;
            }
        }

        else if (choice == 10) {
            lib.tx.showHistory();
        }

        else if (choice != 0) {
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    cout << "Goodbye!" << endl;
    return 0;
}
