#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
protected:
    int AccountNumber;
    double Balance;
    double LastAmount;
    string LastTransactionType;
    bool HasLastTransaction;

public:
    BankAccount() {
        AccountNumber = 0;
        Balance = 0.0;
        LastAmount = 0.0;
        LastTransactionType = "";
        HasLastTransaction = false;
    }

    BankAccount(int accNo, double bal) {
        AccountNumber = accNo;
        Balance = bal;
        LastAmount = 0.0;
        LastTransactionType = "";
        HasLastTransaction = false;
    }

    virtual void Deposit(double amt) = 0;
    virtual void Withdraw(double amt) = 0;
    virtual void UndoLastTransaction() = 0;
    virtual void PrintHistory() = 0;
    virtual int GetAccountNumber() { return AccountNumber; }

    void FileTransaction(string type, double amt, const string& filename) {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << AccountNumber << " " << type << " " << amt << " " << Balance << "\n";
            file.close();
        } else {
            cout << "Couldn't open file." << endl;
        }
    }

    virtual ~BankAccount() {}
};

class SavingAccount : public BankAccount {
    float InterestRate;

public:
    SavingAccount() {
        InterestRate = 0.0;
    }

    SavingAccount(int accNo, double bal, float interest) {
        AccountNumber = accNo;
        Balance = bal;
        InterestRate = interest;
        LastAmount = 0.0;
        LastTransactionType = "";
        HasLastTransaction = false;
    }

    void Deposit(double amt) override {
        Balance += amt;
        LastAmount = amt;
        LastTransactionType = "Deposit";
        HasLastTransaction = true;
        FileTransaction("Deposit", amt, "savings_transactions.txt");
        cout << "Amount credited to savings account!\n";
    }

    void Withdraw(double amt) override {
        if (Balance >= amt) {
            Balance -= amt;
            LastAmount = amt;
            LastTransactionType = "Withdraw";
            HasLastTransaction = true;
            FileTransaction("Withdraw", amt, "savings_transactions.txt");
            cout << "Amount debited from savings account!\n";
        } else {
            cout << "Insufficient balance in savings account!\n";
        }
    }

    void UndoLastTransaction() override {
        if (!HasLastTransaction) {
            cout << "No transaction to undo!\n";
            return;
        }

        if (LastTransactionType == "Deposit") {
            Balance -= LastAmount;
            FileTransaction("UndoDeposit", LastAmount, "savings_transactions.txt");
            cout << "Last deposit undone. Amount " << LastAmount << " debited from savings account!\n";
        } else if (LastTransactionType == "Withdraw") {
            Balance += LastAmount;
            FileTransaction("UndoWithdraw", LastAmount, "savings_transactions.txt");
            cout << "Last withdrawal undone. Amount " << LastAmount << " credited to savings account!\n";
        }
        
        HasLastTransaction = false;
    }

    void PrintHistory() override {
        ifstream file("savings_transactions.txt");
        string type;
        double amt, bal;
        int acc;
        bool found = false;

        while (file >> acc >> type >> amt >> bal) {
            if (acc == AccountNumber) {
                cout << "Type: " << type << " | Amount: " << amt << " | Balance: " << bal << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No transactions found for this savings account.\n";
        }
    }

    static void ShowHistoryByAccountNumber(int accNo) {
        ifstream file("savings_transactions.txt");
        string type;
        double amt, bal;
        int acc;
        bool found = false;

        while (file >> acc >> type >> amt >> bal) {
            if (acc == accNo) {
                cout << "Type: " << type << " | Amount: " << amt << " | Balance: " << bal << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No transactions found for savings account number " << accNo << ".\n";
        }
    }
};

class CurrentAccount : public BankAccount {
    double OverDraftLmt;

public:
    CurrentAccount() {
        OverDraftLmt = 0.0;
    }

    CurrentAccount(int accNo, double bal, double limit) {
        AccountNumber = accNo;
        Balance = bal;
        OverDraftLmt = limit;
        LastAmount = 0.0;
        LastTransactionType = "";
        HasLastTransaction = false;
    }

    void Deposit(double amt) override {
        Balance += amt;
        LastAmount = amt;
        LastTransactionType = "Deposit";
        HasLastTransaction = true;
        FileTransaction("Deposit", amt, "current_transactions.txt");
        cout << "Amount credited to current account!\n";
    }

    void Withdraw(double amt) override {
        if (amt <= Balance + OverDraftLmt) {
            Balance -= amt;
            LastAmount = amt;
            LastTransactionType = "Withdraw";
            HasLastTransaction = true;
            FileTransaction("Withdraw", amt, "current_transactions.txt");
            cout << "Amount debited from current account!\n";
        } else {
            cout << "Overdraft limit exceeded!\n";
        }
    }

    void UndoLastTransaction() override {
        if (!HasLastTransaction) {
            cout << "No transaction to undo!\n";
            return;
        }

        if (LastTransactionType == "Deposit") {
            Balance -= LastAmount;
            FileTransaction("UndoDeposit", LastAmount, "current_transactions.txt");
            cout << "Last deposit undone. Amount " << LastAmount << " debited from current account!\n";
        } else if (LastTransactionType == "Withdraw") {
            Balance += LastAmount;
            FileTransaction("UndoWithdraw", LastAmount, "current_transactions.txt");
            cout << "Last withdrawal undone. Amount " << LastAmount << " credited to current account!\n";
        }
        
        HasLastTransaction = false;
    }

    void PrintHistory() override {
        ifstream file("current_transactions.txt");
        string type;
        double amt, bal;
        int acc;
        bool found = false;

        while (file >> acc >> type >> amt >> bal) {
            if (acc == AccountNumber) {
                cout << "Type: " << type << " | Amount: " << amt << " | Balance: " << bal << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No transactions found for this current account.\n";
        }
    }

    static void ShowHistoryByAccountNumber(int accNo) {
        ifstream file("current_transactions.txt");
        string type;
        double amt, bal;
        int acc;
        bool found = false;

        while (file >> acc >> type >> amt >> bal) {
            if (acc == accNo) {
                cout << "Type: " << type << " | Amount: " << amt << " | Balance: " << bal << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No transactions found for current account number " << accNo << ".\n";
        }
    }
};

int main() {
    int choice, accNo;
    double bal, amt, overdraft;
    float interest;

    SavingAccount sa;
    CurrentAccount ca;
    bool hasSavings = false, hasCurrent = false;

    do {
        cout << "\n----- Banking Menu -----\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Current Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Show Transaction History (Current Account)\n";
        cout << "6. Show Transaction History (Savings Account)\n";
        cout << "7. Show Transaction History by Account Number\n";
        cout << "8. Undo Last Transaction\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Interest Rate: ";
            cin >> interest;
            sa = SavingAccount(accNo, bal, interest);
            hasSavings = true;
            cout << "Savings account created.\n";
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Overdraft Limit: ";
            cin >> overdraft;
            ca = CurrentAccount(accNo, bal, overdraft);
            hasCurrent = true;
            cout << "Current account created.\n";
            break;

        case 3:
            cout << "Deposit to: 1. Savings  2. Current : ";
            cin >> choice;
            cout << "Enter Amount: ";
            cin >> amt;
            if (choice == 1 && hasSavings)
                sa.Deposit(amt);
            else if (choice == 2 && hasCurrent)
                ca.Deposit(amt);
            else
                cout << "Account not available.\n";
            break;

        case 4:
            cout << "Withdraw from: 1. Savings  2. Current : ";
            cin >> choice;
            cout << "Enter Amount: ";
            cin >> amt;
            if (choice == 1 && hasSavings)
                sa.Withdraw(amt);
            else if (choice == 2 && hasCurrent)
                ca.Withdraw(amt);
            else
                cout << "Account not available.\n";
            break;

        case 5:
            if (hasCurrent)
                ca.PrintHistory();
            else
                cout << "No current account exists.\n";
            break;

        case 6:
            if (hasSavings)
                sa.PrintHistory();
            else
                cout << "No savings account exists.\n";
            break;

        case 7:
            cout << "Enter account number: ";
            cin >> accNo;
            cout << "Is this 1. Savings or 2. Current account? ";
            cin >> choice;
            if (choice == 1)
                SavingAccount::ShowHistoryByAccountNumber(accNo);
            else if (choice == 2)
                CurrentAccount::ShowHistoryByAccountNumber(accNo);
            else
                cout << "Invalid type.\n";
            break;
            
        case 8:
            cout << "Undo transaction for: 1. Savings  2. Current : ";
            cin >> choice;
            if (choice == 1 && hasSavings)
                sa.UndoLastTransaction();
            else if (choice == 2 && hasCurrent)
                ca.UndoLastTransaction();
            else
                cout << "Account not available.\n";
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    cout<<"24CE014 JAYRAJSINH BHATTI";
    return 0;
}