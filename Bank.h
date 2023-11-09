#pragma once

#ifndef BANK_H
#define BANK_H

#include "Customer.h"
#include "transaction.h"
#include "transactionlogger.h"
#include <vector>
#include <iostream>
#include <string>

class Bank {
private:
    std::vector<Customer> customers;
    int nextCustomerID;
    TransactionLogger transactionLogger;

public:
    Bank();

    std::string getNextCustomerID();
    std::string TransferMoney(int receivernumber, int senderNumber, float transactionAmount, std::string accountType, std::string date);
    void storeTransaction(int senderNumber, int receiverNumber, std::string date, float transactionAmount, std::string result);
    void searchTransaction(int accountNumber) const;
    int getAccountNumber();
    void createCustomer(const std::string& customerName, const std::string& customerId);
    void addAccount(const std::string& customerID, int accountNumber, float accountBalance, const std::string& accountType);
    void displayDetails(const std::string& customerID) const;
    void deposit(const std::string& customerID, const std::string& accountType, float depositAmount);
    void withdrawal(const std::string& customerID, const std::string& accountType, float withAmount);
    bool customerExists(const std::string& customerID) const;
    bool accountExists(const int accountNumber) const;
    int numberCheck();
    std::string transactionResult(int receiverNumber, int senderNumber, float transactionAmount,std::string accountType);
    void addToReceiver(int receiverNumber, const std::string& accountType, float depositAmount);
    int GetNextTransactionID() const;

};

#endif
