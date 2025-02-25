#include<iostream>
using namespace std;

class ItemStock
{
    int ProductID[10], ID, quantity=0;
    string name;
    float price;

public:

    void AddItem() {
        cout<<"Enter Item ID: ";
        cin>>ID;
        cout<<"Enter name of item: ";
        cin>>name;
        cout<<"Enter quantity of item: ";
        cin>>quantity;

        cout<<"Enter price: ";
        cin>>price;
    }

    void PurchaseItem() {
        cout<<"Enter product ID: ";
        cin>>ID;
        cout<<"Enter quantity: ";
        cin>>quantity;

        search();
    }

    void search() {
        for(int i=0; i<10; i++) {
            if(ProductID[i]==ID) {
                quantity++;
            }
        }
    }

    void DisplayInventory() {
        cout<<":: ABC RETAIL STORE ::"<<endl;
        //cout<<"Name:
    }

    void Bill() {

    }
};

int main()
{
    ItemStock i;
    int choice;

    do {
        cout<<":: ABC RETAIL Store ::"<<endl;
        cout<<"Enter: 1-PURCHASE \n 2-ADD ITEM IN INVENTIRY \n 3-DISPLAY CURRENT INVENTORY DETAILS \n 4-DIPLSAY BILL \n 0-EXIT"<<endl;
        cin>>choice;

        switch(choice) {
            case 1:
                i.PurchaseItem();
                break;

            case 2:
                i.AddItem();
                break;

            case 3:
                i.DisplayInventory();
                break;
            case 4:
                i.Bill();
                break;
            case 0:
                cout<<"Exitting..."<<endl;
            default:
                cout<<"Invalid input."<<endl;
        }
    } while(choice!=0);

    return 0;
}
