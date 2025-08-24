#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        if(n == 0) return "";
        if(n == 1) return strs[0];

        int i = 0;
        while(i < strs[0].size() && i < strs[n-1].size() && strs[0][i] == strs[n-1][i]){
            i++;
        }
        return strs[0].substr(0, i);
    }
};

int main() {
    Solution sol;

    // Hardcoded Input 1
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Input 1: {flower, flow, flight}" << endl;
    cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs1) << endl << endl;

    // Hardcoded Input 2
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Input 2: {dog, racecar, car}" << endl;
    cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs2) << endl;

    return 0;
}
