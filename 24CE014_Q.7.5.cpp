#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    string Name;
    double Marks;
    double TuitionFee;

    Student(const string& name, double marks, double tuitionFee) {
        Name = name;
        Marks = marks;
        TuitionFee = tuitionFee;
    }
};

class UniversitySystem {
private:
    vector<Student> Students;
    string CurrencySymbol;

public:
    UniversitySystem(const string& currencySymbol = "$")
        : CurrencySymbol(currencySymbol) {}

    void AddStudent(const string& name, double marks, double tuitionFee) {
        Students.push_back(Student(name, marks, tuitionFee));
    }

    void DisplayStudentRecords() {
        cout << setw(15) << left << "Name"
             << setw(10) << "Marks"
             << setw(15) << "Tuition Fees" << endl;

        for (const auto& student : Students) {
            cout << setw(15) << left << student.Name
                 << setw(10) << fixed << setprecision(2) << student.Marks
                 << CurrencySymbol << fixed << setprecision(2) << student.TuitionFee
                 << endl;
        }
    }
};

int main() {
    string currencySymbol;
    cout << "Enter the currency symbol (e.g., $, €, ₹): ";
    cin >> currencySymbol;

    UniversitySystem University(currencySymbol);

    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore();

    for (int i = 0; i < numStudents; ++i) {
        string name;
        double marks, tuitionFee;

        cout << "\nEnter details for student " << i + 1 << ":" << endl;

        cout << "Student Name: ";
        getline(cin, name);

        cout << "Marks: ";
        cin >> marks;

        cout << "Tuition Fee: ";
        cin >> tuitionFee;
        cin.ignore();

        University.AddStudent(name, marks, tuitionFee);
    }

    cout << "\nUNIVERSITY STUDENT RECORDS\n";
    University.DisplayStudentRecords();

    cout << "\n24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}
