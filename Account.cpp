#include "Account.h"
#include <iostream>

// Default constructor
Account::Account()
    : maccountNumber(0), maccountBalance(0.0f), maccountType("") {}

// Parameterized constructor
Account::Account(int accountNumber, float accountBalance, const std::string& accountType)
    : maccountNumber(accountNumber), maccountBalance(accountBalance), maccountType(accountType) {}

void Account::displayAccountType() const {
    std::cout << "Account Type: " << maccountType << std::endl;
}

void Account::displayAccountNumber() const {
    std::cout << "Your account number is " << maccountNumber << std::endl;
}

void Account::displayAccountBalance() const {
    std::cout << "Your account balance is " << maccountBalance << std::endl;
}

void Account::depositAccount(float depositAmount) {
    maccountBalance += depositAmount;
    std::cout << "Your deposit amount is " << depositAmount << std::endl;
}

void Account::withAccount(float withAmount) {
    if (maccountBalance - withAmount >= 0) {
        maccountBalance -= withAmount;
        std::cout << "Your withdrawal is " << withAmount << std::endl;
    } else {
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << "| You don't have enough balance for that amount of withdrawal |" << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;
    }
}

int Account::getAccountNumber() const {
    return maccountNumber;
}

std::string Account::getAccountType() const {
    return maccountType;
}

float Account::getAccountBalance() const {
    return maccountBalance;
}
