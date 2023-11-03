#include <iostream>
#include <sstream>
#include "Bank.h"
#include <limits>
#include <string>


// This is creating customer constructor and account constructor.
//building saving and checking as a default.
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
            "Do you want to make a deposit, withdrawal, or exit (Deposit/Withdrawal/Exit): ";
            std::cin >> actionChoice;

            //craeting account case
            if(actionChoice == "Create" || actionChoice == "create")
            {
                nextCustomerID = myBank.getNextCustomerID();
                newAccount(actionChoice, nextCustomerID, myBank);
               
            }

            //making deposit or withdrawal case
            else if (actionChoice == "Deposit" || actionChoice == "deposit" || actionChoice == "Withdrawal" || actionChoice == "withdrawal") {
                std::string customerID;
                while (true) {
                    std::cout << "Enter your customer ID: ";
                    std::cin >> customerID;

                    //checkes whehter selected customerID exists or not.
                    bool customerExists = myBank.customerExists(customerID);

                    if (!customerExists) {
                        std::cerr << "Customer with ID " << customerID << " does not exist. Please enter a valid customer ID." << std::endl;
                    } else {
                        break; // Exit the loop if a valid customer ID is entered
                    }
                }
                
                std::string accountType;
                do {
                    //selecting which one you want to make changes in saving or checking.
                    std::cout << "Choose your account type (Saving or Checking): ";
                    std::cin >> accountType;

                    if (accountType != "Saving" && accountType != "Checking" && accountType != "saving" && accountType != "checking") {
                        std::cout << "Invalid account type. Please enter 'Saving' or 'Checking'." << std::endl;
                    }
                } while (accountType != "Saving" && accountType != "Checking" && accountType != "saving" && accountType != "checking");

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