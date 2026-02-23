#include "Account.h"

Account::Account() {
    accountNumber = 0;
    name = "";
    pin = 0;
    balance = 0;
}

Account::Account(int accNo, string n, int p, double bal) {
    accountNumber = accNo;
    name = n;
    pin = p;
    balance = bal;
}

int Account::getAccountNumber() {
    return accountNumber;
}

int Account::getPin() {
    return pin;
}

double Account::getBalance() {
    return balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > balance)
        return false;
    balance -= amount;
    return true;
}

void Account::display() {
    cout << "\nAccount No: " << accountNumber
         << "\nName: " << name
         << "\nBalance: " << balance << endl;
}


string Account::toFileString() {
    return to_string(accountNumber) + "|" +
           name + "|" +
           to_string(pin) + "|" +
           to_string(balance);
}

