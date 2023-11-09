#include <iostream>
#include <sstream>
#include "Bank.h"
#include <limits>
#include <string>
#include <ctime>


//This is for getting accout number from user.

std::string getValidAccountType() {
    std::string accountType;
    do {
        // Selecting which one you want to make changes in saving or checking.
        std::cout << "Choose your account type (Saving or Checking): ";
        std::cin >> accountType;

        if (accountType != "Saving" && accountType != "Checking" && accountType != "saving" && accountType != "checking") {
                        std::cout << "Invalid account type. Please enter 'Saving' or 'Checking'." << std::endl;
                }
    } while (accountType != "Saving" && accountType != "Checking" && accountType != "saving" && accountType != "checking");

    return accountType;
}


int getAccountNumber(std::string sendOrReceive) {
    int accountNumber;
    do {
        if(sendOrReceive == "sender")
        {
            std::cout << "Enter your account number: ";
        }
        else if(sendOrReceive == "receiver")
        {
            std::cout << "Enter the account number that you are sending";
        }

        if (!(std::cin >> accountNumber)) {
            std::cerr << "Invalid input. Please enter an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Specify '\n' as the delimiter
        } else {
            break; 
        }
    } while (true);
    return accountNumber;
}

int getTransactionAmount()
{
    float amount;
    std::cout << "Enter the amount that you want to transfer" << std::endl;
    std::cin >> amount;
    return amount;
}

std::string getValidCustomerID(Bank& myBank) {
    std::string customerID;
    while (true) {
        std::cout << "Enter your customer ID: ";
        std::cin >> customerID;

        // Check whether the selected customerID exists or not.
        bool customerExists = myBank.customerExists(customerID);

        if (!customerExists) {
            std::cerr << "Customer with ID " << customerID << " does not exist. Please enter a valid customer ID." << std::endl;
        } else {
            return customerID; // Return the valid customer ID if found
        }
    }
    return customerID;
}

// void processTransaction(const std::string& result, Bank& myBank, int receiverNumber, const std::string& accountType, double transactionAmount) {
//     if (result == "successful") {
//         myBank.addToReceiver(receiverNumber, accountType, transactionAmount);
//     }
// }

std::string getCurrentDateTime() {
    time_t now = time(0);
    struct tm* currentDateTime = localtime(&now);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%m/%d %H:%M", currentDateTime);

    return buffer;
}



void createCustomerAndAddAccounts(std::string nextCustomerID,Bank& myBank) {
    std::string name;
    std::cout << "Write your name: ";
    std::cin >> name;
    int accountNumber = myBank.getAccountNumber();
    float accountBalance = 0.0;
    std::string Saving = "Saving";
    std::string Checking = "Checking";
    myBank.createCustomer(name, nextCustomerID);
    myBank.addAccount(nextCustomerID, accountNumber, accountBalance, Saving);
    myBank.addAccount(nextCustomerID, accountNumber, accountBalance, Checking);
    }

    //combining creating customer and accounts and displaying selected customer information
    void newAccount(std::string actionChoice, std::string nextCustomerID,Bank& myBank)
    {  
            createCustomerAndAddAccounts(nextCustomerID, myBank);
            myBank.displayDetails(nextCustomerID);
    }

    // checking if user input is float or not for deposit and withdrawal
    float getValidFloatInput() {
    float inputValue;

    while (true) {
        std::cout << "Enter amount: ";
        std::string input;
        std::cin >> input;
        std::stringstream ss(input);

        if (ss >> inputValue && ss.eof()) {
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        }

        // Clear any error flags and discard any remaining input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return inputValue;
}


int getValidAccountNumber(Bank& myBank, std::string receiveOrSend) {
    while (true) {
        int senderNumber = getAccountNumber(receiveOrSend);

        // Check whether the selected customerID exists or not.
        bool accountExists = myBank.accountExists(senderNumber);

        if (!accountExists) {
            std::cerr << "Account number with " << senderNumber << " does not exist. Please enter a valid account number." << std::endl;
        } else {
            return senderNumber;
        }
    }
}


int main()
{
    //making the first customer and displaying
    Bank myBank;
    std::string nextCustomerID = myBank.getNextCustomerID();
    char createAnother;
    createCustomerAndAddAccounts(nextCustomerID, myBank);
    myBank.displayDetails(nextCustomerID);     
    std::string actionChoice;
        
        do{
            //letting users to choose manage thier money or making an account.
            std::cout << "Do you want to create an account?(Create) or " << std::endl << 
            "Do you want to make a deposit, withdrawal, or exit (Deposit/Withdrawal/Exitfa): " << std::endl <<
            "or do you want to make Transaction? (Transaction)";
            std::cin >> actionChoice;

            //craeting account case
            if(actionChoice == "Create" || actionChoice == "create")
            {
                nextCustomerID = myBank.getNextCustomerID();
                newAccount(actionChoice, nextCustomerID, myBank);
               
            }

            //making deposit or withdrawal case
            else if (actionChoice == "Deposit" || actionChoice == "deposit" || actionChoice == "Withdrawal" || actionChoice == "withdrawal") {
                std::string customerID = getValidCustomerID(myBank);
                
                std::string accountType = getValidAccountType();
                float amount;

                while (true) {
                    //deposit case
                    if (actionChoice == "Deposit" || actionChoice == "deposit") {
                        amount = getValidFloatInput();
                        myBank.deposit(customerID, accountType, amount);
                        break;
                    //withdrawal case
                    } else if (actionChoice == "Withdrawal" || actionChoice == "withdrawal") {
                        amount = getValidFloatInput();
                        myBank.withdrawal(customerID, accountType, amount);
                        break;
                    }
                    else {
                        break; 
                    }
                }

                std::cout << std::endl;
                myBank.displayDetails(customerID);
            }

            else if (actionChoice == "Transaction" || actionChoice == "transaction")
            {    
                int senderNumber = getValidAccountNumber(myBank, "sender");
                int receiverNumber = getValidAccountNumber(myBank, "receiver");
                float transactionAmount = getTransactionAmount();
                std::string accountType = getValidAccountType();
                std::string date = getCurrentDateTime();
                std::string result = myBank.TransferMoney(receiverNumber, senderNumber,transactionAmount,accountType, date);
                
                // myBank.storeTransaction(senderNumber, receiverNumber, date, transactionAmount,result);
                int accountNumberToSearch;
                std::cout << "Enter the account number to check the transaction record" << std::endl;
                std::cin >> accountNumberToSearch;
                myBank.searchTransaction(accountNumberToSearch);
                // std::string result = myBank.transactionResult(receiverNumber, senderNumber,transactionAmount, accountType);
                // processTransaction(result, myBank, receiverNumber, accountType, transactionAmount);

            }

            //letting user to end the system.
            else if (actionChoice == "Exit" || actionChoice == "exit") {
                break; // Exit the inner loop and continue with the next customer
            }
            else {
                std::cout << "Invalid choice. Please enter 'Deposit', 'Withdrawal', or 'Exit'." << std::endl;
            }
        } while (true); // Continue until user chooses to exit
    return 0;
}

