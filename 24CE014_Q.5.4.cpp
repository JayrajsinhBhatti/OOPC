#include<iostream>
using namespace std;

class Celsius {
    float CelsiusVar;

public:
    Celsius(float CelVal) {
        CelsiusVar = CelVal;
    }

    float ConvertCelsiusToFahr() {
        return (CelsiusVar * 9/5) + 32;
    }
};

class Fahrenheit {
    float FahrenheitVar;

public:
    Fahrenheit(float FahVar) {
        FahrenheitVar = FahVar;
    }

    float FahrToCelsius() {
        return (FahrenheitVar - 32) * 5/9;
    }
};

int main() {
    float celsiusValue = 25;
    float fahrenheitValue = 77;

    Celsius c(celsiusValue);
    Fahrenheit f(fahrenheitValue);

    cout << celsiusValue << " Celsius is equal to " << c.ConvertCelsiusToFahr() << " Fahrenheit." << endl;
    cout << fahrenheitValue << " Fahrenheit is equal to " << f.FahrToCelsius() << " Celsius." << endl;

    return 0;
}
