#include<iostream>
using namespace std;

class Complex {
private:
    float Real, Imag;

public:
    void setData(float r, float i) {
        this->Real = r;
        this->Imag = i;
    }

    Complex operator+(Complex &other) {
        Complex result;
        result.Real = this->Real + other.Real;
        result.Imag = this->Imag + other.Imag;
        return result;
    }

    Complex operator-(Complex &other) {
        Complex result;
        result.Real = this->Real - other.Real;
        result.Imag = this->Imag - other.Imag;
        return result;
    }

    Complex operator*(Complex &other) {
        Complex result;
        result.Real = (this->Real * other.Real) - (this->Imag * other.Imag);
        result.Imag = (this->Real * other.Imag) + (this->Imag * other.Real);
        return result;
    }

    void display() {
        cout << Real << " + i(" << Imag << ")";
    }
};

int main() {
    int choice = 1;
    float r, i;
    Complex a, b, c;

    do {
        cout << "\nEnter Complex Number A:" << endl;
        cout << "Real part: ";
        cin >> r;
        cout << "Imaginary part: ";
        cin >> i;
        a.setData(r, i);

        cout << "\nEnter Complex Number B:" << endl;
        cout << "Real part: ";
        cin >> r;
        cout << "Imaginary part: ";
        cin >> i;
        b.setData(r, i);

        cout << "\nResults:";

        c = a + b;
        cout << "\nA + B = ";
        c.display();

        c = a - b;
        cout << "\nA - B = ";
        c.display();

        c = a * b;
        cout << "\nA * B = ";
        c.display();

        cout << "\n\nDo you want to perform operations again? (1 = Yes, 0 = No): ";
        cin >> choice;
    } while (choice == 1);

    cout << "\n24CE014 JAYRAJSINH BHATTI" << endl;
    return 0;
}
