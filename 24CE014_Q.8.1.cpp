#include <iostream>
#include <vector>
#include <algorithm> // For reverse
using namespace std;

void ReverseUsingStdFunction(vector<int>& sequence) {
    reverse(sequence.begin(), sequence.end());
}

void ReverseUsingIterators(vector<int>& sequence) {
    auto left = sequence.begin();
    auto right = sequence.end() - 1;

    while (left < right) {
        iter_swap(left, right); 
        ++left;
        --right;
    }
}

void displaySequence(const vector<int>& sequence) {
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data;
    int n, Value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> Value;
        data.push_back(Value);
    }

    vector<int> dataCopy = data;

    cout << "\nOriginal sequence: ";
    displaySequence(data);

    ReverseUsingStdFunction(data);
    cout << "Reversed using std::reverse: ";
    displaySequence(data);

    ReverseUsingIterators(dataCopy);
    cout << "Reversed using manual iterators: ";
    displaySequence(dataCopy);

    cout << "\n24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}
