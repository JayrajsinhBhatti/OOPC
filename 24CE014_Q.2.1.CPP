#include<iostream>
using namespace std;

class Rectangle {
    float Length, Breadth;
    float NewLength, NewBreadth;

    public:
    void Disp() {
        cout<<"Enter Length:: ";
        cin>>Length;
        cout<<"Enter Breadth:: ";
        cin>>Breadth;
    }
    void Result() {
        cout<<"Area is: "<<Length*Breadth<<endl;
        cout<<"Perimeter is: "<<2*(Length+Breadth)<<endl;
    }

    void Update() {
        cout<<"Enter new Length:: ";
        cin>>NewLength;

        cout<<"Enter new Breadth:: ";
        cin>>NewBreadth;

        cout<<"Old area: "<<Length*Breadth<<endl;
        cout<<"Old perimeter: "<<2*(Length+Breadth)<<endl;

        Length = NewLength;
        Breadth = NewBreadth;

        cout<<"Updated Length is: "<<Length<<endl;
        cout<<"Updated Breadth is: "<<Breadth<<endl;
    }

    //void UpdatedArea() {
        // cout<<"Area is: "<<NewLength*NewBreadth<<endl;
        // cout<<"Area is: "<<2*(NewLength+NewBreadth)<<endl;
    //    cout<<"Area is: "<<Length*Breadth<<endl;
    //   cout<<"Perimeter is: "<<2*(Length+Breadth)<<endl;
    //}
};
int main()
{
    Rectangle r;
    int choice;
    do{
        cout<<"Press 1 to enter,2 to Update, 0 to exit :: ";
        cin>>choice;

        if (choice==1)
        {
            r.Disp();
            r.Result();

        }
        else if (choice==2)
        {
            r.Update();
            r.Result();
        }
        else if (choice==0)
        {
            cout<<"Exitting...";
            return 0;
        }
        else {
            cout<<"Incorrect input!"<<endl;
        }
    } while(choice!=0);

    cout << "24CE014 JAYRAJSINH BHATTI";
}
