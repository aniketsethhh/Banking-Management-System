#include "Bank.h"

int main() {
    Bank bank;
    bank.loadAccounts();

    int choice;
    do {
        cout << "\n--- BANKING SYSTEM ---\n";
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            bank.createAccount();
        else if (choice == 2)
            bank.login();

    } while (choice != 3);

    return 0;
}
