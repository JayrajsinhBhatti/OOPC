#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ostream& tab(ostream& os) {
    return os << setw(15) << left;
}

class StudentManager {
public:
    void DisplayRecords() {
        ifstream file("Stu.txt");

        if (!file) {
            cout << "Error: Could not open file.\n";
            return;
        }

        char Name[50];
        int Marks;
        char Grade;

        cout << tab << "Name" << tab << "Marks" << tab << "Grade" << endl;

        while (file >> Name >> Marks >> Grade) {
            cout << tab << Name << tab << Marks << tab << Grade << endl;
        }

        file.close();
    }
};

int main() {
    StudentManager manager;
    manager.DisplayRecords();

    cout << "\n24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}
