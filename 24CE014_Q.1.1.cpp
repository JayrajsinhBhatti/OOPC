#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNumber, double initialBalance) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrawal successful. New balance: " << balance << endl;
            } else {
                cout << "Insufficient balance. Withdrawal failed." << endl;
            }
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void displayAccountDetails() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    
    string name;
    int acc;
    double InitialBalance;

    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter account number: ";
    cin>>acc;
    cout<<"Enter initial Balance for deposit: ";
    cin>>InitialBalance;

    BankAccount myAccount("Jayrajsinh Bhatti", 1001, 5000.00);

    int choice;
    double amount;

    do {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Account Details\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                myAccount.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 3:
                cout << "Current Balance: " << myAccount.getBalance() << endl;
                break;
            case 4:
                myAccount.displayAccountDetails();
                break;
            case 0:
                cout << "Thank you for using the Bank System!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
