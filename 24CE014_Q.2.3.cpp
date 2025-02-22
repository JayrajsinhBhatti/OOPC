#include <iostream>
#include<string>
using namespace std;

class Account_Details {
    int account_number;
    int AllAccounts[10], i=0;
    float current_balance, withdraw_balance, deposit_balance;
    string name;

    public:

    bool check(int account_number) {
        for(int j=0;j<10;j++)
        {
            if (AllAccounts[i] == account_number)
            {
                return true;
            }
            
        }
        return false;
    }

    void create_account() {
        string choice;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter a new account number: ";
        cin>>account_number;
        AllAccounts[i] = account_number;
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
        cout<<"Enter account number: ";
        cin>>account_number;

        if (check(account_number))
        {
            cout<<"Enter amount to deposit: ";
            cin>>deposit_balance;
            current_balance += deposit_balance;
            cout<<"Amount credited successfully!"<<endl;
        } else {
            cout<<"Account does not exist!"<<endl;
        }

    }

    void withdraw_money() {
        cout<<"Enter account number: ";
        cin>>account_number;

        if (check(account_number))
        {
            cout<<"Enter amount to withdraw: ";
            cin>>withdraw_balance;

            if(withdraw_balance>current_balance) {
                cout<<"Insufficient balance!"<<endl;
        } else {
            current_balance -= withdraw_balance;
            cout<<"Amount debited successfully!"<<endl;
            }
        } else {
            cout<<"Account does not exist!"<<endl;
        }
    }

    void display() {
        if (check(account_number))
        {
            cout<<"Account number: "<<account_number<<endl;
            cout<<"Amount credited: "<<withdraw_balance<<endl;
            cout<<"Amount debited: "<<deposit_balance<<endl;
            cout<<"Total balance: "<<current_balance<<endl;
        }


    }
};

int main() {
    int account_number,choice;
    Account_Details a;
    //cout<<"Enter account number: ";
    //cin>>account_number;

    do{
        cout<<"Enter:: \n 1-DEPOSIT \n 2-WITHDRAW \n 3-CREATE ACCOUNT \n 4-SHOW ACCOUNT STATUS \n 0-EXIT"<<endl;
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
        case 4:
            a.display();
            break;
        case 0:
            cout<<"Exitting program...."<<endl;
            break;
        default:
            cout<<"Invalid input!"<<endl;  
        }

    } while(choice!=0);

    return 0;
}
