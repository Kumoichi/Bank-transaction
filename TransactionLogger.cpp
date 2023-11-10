#include "transactionlogger.h"

TransactionLogger::TransactionLogger() {
}

// storing transaction that is passed from bank.cpp
void TransactionLogger::RecordTransaction(std::shared_ptr<Transaction> transaction) {
    transactionStorage.push_back(transaction);

    if (transactionStorage.size() > 100) {
        transactionStorage.erase(transactionStorage.begin());
    }
}

// seaching transaction from transactionStorage
std::vector<std::shared_ptr<Transaction>> TransactionLogger::SearchTransactionsByAccount(int accountNumber) const {
    std::vector<std::shared_ptr<Transaction>> enteredTransactions;

    for (const auto& transaction : transactionStorage) {
        if (transaction->getFromAccount() == accountNumber || transaction->getToAccount() == accountNumber) {
            enteredTransactions.push_back(transaction);
        }
    }

    return enteredTransactions;
}


