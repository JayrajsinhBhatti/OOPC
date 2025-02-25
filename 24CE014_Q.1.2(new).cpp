#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Inventory {
    int productCount = 0;
    int product[30];
    string names[30];
    int prices[30];
    int quantities[30] = {0};
    double Totalvalue = 0;

public:
    // Search Product by ID
    int search(int id) {
        for (int i = 0; i < productCount; i++) {
            if (product[i] == id) {
                return i; // Return index if found
            }
        }
        return -1; // Not found
    }

    // Add or Update Product
    void addOrUpdate(int id, string name, int price) {
        int index = search(id);
        if (index != -1) {
            // Product exists, update quantity
            quantities[index]++;
            cout << "\nProduct quantity updated successfully!\n";
        } else {
            // Add new product
            if (productCount >= 30) {
                cout << "List is full!" << endl;
                return;
            }
            product[productCount] = id;
            names[productCount] = name;
            prices[productCount] = price;
            quantities[productCount] = 1;
            productCount++;
            cout << "\nProduct added successfully!\n";
        }
        calculateTotalValue();
    }

    // Calculate Total Value
    void calculateTotalValue() {
        Totalvalue = 0;
        for (int i = 0; i < productCount; i++) {
            Totalvalue += prices[i] * quantities[i];
        }
    }

    // Print Bill
    void PrintBill() {
        if (productCount == 0) {
            cout << "\nNo products to display.\n";
            return;
        }
        cout << "\n--- Bill Summary ---\n";
        cout << left << setw(10) << "ID" 
             << setw(15) << "Name" 
             << setw(10) << "Quantity" 
             << setw(10) << "Price" 
             << setw(10) << "Total\n";
        cout << "------------------------------------------------------------\n";

        for (int i = 0; i < productCount; i++) {
            cout << left << setw(10) << product[i]
                 << setw(15) << names[i]
                 << setw(10) << quantities[i]
                 << setw(10) << prices[i]
                 << setw(10) << (prices[i] * quantities[i]) 
                 << endl;
        }

        cout << "------------------------------------------------------------\n";
        cout << "Grand Total: " << Totalvalue << "\n";
    }
};

int main() {
    int pid, price;
    string name;
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
                cin >> pid;

                cout << "Enter Product Name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter Product Price: ";
                cin >> price;

                inventory.addOrUpdate(pid, name, price);
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

    return 0;
}
