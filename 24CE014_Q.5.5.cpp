#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

class Shape {
    public:
    virtual float Area() {

    }
};

class Rectangle: public Shape {
    float length, breadth, area;
    public:
    Rectangle(float l, float b) {
        length = l;
        breadth = b;
    }

    float Area() override {
        area = length*breadth;
        cout<<"Area of rectangle is: "<<area<<endl;
    }
};

class Circle: public Shape {
    float radius, area;

    public:
    Circle(float r) {
        radius = r;
    }

    float Area() override {
        area = M_PI * radius * radius;
        cout<<"Area of circle is: "<<area<<endl;
    }

};

int main()
{
    vector<Shape*> shapes;
    vector<float> area;
    int choice;
    string ShapeName;
    float Length, Breadth, Radius;
    Shape* s;
    do
    {
        cout<<"Enter 1 to enter Shape, 0 to EXIT: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter shape name: ";
            cin>>ShapeName;

            if (ShapeName=="Rectangle")
            {
                cout<<"Enter length: ";
                cin>>Length;
                cout<<"Enter breadth: ";
                cin>>Breadth;
                s = new Rectangle(Length, Breadth);
                s->Area();
                shapes.push_back(s);
            } else if (ShapeName=="Circle")
            {
                cout<<"Enter Radius: ";
                cin>>Radius;
                s = new Circle(Radius);
                s->Area();
                shapes.push_back(s);
            }
            break;
        case 0:
            cout<<"Exitting..."<<endl;
        default:
            break;
        }
    } while (choice);

    for(int i=0;i<shapes.size();++i)
    {
        float a = shapes[i]->Area();
        area.push_back(a);
    }
    cout<<"end";
    
    cout<<"24CE014 Jayrajsinh Bhatti";
    return 0;
}