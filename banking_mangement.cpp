#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Account class definition
class Account {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    // Default constructor
    Account() : accountNumber(0), accountHolder(""), balance(0.0) {}

    // Parameterized constructor
    Account(int accNum, string accHolder, double initialBalance)
        : accountNumber(accNum), accountHolder(accHolder), balance(initialBalance) {}

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance for withdrawal!" << endl;
        } else if (amount > 0) {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: " << balance << endl;
        } else {
            cout << "Withdrawal amount must be positive!" << endl;
        }
    }

    // Getters for account information
    double getBalance() const { return balance; }
    int getAccountNumber() const { return accountNumber; }
    string getAccountHolder() const { return accountHolder; }
};

// Bank class definition
class Bank {
private:
    unordered_map<int, Account> accounts;

public:
    // Function to create a new account
    void createAccount(int accNum, string accHolder, double initialBalance) {
        if (accounts.find(accNum) != accounts.end()) {
            cout << "Account number " << accNum << " already exists!" << endl;
            return;
        }
        accounts.insert(std::make_pair(accNum, Account(accNum, accHolder, initialBalance)));
        cout << "Account created successfully for " << accHolder << " with Account Number: " << accNum << endl;
    }

    // Deposit function
    void deposit(int accNum, double amount) {
        if (accounts.find(accNum) != accounts.end()) {
            accounts[accNum].deposit(amount);
        } else {
            cout << "Account number " << accNum << " not found!" << endl;
        }
    }

    // Withdraw function
    void withdraw(int accNum, double amount) {
        if (accounts.find(accNum) != accounts.end()) {
            accounts[accNum].withdraw(amount);
        } else {
            cout << "Account number " << accNum << " not found!" << endl;
        }
    }

    // Function to show balance for an account
    void showBalance(int accNum) const {
        if (accounts.find(accNum) != accounts.end()) {
            cout << "Account Balance for " << accounts.at(accNum).getAccountHolder()
                 << " (Account Number: " << accNum << "): " << accounts.at(accNum).getBalance() << endl;
        } else {
            cout << "Account number " << accNum << " not found!" << endl;
        }
    }
};

// Main function with a menu-driven interface
int main() {
    Bank bank;
    int choice, accountNumber;
    string accountHolder;
    double initialBalance, amount;

    while (true) {
        cout << "\n=== Banking Management System ===" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Account Holder's Name: ";
                cin.ignore();  // To ignore the newline character left in the buffer
                getline(cin, accountHolder);
                cout << "Enter Initial Balance: ";
                cin >> initialBalance;
                bank.createAccount(accountNumber, accountHolder, initialBalance);
                break;

            case 2:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                bank.deposit(accountNumber, amount);
                break;

            case 3:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;

            case 4:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                bank.showBalance(accountNumber);
                break;

            case 5:
                cout << "Exiting the Banking Management System. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please select a valid option." << endl;
        }
    }
}