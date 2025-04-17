#include <iostream>
#include <vector>
using namespace std;

class Account {
    int AccNo;
    string Name;
    float Balance;

public:
    Account(int acc, string accHolder, float bal) {
        AccNo = acc;
        Name = accHolder;
        Balance = bal;
    }

    int GetAccNumber() const {
        return AccNo;
    }

    float GetBalance() const {
        return Balance;
    }

    void Deposit(float amount) {
        Balance += amount;
    }

    bool Withdraw(float amount) {
        if (amount > Balance) {
            cout << "Insufficient Balance!" << endl;
            return false;
        }
        Balance -= amount;
        return true;
    }

    void Display() const {
        cout << "Account No: " << AccNo
             << ", Name: " << Name
             << ", Balance: " << Balance << endl;
    }

    bool Tranfer(Account &receiver, float amount) {
        if (Withdraw(amount)) {
            receiver.Deposit(amount);
            return true;
        }
        return false;
    }
};

class Bank {
    vector<Account> accounts;
    int nextAccNo = 1001;

public:
    void CreateAccount() {
        string Name;
        float DepositAmount;

        cout << "Enter account holder's Name: ";
        cin >> Name;
        cout << "Enter initial Deposit amount: ";
        cin >> DepositAmount;

        Account newAcc(nextAccNo, Name, DepositAmount);
        accounts.push_back(newAcc);

        cout << "Account created successfully!" << endl;
        cout << "Your Account Number is: " << nextAccNo << endl;

        nextAccNo++;
    }

    Account* FindAccount(int AccNo) {
        for (auto &acc : accounts) {
            if (acc.GetAccNumber() == AccNo)
                return &acc;
        }
        return nullptr;
    }

    void DepositMoney() {
        int AccNo;
        float amount;
        cout << "Enter account number: ";
        cin >> AccNo;
        Account* acc = FindAccount(AccNo);

        if (acc) {
            cout << "Enter amount to Deposit: ";
            cin >> amount;
            acc->Deposit(amount);
            cout << "Amount Deposited successfully!" << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void WithdrawMoney() {
        int AccNo;
        float amount;
        cout << "Enter account number: ";
        cin >> AccNo;
        Account* acc = FindAccount(AccNo);

        if (acc) {
            cout << "Enter amount to Withdraw: ";
            cin >> amount;
            if (acc->Withdraw(amount)) {
                cout << "Withdrawal successful!" << endl;
            }
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void TranferMoney() {
        int fromAccNo, toAccNo;
        float amount;

        cout << "Enter sender's account number: ";
        cin >> fromAccNo;
        cout << "Enter receiver's account number: ";
        cin >> toAccNo;
        cout << "Enter amount to Tranfer: ";
        cin >> amount;

        Account* sender = FindAccount(fromAccNo);
        Account* receiver = FindAccount(toAccNo);

        if (sender && receiver) {
            if (sender->Tranfer(*receiver, amount)) {
                cout << "Tranfer successful!" << endl;
            }
        } else {
            cout << "One or both account numbers are invalid!" << endl;
        }
    }

    void DisplayAllAccounts() {
        cout << "\n--- All Accounts ---" << endl;
        for (const auto &acc : accounts) {
            acc.Display();
        }
        cout << "Total accounts: " << accounts.size() << endl;
    }
};

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n--- ABC COMMUNITY BANK ---" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Tranfer" << endl;
        cout << "5. Show All Accounts" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bank.CreateAccount();
            break;
        case 2:
            bank.DepositMoney();
            break;
        case 3:
            bank.WithdrawMoney();
            break;
        case 4:
            bank.TranferMoney();
            break;
        case 5:
            bank.DisplayAllAccounts();
            break;
        case 0:
            cout << "Exiting system. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
    cout<<"24CE014 JAYRAJSINH BHATTI";
    return 0;
}
