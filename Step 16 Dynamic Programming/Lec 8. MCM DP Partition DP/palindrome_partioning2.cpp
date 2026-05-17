#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    // i represents our current starting position in the string
    int recursiveMinCut(const string& s, int i, int n, vector<int>& dp) {
        // Base Case: If we reached the end of the string, no more cuts are needed
        if (i == n) return 0;

        // If the remaining substring from i to the end is already a palindrome,
        // we need 0 cuts for this entire remaining piece.
        if (isPalindrome(s, i, n - 1)) return 0;

        // Return cached result if already calculated
        if (dp[i] != -1) return dp[i];

        int minCuts = INT_MAX;

        // Try to place a cut at every position 'k' from i to the end
        for (int k = i; k < n; k++) {
            
            // If the left part s[i...k] is a palindrome, we can cut right after 'k'
            if (isPalindrome(s, i, k)) {
                
                // Cost = 1 (for this cut) + minimum cuts needed for the remaining right part
                int cost = 1 + recursiveMinCut(s, k + 1, n, dp);
                
                minCuts = min(minCuts, cost);
            }
        }

        return dp[i] = minCuts;
    }

    int minCut(string s) {
        int n = s.size();
        if (n <= 1) return 0;

        // 1D DP table tracking the minimum cuts needed from index i to the end
        vector<int> dp(n, -1);
        
        return recursiveMinCut(s, 0, n, dp);
    }
};

int main() {
    Solution solver;

    // Test Case: "aab"
    // The string can be partitioned as ["aa", "b"] with 1 cut.
    string s = "aab";

    int result = solver.minCut(s);

    cout << "String: \"" << s << "\"" << endl;
    cout << "Minimum cuts needed: " << result << endl;

    return 0;
}