#include<iostream>
#include<vector>
using namespace std;

class SumAlgorithms {
    public:
    int SumRecursive(int arr[], int n) {
        if(n == 0) return 0;
        else return arr[n-1] + SumRecursive(arr, n-1);
    }

    int SumIterative(int arr[], int n) {
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
        }
        return sum;
    }
};

int main()
{
    int n;
    SumAlgorithms sa;

    cout<<"Enter array size: ";
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        int number;
        cout<<"Enter number-"<<i<<": ";
        cin>>number;
        arr[i] = number;
    }

    int Recursive = sa.SumRecursive(arr, n);
    int Iterative = sa.SumIterative(arr, n);
    cout<<Recursive<<endl;
    cout<<Iterative<<endl;

    return 0;
}