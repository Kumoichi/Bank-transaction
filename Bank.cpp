#include "Bank.h"

Bank::Bank()
    : nextCustomerID(1) {}

std::string Bank::getNextCustomerID() {
    std::string customerID = "C" + std::to_string(nextCustomerID);
    nextCustomerID++;
    return customerID;
}

int Bank::getAccountNumber(){
    int accountNumber = nextCustomerID-1;
    return accountNumber;
}

void Bank::createCustomer(const std::string& customerName, const std::string& customerId) {
    Customer customer(customerId, customerName);
    customers.push_back(customer);
    std::cout << "Customer created: " << std::endl;
}

void Bank::addAccount(const std::string& customerID, int accountNumber, float accountBalance, const std::string& accountType) {
    for (Customer& customer : customers) {
        if (customerID == customer.getCustomerId()) {
            customer.addAccount(accountNumber, accountBalance, accountType);
        }
    }
}

void Bank::displayDetails(const std::string& customerID) const {
    for (const Customer& customer : customers) {
        if (customerID == customer.getCustomerId()) {
            customer.displayDetails();
        }
    }
}

void Bank::deposit(const std::string& customerID, const std::string& accountType, float depositAmount) {
    for (Customer& customer : customers) {
        if (customerID == customer.getCustomerId()) {
            customer.deposit(accountType, depositAmount);
        }
    }
}

void Bank::withdrawal(const std::string& customerID, const std::string& accountType, float withAmount) {
    for (Customer& customer : customers) {
        if (customerID == customer.getCustomerId()) {
            customer.withdrawal(accountType, withAmount);
        }
    }
}

bool Bank::customerExists(const std::string& customerID) const {
    for (const Customer& customer : customers) {
        if (customerID == customer.getCustomerId()) {
            return true;
        }
    }
    return false;
}
