#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {  // check if odd
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main() {
    Solution sol;

    // Hardcoded inputs
    string num1 = "35420";
    string num2 = "4206";

    cout << "Input: " << num1 << " -> Largest odd number: " 
         << sol.largestOddNumber(num1) << endl;

    cout << "Input: " << num2 << " -> Largest odd number: " 
         << sol.largestOddNumber(num2) << endl;

    return 0;
}
