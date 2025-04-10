#include<iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
    int RollNumber;
    string name;
    float marks1, marks2, marks3, avg;

    inline float CalculateAvg() {
        float Avg = (marks1+marks2+marks3)/3.0;
        return Avg;
    }

    public:
    Student() {
        name = "Default";
        RollNumber = 0;
        marks1=0;
        marks2=0;
        marks3=0;
        avg=0;
    }

    void GetStudentInfo() {
        cout<<"Enter name of the student: ";
        cin>>name;

        cout<<"Enter Roll Number: ";
        cin>>RollNumber;

        cout<<"Enter Marks of Subject-1: ";
        cin>>marks1;

        cout<<"Enter Marks of Subject-2: ";
        cin>>marks2;

        cout<<"Enter Marks of Subject-3: ";
        cin>>marks3;

        avg = CalculateAvg();
    }

    void display() {
        cout << "\nRoll No: " << RollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks1 << ", " << marks2 << ", " << marks3 << endl;
        cout << "Average: " << avg << endl;
        cout << "---------------------------" << endl;
    }
};

int main()
{
    vector<Student> st;
    string choice;

    do
    {
        Student s;
        s.GetStudentInfo();
        st.push_back(s);

        cout<<"Do you want to enter marks?: (y/n)";
        cin>>choice;

        if (choice=="n")
        {
            cout<<"Student details entered successfully"<<endl;
            break;
        }
        
    } while (choice=="y");

    for(auto &s: st) {
        s.display();
    }
    
    return 0;
}