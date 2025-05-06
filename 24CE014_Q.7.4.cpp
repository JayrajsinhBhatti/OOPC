#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

void ShowReport(const std::string& FileName) {
    std::ifstream File(FileName);
    if (!File) {
        std::cout << "Error: Cannot open file.\n";
        return;
    }

    std::string Name;
    int Marks;
    char Grade;

    std::cout << "\n=== Student Report ===\n";
    std::cout << std::left << std::setw(20) << "Name"
              << std::setw(10) << "Marks"
              << std::setw(10) << "Grade" << "\n";
    std::cout << "-------------------------------\n";

    while (std::getline(File, Name, ',')) {
        File >> Marks >> Grade;
        File.ignore();
        std::cout << std::left << std::setw(20) << Name
                  << std::setw(10) << Marks
                  << std::setw(10) << Grade << "\n";
    }

    File.close();
}

int main() {
    std::string FileName = "students.txt";
    ShowReport(FileName);
    return 0;
}
