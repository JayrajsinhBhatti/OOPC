#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

class Shape {
    public:
    float radius;

    void getRadius() {
        cout<<"Enter Radius of circle: ";
        cin>>radius;
    }

};

class Circle: public Shape {
    float area;

    public:
    void CalculateArea() {
        area = M_PI*radius*radius;
    }

    void DisplayArea() {
        cout<<"Calculated Area: "<<area<<endl;
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