#include <iostream>
#include <string>
using namespace std;

class Account_Details {
    int account_number;
    float current_balance = 0, withdraw_balance = 0, deposit_balance = 0;
    string name;
    
public:
    void create_account(int acc_no) {
        string choice;
        account_number = acc_no;
        cout << "Enter name: ";
        cin >> name;
        cout << "Do you want to deposit amount in account? (yes/no): ";
        cin >> choice;

        if (choice == "yes" || choice == "Yes" || choice == "YES") {
            deposit_money();
        }
        else {
            cout << "Account created!" << endl;
        }
    }

    void deposit_money() {
        cout << "Enter amount to deposit: ";
        cin >> deposit_balance;
        current_balance += deposit_balance;
        cout << "Amount deposited!" << endl;
    }

    void withdraw_money() {
        cout << "Enter amount to withdraw: ";
        cin >> withdraw_balance;
        if (withdraw_balance > current_balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            current_balance -= withdraw_balance;
            cout << "Amount debited!" << endl;
        }
    }

    void display() {
        cout << "\nAccount number: " << account_number << endl;
        cout << "Amount credited (deposit): " << deposit_balance << endl;
        cout << "Amount debited (withdrawn): " << withdraw_balance << endl;
        cout << "Total balance: " << current_balance << endl;
    }
};

int main() {
    int acc_no, choice;
    Account_Details a;

    cout << "Enter account number: ";
    cin >> acc_no;

    a.create_account(acc_no);

    do {
        cout << "\nEnter:: \n 1-DEPOSIT \n 2-WITHDRAW \n 3-DISPLAY \n 4-EXIT" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                a.deposit_money();
                break;
            case 2:
                a.withdraw_money();
                break;
            case 3:
                a.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid input!" << endl;
        }
    } while (choice != 4);

    return 0;
}
