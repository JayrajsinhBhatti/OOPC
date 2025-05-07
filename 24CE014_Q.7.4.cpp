#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


ostream& tab(ostream& os) {
    return os << setw(15) << left;
}

int main() {
    ifstream file("Stu.txt");

    if (!file) {
        cout << "Error: Could not open file.\n";
        return 1;
    }

    char Name[50];
    int Marks;
    char Grade;


    cout<<tab<<"Name"<<tab<<"Marks"<<tab<<"Grade"<<endl;

  
    while (file >> Name >> Marks >> Grade) {
        cout << tab << Name << tab << Marks << tab << Grade << endl;
    }

    file.close();
    cout << "\n24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}