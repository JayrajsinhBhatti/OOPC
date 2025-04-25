#include<iostream>
#include<vector>
#include<string>
using namespace std;

class WordFrequency {
    public:
    void CountFreq(string str) {

    }
};

int main()
{
    vector<string> words;
    vector<int> count;
    string str;

    cout<<"Enter paragraph: ";
    cin>>str;
    string *strptr = str;

    for(int i=0; i<str.length(); i++) {
        
    }
    WordFrequency wf;
    wf.CountFreq(str);
    return 0;
}