#include "transaction.h"
#include <iostream>
#include <iomanip>

// transaction class stores all information as objects that users have entered
Transaction::Transaction(int transID, int senderNumber, int receiverNumber, const std::string& date, float transactionAmount, const std::string& res)
    : transactionID(transID), fromAccount(senderNumber), toAccount(receiverNumber), timestamp(date), amount(transactionAmount), result(res) {
}

int Transaction::getTransactionID() const {
    return transactionID;
}

int Transaction::getFromAccount() const {
    return fromAccount;
}

int Transaction::getToAccount() const {
    return toAccount;
}

const std::string& Transaction::getTimestamp() const {
    return timestamp;
}

float Transaction::getAmount() const {
    return amount;
}

const std::string& Transaction::getResult() const {
    return result;
}

// for displaying searched account transaction result.
std::string Transaction::ToString() const {
    std::string resultString;
    resultString += "-----------------------------------\n";
    resultString += "Transaction ID: " + std::to_string(transactionID) + "\n";
    resultString += "From Account: " + std::to_string(fromAccount) + "\n";
    resultString += "To Account: " + std::to_string(toAccount) + "\n";
    resultString += "Timestamp: " + timestamp + "\n";
    
    // Use a temporary stringstream for formatting the amount
    std::stringstream amountStream;
    amountStream << std::fixed << std::setprecision(2) << amount;
    
    resultString += "Amount: " + amountStream.str() + "\n";
    resultString += "-----------------------------------\n";
    return resultString;
}