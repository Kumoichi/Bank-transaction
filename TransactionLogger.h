// transactionlogger.h

#ifndef TRANSACTIONLOGGER_H
#define TRANSACTIONLOGGER_H

#include "transaction.h"  // Include the header for the Transaction class
#include <memory>
#include <vector>

class TransactionLogger {
public:
    TransactionLogger();

    void RecordTransaction(std::shared_ptr<Transaction> transaction);
    std::vector<std::shared_ptr<Transaction>> SearchTransactionsByAccount(int accountNumber) const;
private:
    std::vector<std::shared_ptr<Transaction>> transactionStorage;
};

#endif
