#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helperGenerateString(int n, string s, int last, vector<string> &ans){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        helperGenerateString(n, s+'0', 0, ans);
        if(last == 0 ) helperGenerateString(n, s+'1', 1, ans);
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;
        helperGenerateString(n, "", 0, ans);
        return ans;
    }
};


int main() {
    Solution s;

    vector<int> testCases = {2, 3, 4, 5, 6}; 
    vector<string> res = s.generateBinaryStrings(3);
    for(auto &str : res){
        cout << str << " ";
    }
    cout << "\n\n";

    return 0;
}
