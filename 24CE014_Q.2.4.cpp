#include<iostream>
using namespace std;

class Item {
public:
    int ProductID;
    string Name;
    int Quantity;
    float Price;

    Item() {
        ProductID = 0;
        Name = "";
        Quantity = 0;
        Price = 0;
    }

    void input() {
        cout << "Enter Item ID: ";
        cin >> ProductID;
        cout << "Enter Name of item: ";
        cin >> Name;
        cout << "Enter Quantity of item: ";
        cin >> Quantity;
        cout << "Enter Price: ";
        cin >> Price;
    }

    void display() const {
        cout << "ID: " << ProductID
             << " | Name: " << Name
             << " | Qty: " << Quantity
             << " | Price: " << Price << endl;
    }
};

class Inventory {
    Item items[10];
    int itemCount;
    float totalBill;

public:
    Inventory() {
        itemCount = 0;
        totalBill = 0;
    }

    void AddItem() {
        if(itemCount >= 10) {
            cout << "Inventory is full!" << endl;
            return;
        }
        items[itemCount].input();
        itemCount++;
        cout << "Item added successfully!\n";
    }

    void PurchaseItem() {
        int id, qty;
        cout << "Enter Product ID to purchase: ";
        cin >> id;
        cout << "Enter Quantity to purchase: ";
        cin >> qty;

        for(int i = 0; i < itemCount; i++) {
            if(items[i].ProductID == id) {
                if(items[i].Quantity >= qty) {
                    items[i].Quantity -= qty;
                    float billAmount = qty * items[i].Price;
                    totalBill += billAmount;
                    cout << "Purchase successful. Amount: " << billAmount << endl;
                } else {
                    cout << "Insufficient stock!" << endl;
                }
                return;
            }
        }
        cout << "Product ID not found!" << endl;
    }

    void DisplayInventory() {
        cout << "\n:: CURRENT INVENTORY DETAILS ::" << endl;
        for(int i = 0; i < itemCount; i++) {
            items[i].display();
        }
    }

    void Bill() {
        cout << "\n:: TOTAL BILL GENERATED : " << totalBill << " ::" << endl;
    }
};

int main() {
    Inventory store;
    int choice;

    do {
        cout << "\n:: ABC RETAIL STORE MENU ::" << endl;
        cout << "1. PURCHASE ITEM\n2. ADD ITEM TO INVENTORY\n3. DISPLAY INVENTORY\n4. DISPLAY BILL\n0. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                store.PurchaseItem();
                break;
            case 2:
                store.AddItem();
                break;
            case 3:
                store.DisplayInventory();
                break;
            case 4:
                store.Bill();
                break;
            case 0:
                cout << "Exiting system..." << endl;
                break;
            default:
                cout << "Invalid input. Try again!" << endl;
        }

    } while(choice != 0);
    cout<<"24CE014 JAYRAJSINH BHATTI";
    return 0;
}

