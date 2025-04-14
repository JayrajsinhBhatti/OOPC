#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, double initialBalance, double rate)
        : BankAccount(accNum, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest Applied: " << interest << endl;
    }

    void displayAccountDetails() const override {
        BankAccount::displayAccountDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accNum, double initialBalance, double limit)
        : BankAccount(accNum, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }

    void displayAccountDetails() const override {
        BankAccount::displayAccountDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class TransactionHistory {
private:
    vector<string> transactions;

public:
    void addTransaction(const string& transaction) {
        transactions.push_back(transaction);
    }

    void undoLastTransaction() {
        if (!transactions.empty()) {
            cout << "Undoing last transaction: " << transactions.back() << endl;
            transactions.pop_back();
        } else {
            cout << "No transaction to undo." << endl;
        }
    }

    void displayHistory() const {
        if (transactions.empty()) {
            cout << "No transactions yet." << endl;
            return;
        }

        for (const string& transaction : transactions) {
            cout << transaction << endl;
        }
    }
};

// Helper function to find an account by account number
BankAccount* findAccount(const vector<BankAccount*>& accounts, const string& accNum) {
    for (BankAccount* acc : accounts) {
        if (acc->getAccountNumber() == accNum) {
            return acc;
        }
    }
    return nullptr;
}

int main() {
    vector<BankAccount*> accounts;
    TransactionHistory history;

    int choice;
    do {
        cout << "\n1. Add Savings Account\n2. Add Current Account\n3. Deposit\n4. Withdraw\n5. Apply Interest (Savings)\n6. Undo Last Transaction\n7. Display Account Details\n8. Display Transaction History\n0. Exit\nEnter choice: ";
        cin >> choice;

        string accountNumber;
        double amount, rate, limit;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter initial balance: ";
                cin >> amount;
                cout << "Enter interest rate: ";
                cin >> rate;
                accounts.push_back(new SavingsAccount(accountNumber, amount, rate));
                break;

            case 2:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter initial balance: ";
                cin >> amount;
                cout << "Enter overdraft limit: ";
                cin >> limit;
                accounts.push_back(new CurrentAccount(accountNumber, amount, limit));
                break;

            case 3:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter deposit amount: ";
                cin >> amount;
                if (BankAccount* acc = findAccount(accounts, accountNumber)) {
                    acc->deposit(amount);
                    history.addTransaction("Deposited " + to_string(amount) + " to " + accountNumber);
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 4:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                if (BankAccount* acc = findAccount(accounts, accountNumber)) {
                    acc->withdraw(amount);
                    history.addTransaction("Withdrew " + to_string(amount) + " from " + accountNumber);
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 5:
                cout << "Enter account number: ";
                cin >> accountNumber;
                if (BankAccount* acc = findAccount(accounts, accountNumber)) {
                    SavingsAccount* savingsAcc = dynamic_cast<SavingsAccount*>(acc);
                    if (savingsAcc) {
                        savingsAcc->applyInterest();
                        history.addTransaction("Applied interest to " + accountNumber);
                    } else {
                        cout << "Not a savings account!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 6:
                history.undoLastTransaction();
                break;

            case 7:
                cout << "Enter account number: ";
                cin >> accountNumber;
                if (BankAccount* acc = findAccount(accounts, accountNumber)) {
                    acc->displayAccountDetails();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 8:
                history.displayHistory();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 0);

    for (BankAccount* acc : accounts) {
        delete acc;
    }

    return 0;
}
