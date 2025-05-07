#include <iostream>
#include <sstream>

using namespace std;

class LoanEvaluator {
    double LoanAmount = 0;
    double AnnualIncome = 0;

    bool isValidNumber(const string& str) {
        stringstream ss(str);
        double num;
        ss >> num;
        return !ss.fail() && ss.eof();
    }

public:
    void inputDetails() {
        string input;

        do {
            cout << "Enter the total loan amount you want to apply for: ";
            getline(cin, input);

            if (!isValidNumber(input)) {
                cout << "Error: Please enter a valid numerical value for loan amount.\n";
                continue;
            }
            LoanAmount = stod(input);

            cout << "Enter your annual income: ";
            getline(cin, input);

            if (!isValidNumber(input)) {
                cout << "Error: Please enter a valid numerical value for annual income.\n";
                continue;
            }
            AnnualIncome = stod(input);

            if (LoanAmount <= 0 || AnnualIncome <= 0) {
                cout << "Error: Loan amount and annual income must both be greater than 0.\nPlease try again.\n\n";
            }

        } while (LoanAmount <= 0 || AnnualIncome <= 0);
    }

    void evaluate() const {
        double ratio = LoanAmount / AnnualIncome;
        cout << "Your Loan-to-Income Ratio is: " << ratio << endl;
    }
};

int main() {
    LoanEvaluator evaluator;
    evaluator.inputDetails();
    evaluator.evaluate();

    cout << "\n24CE014 JAYRAJSINH BHATTI\n";
    return 0;
}
