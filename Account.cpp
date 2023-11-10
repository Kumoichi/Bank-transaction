#include "Account.h"
#include <iostream>

Account::Account()
    : maccountNumber(0), maccountBalance(0.0f), maccountType("") {}

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

// shows not enought amount message if it doesn't have sufficient funds
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


// shows not enought amount message if it doesn't have sufficient funds

bool Account::sucOrFail(int amount) {
    if (maccountBalance - amount >= 0) {
        maccountBalance -= amount;
        std::cout << "Your transaction amount is " << amount << std::endl;
        return true;
    } else {
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << "| You don't have enough balance for that amount of transaction|" << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;
        return false;
    }
}