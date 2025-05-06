#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    getline(cin, filename);

    ifstream file(filename);
    if (!file) {
        cerr << "File could not be opened.\n";
        return 1;
    }

    vector<string> lines;
    string line;
    int charCount = 0, wordCount = 0;

    while (getline(file, line)) {
        lines.push_back(line);
        charCount += line.length() + 1;

        stringstream ss(line);
        string word;
        while (ss >> word)
            ++wordCount;
    }

    file.close();

    cout << "\n--- File Statistics ---\n";
    cout << "Total Lines    : " << lines.size() << endl;
    cout << "Total Words    : " << wordCount << endl;
    cout << "Total Characters (with spaces and punctuation): " << charCount << endl;

    return 0;
}
