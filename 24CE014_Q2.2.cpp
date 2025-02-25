#include<iostream>
using namespace std;

class Student {
    short int roll_number;
    string name;
    float marks1, marks2, marks3, avg;

    public:
    void get(short int id=0, string Studentname=NULL, float m1=0,float m2=0,float m3=0) {
        roll_number = id;
        name = Studentname;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;

        avg = (m1+m2+m3)/3;
    }

    void display() {
        cout<<"Name: "<<name<<endl;
        cout<<"Roll number: "<<roll_number<<endl;
        cout<<"Your average marks is: "<<avg<<endl;
    }
};

int main()
{
    short int roll_number;
    string name;
    float marks1, marks2, marks3, avg;

    Student s1;
    
    for(int i=0; i<5; i++) {

    cout<<"Enter ID: ";
    cin>>roll_number;

    cout<<"Name: ";
    cin>>name;

    cout<<"Marks-1: ";
    cin>>marks1;
    cout<<"Marks-2: ";
    cin>>marks2;
    cout<<"Marks-3: ";
    cin>>marks3;

    s1.get(roll_number, name, marks1, marks2, marks3);
    s1.display();

    }
}