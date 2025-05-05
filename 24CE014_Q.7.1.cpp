#include<iostream>
#include<map>
#include<sstream>
#include<string>
using namespace std;

class WordFrequency {
    map<string, int> word;
    public:
    void CountFreq(string str) {
        stringstream ss(str);
        string w;

        while (ss >> w)
        {
            word[w]++;
        }
        
    }
    void print() {
        for(const auto &w: word) {
            cout << w.first << " : " << w.second << endl;
        }
    }
};

int main()
{
    string Paragraph;
    cout<<"Enter paragraph: ";
    getline(cin, Paragraph);

    WordFrequency wf;
    wf.CountFreq(Paragraph);
    wf.print();

    cout<<"24CE014 Jayrajsinh Bhatti";
    return 0;
}