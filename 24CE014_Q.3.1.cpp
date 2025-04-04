#include<iostream>
#include<vector>
using namespace std;

class Employee
{
    string Name;
    int salary, bonus, TotalSalary, DefaultBonus = 15000;
    string BonusChoice;

    public: 
    void EmployeeData() {
        cout<<"Enter Employee name: ";
        cin>>Name;
        cout<<"Enter Salary: ";
        cin>>salary;

        cout<<"Employee have a customized BONUS?: (yes/no)";
        cin>>BonusChoice;
        if (BonusChoice == "yes")
        {
            cout<<"Enter Bonus: ";
            cin>>bonus;
        } else {
            bonus = DefaultBonus;
        }
        CountSalary();
    }

    inline void CountSalary() {
        TotalSalary = salary + bonus;
    }

    void ShowEmployeeData() const{
        cout << "Name: " << Name << ", Salary: " << TotalSalary << ", Bonus: " << bonus << ", Total: " << TotalSalary << endl;
    }
};

int main()
{
    vector<Employee> emp;
    string EmployeeChoice;
    do
    {
        Employee e;
        e.EmployeeData();
        emp.push_back(e);

        cout<<"Do you want to add another Employee?: (yes/no)";
        cin>>EmployeeChoice;
    } while (EmployeeChoice == "yes");

    cout<<" -- Displaying Employee Data -- "<<endl;
    for(const auto& e: emp)
    {
        e.ShowEmployeeData();
    }
    
    return 0;
}