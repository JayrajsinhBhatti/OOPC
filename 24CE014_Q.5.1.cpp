#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Calculator {
    int fint, sint;
    float ffloat, sfloat;

    public:
    void GetNumber(int ia, int ib) {
        ia = fint;
        ib = sint;
    }
    void GetNumber(float fa, float fb) {
        fa = ffloat;
        fb = sfloat;
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

    cout<<"Enter 1-int, 2-float";
    cin>>choice;
    if (choice==1)
    {
        cout<<"Enter first int number: ";
        cin>>ia;
        cout<<"Enter second int number: ";
        cin>>ib;

        c.GetNumber(ia, ib);
        c.Sum(ia, ib);
    } else if(choice==2){
        cout<<"Enter first float number: ";
        cin>>fa;
        cout<<"Enter second float number: ";
        cin>>fb;

        c.GetNumber(fa, fb);
        c.Sum(fa, fb);
    } else {
        cout<<"Invalid choice"<<endl;
    }

    return 0;
}