#include "Customer.h"
#include <algorithm>

Customer::Customer(std::string customerId, std::string customerName)
    : mcustomerId(customerId), mcustomerName(customerName) {}

std::string Customer::getCustomerId() const {
    return mcustomerId;
}

int Customer::getAccountNumber(int numberAccount) const{
    int accNum;
     for(const Account& account : accounts) {
        if (numberAccount == account.getAccountNumber())
            accNum = account.getAccountNumber();
     }
     return accNum;
}

void Customer::addAccount(int accountNumber, float accountBalance, std::string accountType) {
    Account account(accountNumber, accountBalance, accountType);
    accounts.push_back(account);
}

void Customer::displayDetails() const {
    std::cout << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Customer Id is " << mcustomerId << std::endl;
    std::cout << "Customer name is " << mcustomerName << std::endl;

    std::string previousAccountType;
    int previousAccountNumber = -1;

    for (const Account& account : accounts) {
        if (account.getAccountNumber() != previousAccountNumber) {
            account.displayAccountNumber();
            previousAccountNumber = account.getAccountNumber();
        }

        account.displayAccountType();
        account.displayAccountBalance();
    }
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}

const std::vector<Account>& Customer::getAccounts() const {
    return accounts;
}

std::string Customer::getCustomerName() const {
    return mcustomerName;
}

void Customer::deposit(const std::string& accountType, float depositAmount) {
    // Convert accountType to lowercase
    std::string accountTypeLowerCase = toLowerCase(accountType);

    for (Account& account : accounts) {
        std::string accountTypeLowerCaseAccount = toLowerCase(account.getAccountType());

        if (accountTypeLowerCase == accountTypeLowerCaseAccount) {
            account.depositAccount(depositAmount);
        }
    }
}

void Customer::withdrawal(const std::string& accountType, float withAmount) {
    std::string accountTypeLowerCase = toLowerCase(accountType);

    for (Account& account : accounts) {
        std::string accountTypeLowerCaseAccount = toLowerCase(account.getAccountType());

        if (accountTypeLowerCase == accountTypeLowerCaseAccount) {
            account.withAccount(withAmount);
        }
    }
}

std::string Customer::toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

std::string Customer::getTransactionResult(std::string& accountType, float amount)
{
    std::string accountTypeLowerCase = toLowerCase(accountType);
    for (Account& account : accounts) {
        std::string accountTypeLowerCaseAccount = toLowerCase(account.getAccountType());

        if (accountTypeLowerCase == accountTypeLowerCaseAccount) {
            if (account.sucOrFail(amount)) {
                return "successful";
            } else {
                return "Fail";
            }
        }
    }
    return "Transaction failed: account not found";
}
