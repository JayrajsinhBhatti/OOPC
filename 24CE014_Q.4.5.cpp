    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;

    class GradingSystem {
    protected:
        int marks;

    public:
        GradingSystem(int m){
            marks = m;
        }

        virtual void computeGrade() = 0;

        virtual ~GradingSystem() {}
    };

    class Undergraduate : public GradingSystem {
    public:
        Undergraduate(int m) : GradingSystem(m) {}

        void computeGrade() override {
            char grade;
            if (marks >= 90) grade = 'A';
            else if (marks >= 75) grade = 'B';
            else if (marks >= 50) grade = 'C';
            else grade = 'F';

            cout << "Undergraduate Grade: " << grade << endl;
        }
    };

    class Postgraduate : public GradingSystem {
    public:
        Postgraduate(int m) : GradingSystem(m) {}

        void computeGrade() override {
            char grade;
            if (marks >= 85) grade = 'A';
            else if (marks >= 70) grade = 'B';
            else if (marks >= 55) grade = 'C';
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
                    int marks;
                    cout << "Enter Undergraduate Marks: ";
                    cin >> marks;
                    students.push_back(new Undergraduate(marks));
                    break;
                }
                case 2: {
                    int marks;
                    cout << "Enter Postgraduate Marks: ";
                    cin >> marks;
                    students.push_back(new Postgraduate(marks));
                    break;
                }
                case 3:
                    for (auto student : students) {
                        student->computeGrade();
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
