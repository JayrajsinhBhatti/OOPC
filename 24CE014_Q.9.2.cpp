#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
private:
    string AccountHolder;
    double Balance;
    vector<string> logs; //store entries

public:
    BankAccount(string Name, double InitialBalance) {
        AccountHolder = Name;
        Balance = InitialBalance;
        logs.push_back("Account created for " + AccountHolder + " with Balance: " + to_string(Balance));
    }

    void deposit(double amount) {
        if (amount <= 0) {
            log("Deposit failed: Invalid amount.");
            cout << "Invalid deposit amount.\n";
            return;
        }
        Balance += amount;
        log("Deposited: " + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            log("Withdrawal failed: Invalid amount.");
            cout << "Invalid withdrawal amount.\n";
            return;
        }
        if (amount > Balance) {
            log("Withdrawal failed: Insufficient Balance.");
            cout << "Insufficient Balance.\n";
            return;
        }
        Balance -= amount;
        log("Withdrew: " + to_string(amount));
    }

    void displayBalance() const {
        cout << "Current Balance: " << Balance << endl;
    }

    void showLogs() const {
        cout << "\nTransaction Logs:\n";
        for (string entry : logs) {
            cout << "- " << entry << endl;
        }
    }

private:
    void log(string message) {
        logs.push_back(message);
    }
};

int main() {
    string Name;
    double InitialBalance;

    cout << "Enter account holder Name: ";
    getline(cin, Name);
    cout << "Enter initial Balance: ";
    cin >> InitialBalance;

    BankAccount account(Name, InitialBalance);

    int choice;
    double amount;

    do {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Deposit\n2. Withdraw\n3. Show Balance\n4. Show Logs\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.displayBalance();
                break;
            case 4:
                account.showLogs();
                break;
            case 5:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);
    cout<<"\n24CE014 JAYRAJSINH BHATTI";
    return 0;
}
