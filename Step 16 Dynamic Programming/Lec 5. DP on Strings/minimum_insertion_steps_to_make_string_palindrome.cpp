#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    int recurPalinSubseq(string &s, int i, int j, vector<vector<int>> &dp){
        // base case
        if(i>j){
            return 0;
        }
        if(i==j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]){
            return dp[i][j] = 2 + recurPalinSubseq(s, i+1, j-1, dp);
        }

        return dp[i][j] = max(recurPalinSubseq(s, i+1, j, dp), recurPalinSubseq(s, i, j-1, dp));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return recurPalinSubseq(s, 0, n-1, dp);    
    }

    int minInsertions(string s) {
        int n =s.size();

        int longestPalSeq = longestPalindromeSubseq(s);

        return n-longestPalSeq;
    }
};


int main() {
    Solution sol;

    // Test Case 1
    string s1 = "bbbab";
    cout << "String: " << s1 << "\nMin Operation to Make Palindrome: " << sol.minInsertions(s1) << endl; 


    // Test Case 2
    string s2 = "cbbd";
    cout << "\nString: " << s2 << "\nMin Operation to Make Palindrome: " << sol.minInsertions(s2) << endl; 


    // Test Case 3
    string s3 = "character";
    cout << "\nString: " << s3 << "\nMin Operation to Make Palindrome " << sol.minInsertions(s3) << endl; 


    return 0;
}