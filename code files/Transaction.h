#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
using namespace std;

class Transaction {
public:
    string logs[100];
    int count;

    Transaction() {
        count = 0;
    }

    void record(string entry) {
        logs[count] = entry;
        count++;
    }

    void showHistory() {
        if (count == 0) {
            cout << "No transactions yet." << endl;
            return;
        }
        cout << "Transaction History " << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << logs[i] << endl;
        }
    }
};

#endif
