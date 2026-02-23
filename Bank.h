#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <vector>

class Bank {
private:
    vector<Account> accounts;

public:
    void loadAccounts();
    void saveAccounts();
    void createAccount();
    void login();
};

#endif
