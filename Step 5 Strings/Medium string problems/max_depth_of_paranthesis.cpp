#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int n = s.length();
        int maxcount = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') count++;
            else if (s[i] == ')') count--;
            maxcount = max(count, maxcount);
        }
        return maxcount;
    }
};

int main() {
    Solution obj;

    string s1 = "(1+(2*3)+((8)/4))+1";   // input 1
    string s2 = "(1)+((2))+(((3)))";     // input 2

    cout << s1 << " -> " << obj.maxDepth(s1) << endl;
    cout << s2 << " -> " << obj.maxDepth(s2) << endl;

    return 0;
}
