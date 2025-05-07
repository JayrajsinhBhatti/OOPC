#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Item {
    char Name[50];
    int Quantity;
    float Price;

public:
    void GetDetails() {
        cout << "Enter item Name: ";
        cin >> Name;
        cout << "Enter Quantity: ";
        cin >> Quantity;
        cout << "Enter Price: ";
        cin >> Price;
    }

    void SaveToFile() {
        ofstream file("inventory.txt", ios::app);
        if (!file) {
            cout << "Error opening file.\n";
            return;
        }
        file << Name << " " << Quantity << " " << Price << endl;
        file.close();
    }

    void Display() {
        cout << "Name: " << Name
             << ", Quantity: " << Quantity
             << ", Price: " << Price << endl;
    }

    bool Search(const char* searchName) {
        return strcmp(Name, searchName) == 0;
    }

    bool LoadFromFile(ifstream& file) {
        file >> Name >> Quantity >> Price;
        return file.good();
    }
};

class InventoryManager {
public:
    void AddItem() {
        Item item;
        item.GetDetails();
        item.SaveToFile();
        cout << "Item added successfully.\n";
    }

    void CheckInventory() {
        ifstream file("inventory.txt");
        if (!file) {
            cout << "No inventory found.\n";
            return;
        }

        Item item;
        cout << "\nInventory:\n";
        while (item.LoadFromFile(file)) {
            item.Display();
        }
        file.close();
    }

    void SearchItem() {
        char searchName[50];
        cout << "Enter item Name to search: ";
        cin >> searchName;

        ifstream file("inventory.txt");
        if (!file) {
            cout << "No inventory found.\n";
            return;
        }

        Item item;
        bool found = false;
        while (item.LoadFromFile(file)) {
            if (item.Search(searchName)) {
                cout << "Found item:\n";
                item.Display();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Item not found.\n";
        }

        file.close();
    }
};

int main() {
    InventoryManager manager;
    int Choice;

    do {
        cout << "\n1. Add Item\n2. View Inventory\n3. Search Item\n0. Exit\n";
        cout << "Enter your Choice: ";
        cin >> Choice;

        switch (Choice) {
            case 1: 
                manager.AddItem(); break;
            case 2: 
                manager.CheckInventory(); break;
            case 3: 
                manager.SearchItem(); break;
            case 0: 
                cout << "Exiting...\n"; break;
            default: 
                cout << "Invalid Choice.\n";
        }
    } while (Choice != 0);

    cout << "\n24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}
