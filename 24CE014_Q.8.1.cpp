#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SequenceReverser {
    vector<int> data;

public:
    void inputData() {
        int n, value;
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter " << n << " integers:\n";
        for (int i = 0; i < n; i++) {
            cin >> value;
            data.push_back(value);
        }
    }

    void displaySequence(const vector<int>& sequence) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    }

    void reverseUsingStdFunction(vector<int>& sequence) {
        reverse(sequence.begin(), sequence.end());
    }

    void reverseUsingIterators(vector<int>& sequence) {
        auto left = sequence.begin();
        auto right = sequence.end() - 1;
        while (left < right) {
            iter_swap(left, right);
            ++left;
            --right;
        }
    }

    void process() {
        vector<int> dataCopy = data;

        cout << "\nOriginal sequence: ";
        displaySequence(data);

        reverseUsingStdFunction(data);
        cout << "Reversed using std::reverse: ";
        displaySequence(data);

        reverseUsingIterators(dataCopy);
        cout << "Reversed using manual iterators: ";
        displaySequence(dataCopy);
    }
};

int main() {
    SequenceReverser reverser;
    reverser.inputData();
    reverser.process();

    cout << "\n24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}
