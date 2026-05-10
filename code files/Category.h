#ifndef CATEGORY_H
#define CATEGORY_H
#include <string>
using namespace std;

class Category {
public:
    string genre;

    Category() {
        genre = "General";
    }

    Category(string g) {
        genre = g;
    }

    string getGenre() {
        return genre;
    }
};

#endif
