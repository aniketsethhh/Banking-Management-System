#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    int pin;
    double balance;

public:
    Account();
    Account(int accNo, string n, int p, double bal);

    int getAccountNumber();
    int getPin();
    double getBalance();

    void deposit(double amount);
    bool withdraw(double amount);
    void display();
    string toFileString();
};

#endif
