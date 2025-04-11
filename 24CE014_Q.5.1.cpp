#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Calculator {
    public:
    void GetNumber(int ia, int ib) {
        cout<<"Enter first number: ";
        cin>>ia;
        cout<<"Enter second number: ";
        cin>>ib;
    }
    void GetNumber(float fa, float fb) {
        cout<<"Enter first number: ";
        cin>>fa;
        cout<<"Enter second number: ";
        cin>>fb;
    }
    void Sum(int ia, int ib) {
        cout<<ia+ib;
    }
    void Sum(float fa, float fb) {
        cout<<fa+fb;
    }
};

int main()
{
    int ia, ib, choice;
    float fa, fb;

    Calculator c;

    cout<<"Eneter 1-int, 2-float";
    cin>>choice;
    if (choice==1)
    {
        c.GetNumber(ia, ib);
        c.Sum(ia, ib);
    } else if(choice==2){
        c.GetNumber(fa, fb);
        c.Sum(fa, fb);
    } else {
        cout<<"Invalid choice"<<endl;
    }

    return 0;
}
