#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    double price;
};

// load items from a file
void loadItems(const string& filename, vector<Item>& items, int& nextId) {
    items.clear();
    ifstream file(filename);

    // Handle error if the file cannot be opened
    if (!file.is_open()) {
        cerr << "Error: Could not open the file '" << filename << "'.\n";
        exit(1);  // Exit the program if the file can't be opened
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        Item item;

        getline(ss, temp, ',');  // Get item ID
        item.id = stoi(temp);
        getline(ss, item.name, ',');  // Get item name
        getline(ss, temp, ',');  // Get quantity
        item.quantity = stoi(temp);
        getline(ss, temp, ',');  // Get price
        item.price = stod(temp);

        items.push_back(item);
    }

    nextId = items.empty() ? 1 : items.back().id + 1;
}

// save items to a file
void saveItems(const string& filename, const vector<Item>& items) {
    ofstream file(filename);
    for (const auto& item : items) {
        file << item.id << "," << item.name << "," << item.quantity << "," << item.price << endl;
    }
}

// add a new item
void addItem(vector<Item>& items, int& nextId, const string& filename) {
    Item newItem;
    newItem.id = nextId++;

    cout << "Enter item name: ";
    getline(cin, newItem.name);
    cout << "Enter quantity: ";
    cin >> newItem.quantity;
    cout << "Enter price: ";
    cin >> newItem.price;
    cin.ignore();  // Clear the buffer

    items.push_back(newItem);
    saveItems(filename, items);

    cout << "Item added successfully!\n";
}

// display all items
void viewItems(const vector<Item>& items) {
    if (items.empty()) {
        cout << "No items in inventory.\n";
        return;
    }

    cout << "\n--- Inventory ---\n";
    for (const auto& item : items) {
        cout << "ID: " << item.id
             << ", Name: " << item.name
             << ", Quantity: " << item.quantity
             << ", Price: $" << item.price << endl;
    }
}

// search for an item by name
void searchByName(const vector<Item>& items) {
    string name;
    cout << "Enter item name to search: ";
    getline(cin, name);

    bool found = false;
    for (const auto& item : items) {
        if (item.name == name) {
            cout << "Found: ID=" << item.id << ", Qty=" << item.quantity << ", Price=$" << item.price << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Item not found.\n";
    }
}

// update item quantity
void updateQuantity(vector<Item>& items, const string& filename) {
    int id, newQty;
    cout << "Enter item ID: ";
    cin >> id;
    cout << "Enter new quantity: ";
    cin >> newQty;
    cin.ignore();  // Clear buffer

    bool updated = false;
    for (auto& item : items) {
        if (item.id == id) {
            item.quantity = newQty;
            updated = true;
            break;
        }
    }

    if (updated) {
        saveItems(filename, items);
        cout << "Quantity updated successfully!\n";
    } else {
        cout << "Item not found.\n";
    }
}

int main() {
    const string filename = "inventory.csv";
    vector<Item> items;
    int nextId = 1;

    loadItems(filename, items, nextId);  // Load items with error handling for file

    int choice;
    do {
        cout << "\n--- Inventory System ---\n";
        cout << "1. Add Item\n2. View Items\n3. Search by Name\n4. Update Quantity\n0. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();  // Clear input buffer

        switch (choice) {
            case 1: 
                addItem(items, nextId, filename); 
                break;
            case 2: 
                viewItems(items); 
                break;
            case 3: 
                searchByName(items); 
                break;
            case 4: 
                updateQuantity(items, filename); 
                break;
            case 0: 
                cout << "Goodbye!\n"; 
                break;
            default: 
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    cout << "24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}
