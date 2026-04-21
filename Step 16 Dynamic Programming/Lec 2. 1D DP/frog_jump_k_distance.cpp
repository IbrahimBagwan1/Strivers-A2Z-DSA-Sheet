#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Memoization Helper
    int solveK(int idx, vector<int>& heights, int k, vector<int>& dp) {
        // Base Case
        if (idx == 0) return 0;
        
        // Return stored result
        if (dp[idx] != -1) return dp[idx];

        int minEnergy = 1e9;

        // Try all jumps from 1 up to k
        for (int j = 1; j <= k; j++) {
            if (idx - j >= 0) {
                int jump = solveK(idx - j, heights, k, dp) + abs(heights[idx] - heights[idx - j]);
                minEnergy = min(minEnergy, jump);
            }
        }

        return dp[idx] = minEnergy;
    }

    int frogJumpK(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return solveK(n - 1, heights, k, dp);
    }
};

int main() {
    Solution sol;
    vector<int> heights = {10, 30, 40, 50, 20};
    int k = 3;
    cout << "Min Energy (K steps): " << sol.frogJumpK(heights, k) << endl; // Output: 30
    return 0;
}