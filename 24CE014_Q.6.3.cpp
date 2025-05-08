#include <iostream>
using namespace std;

class ArrayMerger {
    int* arr1;
    int* arr2;
    int Size1;
    int Size2;

public:
    ArrayMerger(){
        arr1 = nullptr;
        arr2 = nullptr;
        Size1 = 0;
        Size2 = 0;
    }

    void inputArrays() {
        cout << "Enter size of first sorted array: ";
        cin >> Size1;
        arr1 = new int[Size1];
        cout << "Enter elements of first sorted array: ";
        for (int i = 0; i < Size1; i++) {
            cin >> arr1[i];
        }

        cout << "Enter size of second sorted array: ";
        cin >> Size2;
        arr2 = new int[Size2];
        cout << "Enter elements of second sorted array: ";
        for (int i = 0; i < Size2; i++) {
            cin >> arr2[i];
        }
    }

    void mergeAndDisplay() {
        int* mergedArr = new int[Size1 + Size2];
        int i = 0, j = 0, k = 0;

        while (i < Size1 && j < Size2) {
            if (arr1[i] < arr2[j]) {
                mergedArr[k++] = arr1[i++];
            } else {
                mergedArr[k++] = arr2[j++];
            }
        }

        while (i < Size1) {
            mergedArr[k++] = arr1[i++];
        }

        while (j < Size2) {
            mergedArr[k++] = arr2[j++];
        }

        cout << "Merged Sorted Array: ";
        for (int i = 0; i < Size1 + Size2; i++) {
            cout << mergedArr[i] << " ";
        }
        cout << endl;

        delete[] mergedArr;
    }

    ~ArrayMerger() {
        delete[] arr1;
        delete[] arr2;
    }
};

int main() {
    ArrayMerger merger;
    merger.inputArrays();
    merger.mergeAndDisplay();

    cout << "\n24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}
