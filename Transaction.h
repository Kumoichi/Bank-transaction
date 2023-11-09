#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <sstream>
#include <iomanip>  // Include the header for std::setprecision

class Transaction {
public:
    Transaction(int transID, int senderNumber, int receiverNumber, const std::string& date, float transactionAmount, const std::string& res);
    int getTransactionID() const;
    int getFromAccount() const;
    int getToAccount() const;
    const std::string& getTimestamp() const;
    float getAmount() const;
    const std::string& getResult() const;

    std::string ToString() const;

private:
    int transactionID;
    int fromAccount;
    int toAccount;
    std::string timestamp;
    float amount;
    std::string result;
};

#endif // TRANSACTION_H
