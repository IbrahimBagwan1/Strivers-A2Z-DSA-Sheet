#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        return (s + s).find(goal) != string::npos;
    }
};

int main() {
    Solution sol;

    // Test 1: your failing case -> should be true
    string s1 = "defdefdefabcabc";
    string g1 = "defdefabcabcdef";
    cout << "s1: " << s1 << "\n"
         << "g1: " << g1 << "\n"
         << "Rotations? " << (sol.rotateString(s1, g1) ? "true" : "false") << "\n\n";

    // Test 2: negative case -> should be false
    string s2 = "abcde";
    string g2 = "abced";
    cout << "s2: " << s2 << "\n"
         << "g2: " << g2 << "\n"
         << "Rotations? " << (sol.rotateString(s2, g2) ? "true" : "false") << "\n";

    return 0;
}
