#include<iostream>
#include<vector>
using namespace std;

class Employee
{
    string Name;
    int Salary, Bonus, TotalSalary, DefaultBonus = 15000;
    string BonusChoice;

    public: 
    void EmployeeData() {
        cout<<"Enter Employee name: ";
        cin>>Name;
        cout<<"Enter Salary: ";
        cin>>Salary;

        cout<<"Employee have a customized BONUS?: (yes/no)";
        cin>>BonusChoice;
        if (BonusChoice == "yes")
        {
            cout<<"Enter Bonus: ";
            cin>>Bonus;
        } else {
            Bonus = DefaultBonus;
        }
        CountSalary();
    }

    inline void CountSalary() {
        TotalSalary = Salary + Bonus;
    }

    void ShowEmployeeData() const{
        cout << "Name: " << Name << ", Bonus: " << Bonus << ", Total: " << TotalSalary << endl;
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
    cout << "24CE014 JAYRAJSINH BHATTI";
    return 0;
}