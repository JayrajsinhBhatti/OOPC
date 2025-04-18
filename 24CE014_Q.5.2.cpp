#include<iostream>
using namespace std;

class Complex {
    int RealPart, ImaginaryPart;

    public:
    void InputNums() {
        cout<<"Enter real part: ";
        cin>>RealPart;
        cout<<"Enter Imaginary part: ";
        cin>>ImaginaryPart;
    }
    void operator+(Complex &b) {
        Complex ans;
        ans.RealPart = RealPart+b.RealPart;
        ans.ImaginaryPart = ImaginaryPart+b.ImaginaryPart;
        cout<<RealPart << "+" <<ImaginaryPart<<"i + "<<b.RealPart<<"+ "<<b.ImaginaryPart<<"i = " <<ans.RealPart<<"+"<<ans.ImaginaryPart<<"i"; 
    }
};

int main()
{
    Complex a,b;
    a.InputNums();
    b.InputNums();
    a+b;

    return 0;
}