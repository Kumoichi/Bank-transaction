// transactionlogger.h

#ifndef TRANSACTIONLOGGER_H
#define TRANSACTIONLOGGER_H

#include "transaction.h"  // Include the header for the Transaction class

#include <vector>

class TransactionLogger {
public:
    TransactionLogger();

    void RecordTransaction(Transaction* transaction);
    std::vector<Transaction*> SearchTransactionsByAccount(int accountNumber) const;

private:
    std::vector<Transaction*> transactionHistory;
};

#endif
