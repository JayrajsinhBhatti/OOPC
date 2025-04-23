#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Point {
    float x,y;

    public:
    Point(float a = 0.0, float b = 0.0) {
        x = a;
        y = b;
    }

    Point operator+(Point &other) {
        return Point(x+other.x, y+other.y);
    }

    Point operator-(Point &other) {
        return Point(x-other.x, y-other.y);
    }

    bool operator==(Point &other) {
        if (x==other.x && y==other.y)
        {
            return true;
        } else {
            return false;
        }
    }

    void DisplayResult() {
        cout << "(" << x << ", " << y << ")"<<endl;
    }
};

int main()
{
    string OperationChoice;
    int choice;
    float x1,y1,x2,y2;
    do
    {
        cout<<"Enter 1 to perform operation, 0 to EXIT: ";
        cin>>choice;
        switch (choice)
        {
        case 1:

            cout<<"Enter x for first point: ";
            cin>>x1;
            cout<<"Enter y for first point: ";
            cin>>y1;
            cout<<"Enter x for second point: ";
            cin>>x2;
            cout<<"Enter y for second point: ";
            cin>>y2;
            


            cout<<"Enter operation choice (+ , -, ==): ";
            cin>>OperationChoice;

            if (OperationChoice=="+")
            {
                Point p1(x1, y1);
                Point p2(x2, y2);
                Point p3;
                p3 = p1 + p2;
                p3.DisplayResult();
                break;
            } else if (OperationChoice=="-")
            {
                Point p1(x1, y1);
                Point p2(x2, y2);
                Point p3;
                p3 = p1 - p2;
                p3.DisplayResult();
                break;
            }else if (OperationChoice=="==")
            {
                Point p1(x1, y1);
                Point p2(x2, y2);
                if (p1 == p2)
                {
                    cout<<"Points are equal"<<endl;
                } else {
                    cout<<"Points are not equal"<<endl;
                }
                break;
            }
             else {
                cout<<"Invalid input!"<<endl;
            }
        case 0:
            cout<<"Exitting..."<<endl;
        
        default:
            break;
        }
        
    } while (choice!=0);
    
    return 0;
}