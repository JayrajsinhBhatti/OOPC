#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

class Shape {
    public:
    float Radius;

    void getRadius() {
        cout<<"Enter Radius of circle: ";
        cin>>Radius;
    }

};

class Circle: public Shape {
    float Area;

    public:
    void CalculateArea() {
        Area = M_PI*Radius*Radius;
    }

    void DisplayArea() {
        cout<<"Calculated Area: "<<Area<<endl;
    }
};

int main()
{
    vector<Circle> circle;
    Circle c;
    int choice;
    do
    {
        cout<<"Enter 1-Enter Radius, 2-Display All Cirlce Area, 0-EXIT";
        cin>>choice;

        switch (choice)
        {
        case 1:
            c.getRadius();
            c.CalculateArea();
            c.DisplayArea();
            circle.push_back(c);
            break;

        case 2:
            for(auto &c: circle) {
                c.DisplayArea();
            }
            break;

        default:
            break;
        }
    } while (choice!=0);

    cout<<"24CE014 JAYRAJSINH BHATTI";
    return 0;
}