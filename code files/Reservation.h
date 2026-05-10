#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <string>
using namespace std;

class Reservation {
public:
    string memberName;
    string bookTitle;
    string status;

    Reservation() {
        status = "Empty";
    }

    void set(string m, string b) {
        memberName = m;
        bookTitle = b;
        status = "Pending";
    }

    void confirm() {
        status = "Confirmed";
    }

    void cancel() {
        status = "Cancelled";
    }

    void display(int i) {
        cout << "[" << i << "] Book: " << bookTitle
             << " | Member: " << memberName
             << " | Status: " << status << endl;
    }
};

#endif
