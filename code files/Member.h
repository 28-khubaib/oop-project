#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include "Person.h"
using namespace std;

// DERIVED CLASS  inherits from Person
class Member : public Person {
public:
    int borrowedCount;

    Member() {
        borrowedCount = 0;
    }

    Member(string n, int i) : Person(n, i) {
        // Person(n, i) sets name and id
        borrowedCount = 0;
    }

    // override base class display()  polymorphism
    void display(int i) {
        cout << "[" << i << "] Member: " << name
             << " | ID: " << id
             << " | Books Borrowed: " << borrowedCount << endl;
    }
};

#endif
