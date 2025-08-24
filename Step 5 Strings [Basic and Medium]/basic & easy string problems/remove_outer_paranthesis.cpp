#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int n = s.length();
        int sum = 0;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') sum++;
            else sum--;
            if (sum == 0) {
                ans += s.substr(idx + 1, i - idx - 1);
                idx = i + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    string result = sol.removeOuterParentheses(s);
    cout << "After removing outer parentheses: " << result << endl;

    return 0;
}
