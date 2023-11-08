#include "Bank.h"



Bank::Bank()
    : nextCustomerID(1) {}


int Bank::GetNextTransactionID() const {
    static int transactionCounter = 1;
    return transactionCounter++;
}

std::string Bank::getNextCustomerID() {
    std::string customerID = "C" + std::to_string(nextCustomerID);
    nextCustomerID++;
    return customerID;
}

std::string Bank::TransferMoney(int receiverNumber, int senderNumber, float transactionAmount, std::string accountType, std::string date)
{
    std::string result;
    for (Customer& customer : customers)
    {
        if (senderNumber == customer.getAccountNumber(senderNumber))
        {
                result = customer.getTransactionResult(senderNumber, accountType, transactionAmount);
        }
    }

    for (Customer& customer : customers) {
        if (receiverNumber == customer.getAccountNumber(receiverNumber)) {
            customer.deposit(accountType, transactionAmount);
        }
    }

    Transaction newTransaction(GetNextTransactionID(), senderNumber, receiverNumber, date, transactionAmount, result);
    // transactionLogger.RecordTransaction(newTransaction);

};


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


bool Bank::accountExists(const int accountNumber) const{
    for(const Customer& customer : customers) {
        if (accountNumber == customer.getAccountNumber(accountNumber))
        {
            return true;
        }
    }
    return false;
}



// std::string Bank::transactionResult(int receiverNumber, int senderNumber, float transactionAmount, std::string accountType)
// {
//     for (Customer& customer : customers)
//     {
//         if (senderNumber == customer.getAccountNumber(senderNumber))
//         {
//                 return customer.getTransactionResult(senderNumber, accountType, transactionAmount);
//         }
//     }
//     return "";
// }



// void Bank::addToReceiver(int receiverNumber, const std::string& accountType, float depositAmount) {
//     for (Customer& customer : customers) {
//         if (receiverNumber == customer.getAccountNumber(receiverNumber)) {
//             customer.deposit(accountType, depositAmount);
//         }
//     }
// }