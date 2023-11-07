#pragma once

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Account.h"
#include <iostream>
#include <string>
#include <vector>

class Customer {
private:
    std::string mcustomerId;
    std::string mcustomerName;
    std::vector<Account> accounts;

public:
    Customer(std::string customerId, std::string customerName);

    std::string getCustomerId() const;
    int getAccountNumber(int numberAccount) const;
    void addAccount(int accountNumber, float accountBalance, std::string accountType);
    void displayDetails() const;
    const std::vector<Account>& getAccounts() const;
    std::string getCustomerName() const;
    void deposit(const std::string& accountType, float depositAmount);
    void withdrawal(const std::string& accountType, float withAmount);
    std::string getTransactionResult(int senderNumber, std::string& accountType, float amount);
private:
    std::string toLowerCase(const std::string& str);
};

#endif
