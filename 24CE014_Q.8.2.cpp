#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

void CountWordFrequency(string& text) {
    map<string, int> wordCount;
    stringstream ss(text);
    string word;

    while (ss >> word) {
        ++wordCount[word];
    }

    cout << "\nWord Frequency:\n";
    for (auto it = wordCount.begin(); it != wordCount.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

int main() {
    string inputText;

    cout << "Enter a sentence:\n";
    getline(cin, inputText);

    CountWordFrequency(inputText);

    cout<<"\n24CE014 JAYRAJSINH BHATTI";
    return 0;
}
