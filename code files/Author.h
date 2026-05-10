#ifndef AUTHOR_H
#define AUTHOR_H
#include <string>
using namespace std;

class Author {
public:
    string name;

    Author() {
        name = "Unknown";
    }

    Author(string n) {
        name = n;
    }

    string getName() {
        return name;
    }
};

#endif
