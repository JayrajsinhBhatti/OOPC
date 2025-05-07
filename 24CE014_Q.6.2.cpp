#include <iostream>
using namespace std;

class Coordinates {
private:
    int x, y;

public:
    Coordinates(int XVal = 0, int YVal = 0) {
        x = XVal;
        y = YVal;
    }

    Coordinates* Move(int dx, int dy) {
        x += dx;
        y += dy;
        return this;
    }

    void Display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    int x, y;
    cout << "Enter initial coordinates (x y): ";
    cin >> x >> y;

    Coordinates* point = new Coordinates(x, y);
    cout << "\nInitial Position: ";
    point->Display();

    int moves;
    cout << "\nEnter number of movements: ";
    cin >> moves;

    for (int i = 1; i <= moves; ++i) {
        int dx, dy;
        cout << "Move " << i << " - Enter dx and dy: ";
        cin >> dx >> dy;
        point->Move(dx, dy);
    }

    cout << "\nFinal Position: ";
    point->Display();

    delete point;
    cout << "\n24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}
