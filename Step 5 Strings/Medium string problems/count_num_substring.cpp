#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubstrings(string s) {
        long long n = s.length();
        return n * (n + 1) / 2;   // formula for total substrings
    }
};

int main() {
    Solution obj;

    string s1 = "abc";   // input 1
    string s2 = "abcd";  // input 2

    cout << s1 << " -> " << obj.countSubstrings(s1) << endl;
    cout << s2 << " -> " << obj.countSubstrings(s2) << endl;

    return 0;
}
