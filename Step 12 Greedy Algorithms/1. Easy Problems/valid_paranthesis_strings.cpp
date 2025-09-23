#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int minRange = 0;
        int maxRange = 0;

        for (char c : s) {
            if (c == '(') {
                minRange++;
                maxRange++;
            } 
            else if (c == ')') {
                if (minRange > 0) minRange--;
                maxRange--;
            } 
            else { // '*'
                if (minRange > 0) minRange--; // treat as ')'
                maxRange++;                  // treat as '('
            }

            if (maxRange < 0) return false; // too many ')'
        }
        return (minRange == 0);
    }
};

int main() {
    Solution sol;

    vector<string> tests = {
        "(*))",   // true
        "(*()",   // true
        "(*)))",  // false
        "()",     // true
        "(*",     // true
        "(((******))", // true
        "(((*)",  // false
    };

    for (auto &s : tests) {
        cout << "String: " << s 
             << " -> " << (sol.checkValidString(s) ? "Valid" : "Invalid") 
             << endl;
    }

    return 0;
}
