#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class DataCollection
{
    vector<T> data;

    public:
    void InputData(int n) {
        for(int i=0;i<n;i++)
        {
            T temp;
            cout<<"Enter "<<i<<"th value: ";
            cin>>temp;
            data.push_back(temp);
        }
        cout<<endl;
    }

    void DisplayData() {
        cout<<"Displaying data: ";
        for(T temp : data) {
            cout<<temp<<" ";
        }
        cout<<endl;
    }

    void GetMax(int n) {
        int max = data[0];
        for(int i=1;i<n;i++)
        {
            if (data[i] > max)
            {
                max = data[i];
            }
        }
        cout<<"Maximum value: "<<max<<endl;
    }

    void ReverseCollection(int n) {
        int st = 0, end = data.size() - 1;
        cout<<"Reversing collection..."<<endl;
        while (st < end)
        {
            T temp = data[st];
            data[st] = data[end];
            data[end] = temp;

            st++;
            end--;
        }

    }
};

int main()
{
    int DataType, TotalNumber;

    do
    {
        cout<<"Enter the Data Type (1-INT :: 2-FLOAT :: 3-CHAR :: 0-EXIT): ";
        cin>>DataType;

        if (DataType == 0)
        {
            cout<<"Exitting...";
            break;
        }


        cout<<"Enter Total size of input: ";
        cin>>TotalNumber;

        switch (DataType)
        {
        case 1:
            {
                DataCollection<int> dci;
                dci.InputData(TotalNumber);
                dci.DisplayData();
                dci.GetMax(TotalNumber);
                dci.ReverseCollection(TotalNumber);
                dci.DisplayData();
            break;
            }


        case 2:
            {
                DataCollection<float> dcf;
                dcf.InputData(TotalNumber);
                dcf.DisplayData();
                dcf.GetMax(TotalNumber);
                dcf.ReverseCollection(TotalNumber);
                dcf.DisplayData();
            break;
            }

        case 3:
            {
                DataCollection<char> dcc;
                dcc.InputData(TotalNumber);
                dcc.DisplayData();
                dcc.GetMax(TotalNumber);
                dcc.ReverseCollection(TotalNumber);
                dcc.DisplayData();
            break;
            }

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (DataType != 0);

    cout<<"24CE014 JAYRAJSINH BHATTI";
    return 0;
}
