#include "Bank.h"
#include <fstream>
#include <sstream>

void Bank::loadAccounts() {
    accounts.clear();
    ifstream in("accounts.txt");

    string line;
    while (getline(in, line)) {

        if (line.empty()) continue; 

        stringstream ss(line);
        string accNo, name, pin, bal;

        if (!getline(ss, accNo, '|')) continue;
        if (!getline(ss, name, '|')) continue;
        if (!getline(ss, pin, '|')) continue;
        if (!getline(ss, bal, '|')) continue;

        try {
            accounts.push_back(Account(
                stoi(accNo),
                name,
                stoi(pin),
                stod(bal)
            ));
        }
        catch (...) {
            cout << "⚠ Skipping corrupted record\n";
        }
    }
    in.close();
}



void Bank::saveAccounts() {
    ofstream out("accounts.txt", ios::trunc); // CLEAR file first
    for (auto &acc : accounts) {
        out << acc.toFileString() << endl;
    }
    out.close();
}


void Bank::createAccount() {
    int accNo, pin;
    string name;
    double bal;

    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Set 4-digit PIN: ";
    cin >> pin;
    cout << "Initial Deposit: ";
    cin >> bal;

    accounts.push_back(Account(accNo, name, pin, bal));
    saveAccounts();

    cout << "Account Created Successfully!\n";
}

void Bank::login() {
    int accNo, pin;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter PIN: ";
    cin >> pin;

    for (auto &acc : accounts) {
        if (acc.getAccountNumber() == accNo && acc.getPin() == pin) {
            int choice;
            do {
                cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Logout\nChoice: ";
                cin >> choice;

                if (choice == 1) {
                    acc.display();
                }
                else if (choice == 2) {
                    double amt;
                    cout << "Amount: ";
                    cin >> amt;
                    acc.deposit(amt);
                    saveAccounts();
                    cout << "Deposited Successfully\n";
                }
                else if (choice == 3) {
                    double amt;
                    cout << "Amount: ";
                    cin >> amt;
                    if (acc.withdraw(amt)) {
                        saveAccounts();
                        cout << "Withdrawal Successful\n";
                    } else {
                        cout << "Insufficient Balance\n";
                    }
                }
            } while (choice != 4);
            return;
        }
    }
    cout << "Invalid Account or PIN\n";
}
