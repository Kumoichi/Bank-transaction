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
