#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SuperDigit {
    string Res = "";

public:
    long long GenerateNum(int Number, int k) {
        for (int i = 0; i < k; i++) {
            Res += to_string(Number);
        }
        long long conc_num = stoll(Res);
        return conc_num;
    }

    int GetSuperNum(long long num) {
        if (num < 10) {
            return num;
        }

        long long sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return GetSuperNum(sum);
    }
};

int main() {
    int Number, k;

    cout << "Enter the number: ";
    cin >> Number;
    cout << "Enter the number of concatenations: ";
    cin >> k;

    SuperDigit sd;
    long long GenNum = sd.GenerateNum(Number, k);
    int Res = sd.GetSuperNum(GenNum);
    cout << "Result: " << Res << endl;

    cout << "24CE014 JAYRAJSINH BHATTI";
    return 0;
}
