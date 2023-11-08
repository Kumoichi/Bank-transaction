#include "transaction.h"

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


std::string Transaction::ToString() const {
    std::string result;
    result += "Transaction ID: " + std::to_string(transactionID) + "\n";
    result += "From Account: " + std::to_string(fromAccount) + "\n";
    result += "To Account: " + std::to_string(toAccount) + "\n";
    result += "Timestamp: " + timestamp + "\n";
    result += "Amount: " + std::to_string(amount) + "\n";
    result += "Result: " + result + "\n";  
    return result;
}


