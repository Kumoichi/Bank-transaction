#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {
private:
    int maccountNumber;
    std::string maccountType;
    float maccountBalance;

public:
    Account();
    Account(int accountNumber, float accountBalance, const std::string& accountType);

    void displayAccountType() const;
    void displayAccountNumber() const;
    void displayAccountBalance() const;
    void depositAccount(float depositAmount);
    void withAccount(float withAmount);

    int getAccountNumber() const;
    std::string getAccountType() const;
    float getAccountBalance() const;
};

#endif
