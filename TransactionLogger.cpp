#include "transactionlogger.h"

TransactionLogger::TransactionLogger() {
    // Constructor, you can initialize any necessary data members here
}

void TransactionLogger::RecordTransaction(std::shared_ptr<Transaction> transaction) {
    transactionHistory.push_back(transaction);

    if (transactionHistory.size() > 100) {
        transactionHistory.erase(transactionHistory.begin());
    }
}


std::vector<std::shared_ptr<Transaction>> TransactionLogger::SearchTransactionsByAccount(int accountNumber) const {
    std::vector<std::shared_ptr<Transaction>> matchingTransactions;

    for (const auto& transaction : transactionHistory) {
        if (transaction->getFromAccount() == accountNumber || transaction->getToAccount() == accountNumber) {
            matchingTransactions.push_back(transaction);
        }
    }

    return matchingTransactions;
}
