#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string Name;
    int Age;

public:
    Person() {}

    void InputPerson() {
        cout << "Enter your name: ";
        cin >> Name;
        cout << "Enter your age: ";
        cin >> Age;
    }

    void DisplayPerson() const {
        cout << "Name: " << Name << ", Age: " << Age << endl;
    }
};

class Employee : public Person {
protected:
    int ID;

public:
    Employee() {}

    void InputEmployee() {
        InputPerson();
        cout << "Enter Employee ID: ";
        cin >> ID;
    }

    void DisplayEmployee() const {
        DisplayPerson();
        cout << "Employee ID: " << ID << endl;
    }

    int GetID() const {
        return ID;
    }
};

class Manager : public Employee {
    string Department;

public:
    Manager() {}

    void InputManager() {
        InputEmployee();
        cout << "Enter Department: ";
        cin >> Department;
    }

    void DisplayManager() const {
        DisplayEmployee();
        cout << "Department: " << Department << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {
    vector<Manager> managerVector;
    Manager managerArray[10];
    int count = 0;
    int choice;

    do {
        cout << "\n1. Add Manager\n2. Display All Managers (Vector)\n3. Display by ID (Array)\n0. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (count >= 10) {
                cout << "Manager array is full!" << endl;
                break;
            }
            {
                Manager m;
                m.InputManager();
                managerVector.push_back(m);
                managerArray[count] = m;
                count++;
            }
            break;

        case 2:
            for (const auto& m : managerVector) {
                m.DisplayManager();
            }
            break;

        case 3: {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < count; ++i) {
                if (managerArray[i].GetID() == id) {
                    managerArray[i].DisplayManager();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Manager with ID " << id << " not found!" << endl;
            }
            break;
        }

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }

    } while (choice != 0);

    cout << "24CE014 JAYRAJSINH BHATTI";
    return 0;
}

