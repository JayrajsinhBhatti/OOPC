#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

class WordFrequencyCounter {
public:
    void countFrequency(const string& text) {
        map<string, int> wordCount;
        stringstream ss(text);
        string word;

        while (ss >> word) {
            ++wordCount[word];
        }

        cout << "\nWord Frequency:\n";
        for (const auto& pair : wordCount) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

int main() {
    string inputText;
    WordFrequencyCounter counter;

    cout << "Enter a sentence:\n";
    getline(cin, inputText);

    counter.countFrequency(inputText);

    cout << "\n24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}
