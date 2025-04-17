#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Inventory {
    int ProductCount = 0;
    int Product[30];
    string Names[30];
    int Prices[30];
    int Quantities[30] = {0};
    double Totalvalue = 0;

public:
    // Search Product by ID
    int Search(int id) {
        for (int i = 0; i < ProductCount; i++) {
            if (Product[i] == id) {
                return i; // Return index if found
            }
        }
        return -1; // Not found
    }

    // Add or Update Product
    void AddOrUpdate(int id, string Name, int Price) {
        int index = Search(id);
        if (index != -1) {
            // Product exists, update quantity
            Quantities[index]++;
            cout << "\nProduct quantity updated successfully!\n";
        } else {
            // Add new Product
            if (ProductCount >= 30) {
                cout << "List is full!" << endl;
                return;
            }
            Product[ProductCount] = id;
            Names[ProductCount] = Name;
            Prices[ProductCount] = Price;
            Quantities[ProductCount] = 1;
            ProductCount++;
            cout << "\nProduct added successfully!\n";
        }
        CalculateTotalValue();
    }

    // Calculate Total Value
    void CalculateTotalValue() {
        Totalvalue = 0;
        for (int i = 0; i < ProductCount; i++) {
            Totalvalue += Prices[i] * Quantities[i];
        }
    }

    // Print Bill
    void PrintBill() {
        if (ProductCount == 0) {
            cout << "\nNo Products to display.\n";
            return;
        }
        cout << "\n--- Bill Summary ---\n";
        cout << left << setw(10) << "ID" 
             << setw(15) << "Name" 
             << setw(10) << "Quantity" 
             << setw(10) << "Price" 
             << setw(10) << "Total\n";
        cout << "------------------------------------------------------------\n";

        for (int i = 0; i < ProductCount; i++) {
            cout << left << setw(10) << Product[i]
                 << setw(15) << Names[i]
                 << setw(10) << Quantities[i]
                 << setw(10) << Prices[i]
                 << setw(10) << (Prices[i] * Quantities[i]) 
                 << endl;
        }

        cout << "------------------------------------------------------------\n";
        cout << "Grand Total: " << Totalvalue << "\n";
    }
};

int main() {
    int Pid, Price;
    string Name;
    Inventory inventory;
    int choice;

    do {
        cout << "\n--- Inventory Management System ---\n";
        cout << "1. Add Product\n";
        //cout << "2. Print Bill\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter Product ID: ";
                cin >> Pid;

                cout << "Enter Product Name: ";
                cin.ignore();
                getline(cin, Name);

                cout << "Enter Product Price: ";
                cin >> Price;

                inventory.AddOrUpdate(Pid, Name, Price);
                break;

            /*case 2:
                inventory.PrintBill();
                break;*/

            case 0:
                inventory.PrintBill();
                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
                break;
        }
    } while (choice != 0);

    cout << "24CE014 JAYRAJSINH BHATTI";

    return 0;
}
