#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, Num;
    set<int> uniqueIDs;

    cout << "Enter Number of transaction IDs: ";
    cin >> n;

    cout << "Enter the transaction IDs:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> Num;
        uniqueIDs.insert(Num);  // Automatically removes duplicates
    }

    cout << "Unique transaction IDs in sorted order:" << endl;
    for (set<int>::iterator it = uniqueIDs.begin(); it != uniqueIDs.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout<<"24CE014 Jayrajsinh Bhatti";
    return 0;
}