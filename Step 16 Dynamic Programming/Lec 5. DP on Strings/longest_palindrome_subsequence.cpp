#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int recurPalinSubseq(string &s, int i, int j, vector<vector<int>> &dp) {
        // Base case: If pointers cross, no characters left
        if (i > j) return 0;
        
        // Base case: If pointers are on the same character, it's a 1-length palindrome
        if (i == j) return 1;

        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            // Both ends match, add 2 and move inward
            return dp[i][j] = 2 + recurPalinSubseq(s, i + 1, j - 1, dp);
        } else {
            // Ends don't match, try skipping either the left or the right character
            return dp[i][j] = max(recurPalinSubseq(s, i + 1, j, dp), 
                                  recurPalinSubseq(s, i, j - 1, dp));
        }
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        // Initialize DP table with -1
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return recurPalinSubseq(s, 0, n - 1, dp);
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "bbbab";
    cout << "String: " << s1 << "\nLPS Length: " << sol.longestPalindromeSubseq(s1) << endl; 
    // Expected: 4 ("bbbb")

    // Test Case 2
    string s2 = "cbbd";
    cout << "\nString: " << s2 << "\nLPS Length: " << sol.longestPalindromeSubseq(s2) << endl; 
    // Expected: 2 ("bb")

    // Test Case 3
    string s3 = "character";
    cout << "\nString: " << s3 << "\nLPS Length: " << sol.longestPalindromeSubseq(s3) << endl; 
    // Expected: 5 ("carac")

    return 0;
}