#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <iostream>
#include <string>
using namespace std;

class Notification {
public:
    string recipient;
    string message;

    void send(string to, string msg) {
        recipient = to;
        message = msg;
        cout << "Notification to " << recipient << ": " << message << endl;
    }
};

#endif
