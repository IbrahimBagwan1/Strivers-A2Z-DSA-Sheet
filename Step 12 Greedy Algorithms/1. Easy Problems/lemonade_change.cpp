#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        int n = bills.size();

        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                fives++;
            } 
            else if (bills[i] == 10) {
                if (fives > 0) {
                    fives--;
                    tens++;
                } else {
                    return false;
                }
            } 
            else { // bill = 20
                if (fives > 0 && tens > 0) {
                    fives--;
                    tens--;
                } else if (fives >= 3) {
                    fives -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> bills1 = {5, 5, 5, 10, 20};
    cout << "Example 1: " << (sol.lemonadeChange(bills1) ? "true" : "false") << endl;
    // Expected: true

    // Example 2
    vector<int> bills2 = {5, 5, 10, 10, 20};
    cout << "Example 2: " << (sol.lemonadeChange(bills2) ? "true" : "false") << endl;
    // Expected: false

    // Example 3
    vector<int> bills3 = {5, 5, 5, 5, 10, 5, 10, 10, 10, 20};
    cout << "Example 3: " << (sol.lemonadeChange(bills3) ? "true" : "false") << endl;
    // Expected: false

    return 0;
}
