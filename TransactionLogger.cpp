// transactionlogger.cpp

#include "transactionlogger.h"

TransactionLogger::TransactionLogger() {
    // Constructor, you can initialize any necessary data members here
}

void TransactionLogger::RecordTransaction(Transaction* transaction) {
    transactionHistory.push_back(transaction);

    if (transactionHistory.size() > 100) {
        delete transactionHistory[0];
        transactionHistory.erase(transactionHistory.begin());
    }
}

std::vector<Transaction*> TransactionLogger::SearchTransactionsByAccount(int accountNumber) const {
    std::vector<Transaction*> matchingTransactions;

    for (auto transaction : transactionHistory) {
        if (transaction->getFromAccount() == accountNumber || transaction->getToAccount() == accountNumber) {
            matchingTransactions.push_back(transaction);
        }
    }

    return matchingTransactions;
}
