#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n = s.length();
        int i = n - 1;

        // skip trailing spaces
        while (i >= 0 && s[i] == ' ') i--;

        while (i >= 0) {
            int end = i;

            // move left until space or start
            while (i >= 0 && s[i] != ' ') i--;

            ans += s.substr(i + 1, end - i);
            ans += ' ';

            // skip spaces
            while (i >= 0 && s[i] == ' ') i--;
        }

        // remove last extra space
        if (!ans.empty()) ans.pop_back();

        return ans;
    }
};

int main() {
    Solution sol;
    string s;
    getline(cin, s);  // input with spaces
    cout << sol.reverseWords(s) << endl;
    return 0;
}
