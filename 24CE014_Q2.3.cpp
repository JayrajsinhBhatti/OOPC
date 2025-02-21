#include <iostream>
#include<string>
using namespace std;

class Account_Details {
    int account_number;
    float current_balance, withdraw_balance, deposit_balance;
    string name;

    public:

    void create_account() {
        string choice;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Do you want to deposit amount in account?";
        cin>>choice;
        if(choice=="yes" || choice=="Yes" || choice=="YES") {
            deposit_money();
        }
        else {
            cout<<"Account created!"<<endl;
        }
    }

    void deposit_money() {
        //cout<<"Enter account number: ";
        //cin>>account_number;
        cout<<"Enter amount to deposit: ";
        cin>>deposit_balance;
        current_balance += deposit_balance;
    }

    void withdraw_money() {
        //cout<<"Enter account number: ";
        //cin>>account_number;
        cout<<"Enter amount to withdraw: ";
        cin>>withdraw_balance;
        if(withdraw_balance>current_balance) {
            cout<<"Insufficient balance!"<<endl;
        }
        else {
            current_balance -= withdraw_balance;
        cout<<"Amount debited!"<<endl;
        }
    }

    void display() {
        cout<<"Account number: "<<account_number;
        cout<<"Amount credited: "<<withdraw_balance<<endl;
        cout<<"Amount debited: "<<deposit_balance;
        cout<<"Total balance: "<<current_balance;
    }
};

int main() {
    int account_number,choice;
    Account_Details a;
    cout<<"Enter account number: ";
    cin>>account_number;

    do{
        cout<<"Enter:: \n 1-DEPOSIT \n 2-WITHDRAW \n 3-CREATE ACCOUNT \n 4-EXIT"<<endl;
        cin>>choice;

        switch(choice) {
        case 1:
            a.deposit_money();
            break;

        case 2:
            a.withdraw_money();
            break;

        case 3:
            a.create_account();
            break;
        default:
            cout<<"Invalid input!"<<endl;
        }

    } while(choice!=0);

    a.display();


    return 0;
}

