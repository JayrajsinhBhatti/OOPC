    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;

    class GradingSystem {
    protected:
        int Marks;

    public:
        GradingSystem(int m){
            Marks = m;
        }

        virtual void ComputeGrade() = 0;
    };

    class Undergraduate : public GradingSystem { //initializer list
    public:
        Undergraduate(int m) : GradingSystem(m) {

        }

        void ComputeGrade() {
            char grade;
            if (Marks >= 85) grade = 'A';
            else if (Marks >= 75) grade = 'B';
            else if (Marks >= 50) grade = 'C';
            else grade = 'F';

            cout << "Undergraduate Grade: " << grade << endl;
        }
    };

    class Postgraduate : public GradingSystem {
    public:
        Postgraduate(int m) : GradingSystem(m) {}

        void ComputeGrade() {
            char grade;
            if (Marks >= 90) grade = 'A';
            else if (Marks >= 70) grade = 'B';
            else if (Marks >= 55) grade = 'C';
            else grade = 'F';

            cout << "Postgraduate Grade: " << grade << endl;
        }
    };

    int main() {
        vector<GradingSystem*> students;

        int choice;
        do {
            cout << "\n1. Add Undergraduate\n2. Add Postgraduate\n3. Display Grades\n0. Exit\nEnter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int Marks;
                    cout << "Enter Undergraduate Total Marks: ";
                    cin >> Marks;
                    students.push_back(new Undergraduate(Marks));
                    break;
                }
                case 2: {
                    int Marks;
                    cout << "Enter Postgraduate Total Marks: ";
                    cin >> Marks;
                    students.push_back(new Postgraduate(Marks));
                    break;
                }
                case 3:
                    for (auto student : students) {
                        student->ComputeGrade();
                    }
                    break;
                case 0:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }

        } while (choice != 0);

        for (auto student : students) {
            delete student;
        }

        cout<<"24CE014 JAYRAJSINH BHATTI";

        return 0;
    }
