#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

// BASE CLASS
// Member and Librarian will both inherit from this
class Person {
public:
    string name;
    int id;

    Person() {
        name = "Unknown";
        id = 0;
    }

    Person(string n, int i) {
        name = n;
        id = i;
    }

    // virtual so derived classes can override it
    virtual void display(int i) {
        cout << "[" << i << "] " << name << " | ID: " << id << endl;
    }

    virtual ~Person() {}
};

#endif
