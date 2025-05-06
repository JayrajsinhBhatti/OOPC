#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class StudentReport {
private:
    string fileName;

    // User-defined manipulator for fixed-width column
    static ostream& Col(ostream& Os) {
        return Os << left << setw(20);
    }

public:
    // Constructor to initialize the file name
    StudentReport(const string& file) : fileName(file) {}

    // Function to generate the student performance report
    void GenerateReport() const {
        ifstream inputFile(fileName);
        if (!inputFile.is_open()) {
            cerr << "Error: Could not open file '" << fileName << "'.\n";
            return;
        }

        string studentName;
        int studentMarks;
        char studentGrade;

        cout << "\n===== STUDENT PERFORMANCE REPORT =====\n";
        cout << Col << "Name"
                  << setw(10) << "Marks"
                  << setw(10) << "Grade" << "\n";
        cout << string(40, '-') << "\n";

        while (inputFile >> ws && getline(inputFile, studentName, ',')) {
            inputFile >> studentMarks >> studentGrade;
            inputFile.ignore();  // Skip newline or trailing whitespace

            cout << Col << studentName
                      << setw(10) << studentMarks
                      << setw(10) << studentGrade << "\n";
        }

        inputFile.close();
        cout << "======================================\n";
    }
};

int main() {
    const string fileName = "students.txt";
    StudentReport report(fileName);
    report.GenerateReport();
    cout<<"24CE014 JAYRAJSINH BHATTI";
    return 0;
}
