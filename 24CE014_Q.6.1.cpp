#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int Size;
    int Capacity;

    void Resize() {
        Capacity *= 2;
        int* newData = new int[Capacity];
        for (int i = 0; i < Size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynamicArray() {
        Size = 0;
        Capacity = 2;
        data = new int[Capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void Insert(int Value) {
        if (Size == Capacity) {
            Resize();
        }
        data[Size++] = Value;
        cout << "Inserted: " << Value << endl;
    }

    void RemoveAt(int Index) {
        if (Index < 0 || Index >= Size) {
            cout << "Error: Invalid Index.\n";
            return;
        }

        for (int i = Index; i < Size - 1; i++) {
            data[i] = data[i + 1];
        }

        Size--;
        cout << "Removed element at Index: " << Index << endl;
    }

    void Display() {
        if (Size == 0) {
            cout << "Array is empty.\n";
            return;
        }

        cout << "Array elements: ";
        for (int i = 0; i < Size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr;
    int choice, Value, Index;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert\n2. Remove at Index\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Value to Insert: ";
                cin >> Value;
                arr.Insert(Value);
                break;
            case 2:
                cout << "Enter Index to remove: ";
                cin >> Index;
                arr.RemoveAt(Index);
                break;
            case 3:
                arr.Display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    cout << "\n24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}
