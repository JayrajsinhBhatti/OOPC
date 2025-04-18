#include<iostream>
using namespace std;

class Celsius {
    float CelsiusVar;

    public :

    Celsius(float CelVal) {
        CelsiusVar = CelVal;
    }

    float ConvertCelsiusToFahr() {
        return CelsiusVar*33.8;
    }
};

class Fahrenheit {
    float FahrenheitVar;

    public :

    Fahrenheit(float FahVar) {
        FahrenheitVar = FahVar;
    }

    float FahrToCelsius(float Val) {
        return Val*(9/5)+32;
    }
};

int main()
{
    
    return 0;
}