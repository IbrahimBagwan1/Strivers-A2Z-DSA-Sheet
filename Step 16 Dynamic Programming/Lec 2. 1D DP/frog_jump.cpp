#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Memoization Helper
    int solve(int idx, vector<int>& heights, vector<int>& dp) {
        // Base Case: At the first step, cost is 0
        if (idx == 0) return 0;
        
        // Return stored result if already calculated
        if (dp[idx] != -1) return dp[idx];

        // Choice 1: Jump from the immediate previous step
        int jumpOne = solve(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);

        // Choice 2: Jump from two steps back
        int jumpTwo = 1e9; // Initialize with a large value
        if (idx > 1) {
            jumpTwo = solve(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);
        }

        // Store and return the minimum of both choices
        return dp[idx] = min(jumpOne, jumpTwo);
    }

    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return solve(n - 1, heights, dp);
    }
};

int main() {
    Solution sol;
    vector<int> heights = {10, 20, 30, 10};
    cout << "Min Energy (2 steps): " << sol.frogJump(heights) << endl; // Output: 20
    return 0;
}