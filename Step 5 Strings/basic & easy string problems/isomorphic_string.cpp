#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        int mapS[256] = {0};
        int mapT[256] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (mapS[s[i]] != mapT[t[i]])
                return false;
            mapS[s[i]] = i + 1;
            mapT[t[i]] = i + 1;
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Hardcoded Input 1
    string s1 = "egg", t1 = "add";
    cout << "Input 1: s = " << s1 << ", t = " << t1 << endl;
    cout << "Isomorphic? " << (sol.isIsomorphic(s1, t1) ? "true" : "false") << endl << endl;

    // Hardcoded Input 2
    string s2 = "foo", t2 = "bar";
    cout << "Input 2: s = " << s2 << ", t = " << t2 << endl;
    cout << "Isomorphic? " << (sol.isIsomorphic(s2, t2) ? "true" : "false") << endl;

    return 0;
}
