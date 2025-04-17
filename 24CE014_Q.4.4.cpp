#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
protected:
    string AccountNumber;
    double Balance;

public:
    BankAccount(string accNum, double initialBalance) {
        AccountNumber = accNum;
        Balance = initialBalance;
    }

    virtual void Deposit(double amount) {
        Balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void Withdraw(double amount) {
        if (amount <= Balance) {
            Balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Insufficient Balance!" << endl;
        }
    }

    virtual void DisplayAccountDetails() const {
        cout << "Account Number: " << AccountNumber << endl;
        cout << "Balance: " << Balance << endl;
    }

    string GetAccountNumber() const {
        return AccountNumber;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, double initialBalance, double rate)
        : BankAccount(accNum, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double interest = Balance * (interestRate / 100);
        Balance += interest;
        cout << "Interest Applied: " << interest << endl;
    }

    void DisplayAccountDetails() const override {
        BankAccount::DisplayAccountDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accNum, double initialBalance, double limit)
        : BankAccount(accNum, initialBalance), overdraftLimit(limit) {}

    void Withdraw(double amount) override {
        if (amount <= Balance + overdraftLimit) {
            Balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }

    void DisplayAccountDetails() const override {
        BankAccount::DisplayAccountDetails();
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
        if (acc->GetAccountNumber() == accNum) {
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

        string AccountNumber;
        double amount, rate, limit;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> AccountNumber;
                cout << "Enter initial Balance: ";
                cin >> amount;
                cout << "Enter interest rate: ";
                cin >> rate;
                accounts.push_back(new SavingsAccount(AccountNumber, amount, rate));
                break;

            case 2:
                cout << "Enter account number: ";
                cin >> AccountNumber;
                cout << "Enter initial Balance: ";
                cin >> amount;
                cout << "Enter overdraft limit: ";
                cin >> limit;
                accounts.push_back(new CurrentAccount(AccountNumber, amount, limit));
                break;

            case 3:
                cout << "Enter account number: ";
                cin >> AccountNumber;
                cout << "Enter Deposit amount: ";
                cin >> amount;
                if (BankAccount* acc = findAccount(accounts, AccountNumber)) {
                    acc->Deposit(amount);
                    history.addTransaction("Deposited " + to_string(amount) + " to " + AccountNumber);
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 4:
                cout << "Enter account number: ";
                cin >> AccountNumber;
                cout << "Enter Withdrawal amount: ";
                cin >> amount;
                if (BankAccount* acc = findAccount(accounts, AccountNumber)) {
                    acc->Withdraw(amount);
                    history.addTransaction("Withdrew " + to_string(amount) + " from " + AccountNumber);
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 5:
                cout << "Enter account number: ";
                cin >> AccountNumber;
                if (BankAccount* acc = findAccount(accounts, AccountNumber)) {
                    SavingsAccount* savingsAcc = dynamic_cast<SavingsAccount*>(acc);
                    if (savingsAcc) {
                        savingsAcc->applyInterest();
                        history.addTransaction("Applied interest to " + AccountNumber);
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
                cin >> AccountNumber;
                if (BankAccount* acc = findAccount(accounts, AccountNumber)) {
                    acc->DisplayAccountDetails();
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

    cout << "24CE014 JAYRAJSINH BHATTI";
    return 0;
}
