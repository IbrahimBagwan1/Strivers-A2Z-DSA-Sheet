#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool existsWord(string word, vector<string>& wordDict){
        for(auto &words: wordDict){
            if(words == word){
                return true;
            }
        }
        return false;
    }

    bool helperWord(string s, vector<string> &wordDict, int n, int idx, vector<int> &dp){
        if(idx==n){
            return true;
        }

        if(dp[idx]!= -1) return dp[idx];

        for(int i=1; idx+i<=n; i++){
            string findWord = s.substr(idx, i);
            if(existsWord(findWord, wordDict)){
                if(helperWord(s, wordDict, n, idx+i, dp)){
                    return dp[idx]= true;
                }
            }
        }
        return dp[idx]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return helperWord(s, wordDict, n,0, dp);
    }
};

int main() {
    Solution sol;

    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    if(sol.wordBreak(s, wordDict)){
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    // Another test
    string s2 = "applepenapple";
    vector<string> dict2 = {"apple", "pen"};

    cout << (sol.wordBreak(s2, dict2) ? "true\n" : "false\n");

    // Another test where it's impossible
    string s3 = "catsandog";
    vector<string> dict3 = {"cats","dog","sand","and","cat"};

    cout << (sol.wordBreak(s3, dict3) ? "true\n" : "false\n");

    return 0;
}
