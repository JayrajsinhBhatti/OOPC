#include<iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
    int RollNumber;
    string Name;
    float Marks1, Marks2, Marks3, Avg;

    inline float CalculateAvg() {
        float Avg = (Marks1+Marks2+Marks3)/3.0;
        return Avg;
    }

    public:
    Student() {
        Name = "Default";
        RollNumber = 0;
        Marks1=0;
        Marks2=0;
        Marks3=0;
        Avg=0;
    }

    void GetStudentInfo() {
        cout<<"Enter Name of the student: ";
        cin>>Name;

        cout<<"Enter Roll Number: ";
        cin>>RollNumber;

        cout<<"Enter Marks of Subject-1: ";
        cin>>Marks1;

        cout<<"Enter Marks of Subject-2: ";
        cin>>Marks2;

        cout<<"Enter Marks of Subject-3: ";
        cin>>Marks3;

        Avg = CalculateAvg();
    }

    void Display() {
        cout << "\nRoll No: " << RollNumber << endl;
        cout << "Name: " << Name << endl;
        cout << "Marks: " << Marks1 << ", " << Marks2 << ", " << Marks3 << endl;
        cout << "Average: " << Avg << endl;
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
        s.Display();
    }

    cout << "24CE014 JAYRAJSINH BHATTI";
    
    return 0;
}