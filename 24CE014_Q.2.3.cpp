#include <iostream>
#include <string>
using namespace std;

class Account_Details {
    int AccountNumber;
    float CurrentBalance = 0, WithdrawBalance = 0, DepositBalance = 0;
    string Name;
    
public:
    void CreateAccount(int acc_no) {
        string choice;
        AccountNumber = acc_no;
        cout << "Enter Name: ";
        cin >> Name;
        cout << "Do you want to deposit amount in account? (yes/no): ";
        cin >> choice;

        if (choice == "yes" || choice == "Yes" || choice == "YES") {
            DepositMoney();
        }
        else {
            cout << "Account created!" << endl;
        }
    }

    void DepositMoney() {
        cout << "Enter amount to deposit: ";
        cin >> DepositBalance;
        CurrentBalance += DepositBalance;
        cout << "Amount deposited!" << endl;
    }

    void WithdrawMoney() {
        cout << "Enter amount to withdraw: ";
        cin >> WithdrawBalance;
        if (WithdrawBalance > CurrentBalance) {
            cout << "Insufficient balance!" << endl;
        } else {
            CurrentBalance -= WithdrawBalance;
            cout << "Amount debited!" << endl;
        }
    }

    void Display() {
        cout << "\nAccount number: " << AccountNumber << endl;
        cout << "Amount credited (deposit): " << DepositBalance << endl;
        cout << "Amount debited (withdrawn): " << WithdrawBalance << endl;
        cout << "Total balance: " << CurrentBalance << endl;
    }
};

int main() {
    int acc_no, choice;
    Account_Details a;

    cout << "Enter account number: ";
    cin >> acc_no;

    a.CreateAccount(acc_no);

    do {
        cout << "\nEnter:: \n 1-DEPOSIT \n 2-WITHDRAW \n 3-DISPLAY \n 4-EXIT" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                a.DepositMoney();
                break;
            case 2:
                a.WithdrawMoney();
                break;
            case 3:
                a.Display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid input!" << endl;
        }
    } while (choice != 4);

    return 0;

    cout << "24CE014 JAYRAJSINH BHATTI";
}
