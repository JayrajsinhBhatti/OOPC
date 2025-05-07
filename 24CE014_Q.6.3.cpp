#include <iostream>
using namespace std;

void Merge_sorted_arrays(int* arr1, int Size1, int* arr2, int Size2) {
  
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
    for (int i = 0; i < Size1 + Size2; ++i) {
        cout << mergedArr[i] << " ";
    }
    cout << endl;
    delete[] mergedArr;
}

int main() {

    int Size1, Size2;

    cout << "Enter size of first sorted array: ";
    cin >> Size1;

    int* arr1 = new int[Size1];

    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < Size1; ++i) {
        cin >> arr1[i];
    }

    cout << "Enter size of second sorted array: ";
    cin >> Size2;
    int* arr2 = new int[Size2];
    cout << "Enter elements of second sorted array: ";

    for (int i = 0; i < Size2; ++i) {
        cin >> arr2[i];
    }

    Merge_sorted_arrays(arr1, Size1, arr2, Size2);

    delete[] arr1;
    delete[] arr2;
    cout << "\n24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}