/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(string number, string name, double initialBalance)
        : accountNumber(number), accountHolderName(name), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " into account " << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    const string& getAccountNumber() const {
        return accountNumber;
    }
};

class Bank {
private:
    vector<Account> accounts;

public:
    void createAccount(string accountNumber, string accountHolderName, double initialBalance) {
        accounts.emplace_back(accountNumber, accountHolderName, initialBalance);
        cout << "Account created successfully." << endl;
    }

    Account* findAccount(string accountNumber) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }
};

int main() {
    Bank bank;

    while (true) {
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string accountNumber, accountHolderName;
                    double initialBalance;
                    cout << "Enter account number: ";
                    cin >> accountNumber;
                    cout << "Enter account holder name: ";
                    cin >> accountHolderName;
                    cout << "Enter initial balance: ";
                    cin >> initialBalance;
                    bank.createAccount(accountNumber, accountHolderName, initialBalance);
                }
                break;

            case 2:
                {
                    string accountNumber;
                    double amount;
                    cout << "Enter account number: ";
                    cin >> accountNumber;
                    Account* account = bank.findAccount(accountNumber);
                    if (account) {
                        cout << "Enter deposit amount: ";
                        cin >> amount;
                        account->deposit(amount);
                    } else {
                        cout << "Account not found." << endl;
                    }
                }
                break;

            case 3:
                {
                    string accountNumber;
                    double amount;
                    cout << "Enter account number: ";
                    cin >> accountNumber;
                    Account* account = bank.findAccount(accountNumber);
                    if (account) {
                        cout << "Enter withdrawal amount: ";
                        cin >> amount;
                        account->withdraw(amount);
                    } else {
                        cout << "Account not found." << endl;
                    }
                }
                break;

            case 4:
                {
                    string accountNumber;
                    cout << "Enter account number: ";
                    cin >> accountNumber;
                    Account* account = bank.findAccount(accountNumber);
                    if (account) {
                        cout << "Account balance: $" << account->getBalance() << endl;
                    } else {
                        cout << "Account not found." << endl;
                    }
                }
                break;

            case 5:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
