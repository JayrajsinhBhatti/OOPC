#include<iostream>
using namespace std;

class Rectangle {
    float length, breadth;
    float newlength, newbreadth;

    public:
    void disp() {
        cout<<"Enter length:: ";
        cin>>length;
        cout<<"Enter breadth:: ";
        cin>>breadth;
    }
    void result() {
        cout<<"Area is: "<<length*breadth<<endl;
        cout<<"Perimeter is: "<<2*(length+breadth)<<endl;
    }

    void update() {
        cout<<"Enter new length:: ";
        cin>>newlength;

        cout<<"Enter new breadth:: ";
        cin>>newbreadth;

        cout<<"Old area: "<<length*breadth<<endl;
        cout<<"Old perimeter: "<<2*(length+breadth)<<endl;

        length = newlength;
        breadth = newbreadth;

        cout<<"Updated length is: "<<length<<endl;
        cout<<"Updated breadth is: "<<breadth<<endl;
    }

    //void updatedArea() {
        // cout<<"Area is: "<<newlength*newbreadth<<endl;
        // cout<<"Area is: "<<2*(newlength+newbreadth)<<endl;
    //    cout<<"Area is: "<<length*breadth<<endl;
    //   cout<<"Perimeter is: "<<2*(length+breadth)<<endl;
    //}
};
int main()
{
    Rectangle r;
    int choice;
    do{
        cout<<"Press 1 to enter,2 to update, 0 to exit :: ";
        cin>>choice;

        if (choice==1)
        {
            r.disp();
            r.result();

        }
        else if (choice==2)
        {
            r.update();
            r.result();
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
}
