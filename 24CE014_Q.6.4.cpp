#include <iostream>
using namespace std;

class Base {
public:
  
    virtual ~Base() {
        cout << "Base class destructor\n";
    }

    virtual void show() {
        cout << "Base class behavior\n";
    }
};


class Derived : public Base {
public:
   
    Derived() {
        cout << "Derived class constructor\n";
    }

    ~Derived() {
        cout << "Derived class destructor\n";
    }

    void show() override {
        cout << "Derived class behavior\n";
    }
};

int main() {
   
    Base* obj = new Derived();

    obj->show();  
    delete obj;

    cout << "\n24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}