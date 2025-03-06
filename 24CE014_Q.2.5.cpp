#include<iostream>
#include<math.h>
using namespace std;

class LoanDetails
{
    string name;
    float TotalLoanAmount, LoanTenure, InterestRate;

    public:

    void AddDetails()
    {
        cout<<"Enter Name of Loan appplicant: ";
        cin>>name;
        cout<<"Enter Total Loan Amount: ";
        cin>>TotalLoanAmount;
        cout<<"Enter Loan Tenure(*in months): ";
        cin>>LoanTenure;
        cout<<"Enter Loan Interest: ";
        cin>>InterestRate;

        InterestRate= InterestRate/(12)/(100);

        cout<<"Entry is completed!"<<endl;
        CalculateEMi(TotalLoanAmount, LoanTenure, InterestRate);
    }

    void CalculateEMi(float TotalLoanAmount,float LoanTenure,float InterestRate)
    {
        float EMI =  (TotalLoanAmount*InterestRate*(float)pow(1+InterestRate,LoanTenure)) / (float)((pow(1+InterestRate,LoanTenure))-1);
        DisplayDetails(EMI);
    }

    void DisplayDetails(float EMI)
    {
        cout<<"Name of Applicant: "<<name<< " || " << "Total Loan Amount: "<<TotalLoanAmount << " || " << "Loan Tenure(in months): "<<LoanTenure << " || "<<"Interest Rate(per annum): "<<InterestRate*12*100<<"%" <<" || " <<"EMI: "<<EMI<<endl<<endl;
    }
};

int main()
{
    int choice;
    LoanDetails l;

    do
    {
        cout<<"Enter 1 to Enter details, 0 to EXIT::";
        cin>>choice;

        switch (choice)
        {
        case 1:
            l.AddDetails();
            break;
        case 0:
            cout<<"Exitting from System..."<<endl;
            break;
        default:
            cout<<"Incorrect Input! "<<endl;
            break;
        }

    } while (choice!=0);
    cout<<"24CE014";

    return 0;
}
