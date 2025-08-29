#include <bits/stdc++.h>
using namespace std;
// Also known as : Power Set
class Solution {
public:
    vector<string> helperGenerateString(int n, string s){
        vector<string> ans;
        if(n==0){
            ans.push_back(s);
            return ans;
        }

        // collect results from adding '0'
        vector<string> part1 = helperGenerateString(n-1, s+'0');
        ans.insert(ans.end(), part1.begin(), part1.end());

        // collect results from adding '1'
        
        vector<string> part2 = helperGenerateString(n-1, s+'1');
        ans.insert(ans.end(), part2.begin(), part2.end());


        return ans;
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;
        ans = helperGenerateString(n, "");
        return ans;
    }
};

int main() {
    Solution s;

    vector<int> testCases = {2, 3, 4, 5, 6}; // 5 hardcoded inputs

    for(int n : testCases){
        cout << "Binary strings of length " << n << ":\n";
        vector<string> res = s.generateBinaryStrings(n);
        for(auto &str : res){
            cout << str << " ";
        }
        cout << "\n\n";
    }

    return 0;
}
