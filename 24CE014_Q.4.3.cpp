#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

class Fuel {
    protected:
    string FuelType;

    public:
    Fuel(string f) {
        FuelType = f;
    }
};

class Brand: public Fuel {
    protected:
    string CarBrand;

    public:
    Brand(string f, string name) : Fuel(f){
        CarBrand = name;
    }
};

class Car: public Brand {
    public:
    Car(string f, string name) : Brand(f, name) {}

    void DisplayCar() {
        cout<<"Fuel Type: "<<FuelType<<endl;
        cout<<"Brand name: "<<CarBrand<<endl;
        cout<<"-------------------------------"<<endl;
    }
};

int main()
{
    vector<Car> car;
    int choice;
    string fuel, name;

    do
    {
        cout<<"Enter 1-Enter Car Details , 2-Display all Cars, 0-EXIT: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
        {
            cout<<"Enter Fuel type: ";
            cin>> fuel;
            cout<<"Enter Brand name: ";
            cin>> name;
            Car c(fuel, name);

            car.push_back(c);
            break;
        }

        case 2:
            for(auto &c: car) {
                c.DisplayCar();
            }
            break;

        case 0:
            cout<<"Exitting...";
            break;

        default:
            break;
        }
    } while (choice!=0);

    cout<<"24CE014 JAYRAJSINH BHATTI";
    
    return 0;
}