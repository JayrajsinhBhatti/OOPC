#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SuperDigit {
    string res = "";

public:
    long long GenerateNum(int Number, int k) {
        for (int i = 0; i < k; i++) {
            res += to_string(Number);
        }
        long long conc_num = stoll(res);
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
    int res = sd.GetSuperNum(GenNum);
    cout << "Result: " << res << endl;

    return 0;
}
