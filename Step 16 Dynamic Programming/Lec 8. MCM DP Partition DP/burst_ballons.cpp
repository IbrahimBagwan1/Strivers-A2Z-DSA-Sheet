#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solution class containing the corrected logic
class Solution {
public:
    int recursiveMaxCoins(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maxProfit = 0;

        for(int idx = i; idx <= j; idx++){
            int cost = nums[i-1] * nums[idx] * nums[j+1] + 
                       recursiveMaxCoins(nums, i, idx-1, dp) +
                       recursiveMaxCoins(nums, idx+1, j, dp);

            maxProfit = max(maxProfit, cost);
        }

        return dp[i][j] = maxProfit;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        int newSize = nums.size();
        vector<vector<int>> dp(newSize, vector<int>(newSize, -1));
        
        return recursiveMaxCoins(nums, 1, n, dp);
    }
};

int main() {
    Solution solver;

    // Test Case: Balloons with values [3, 1, 5, 8]
    vector<int> nums = {3, 1, 5, 8};

    int result = solver.maxCoins(nums);

    // Expected output for this case is 167
    cout << "The maximum coins you can collect: " << result << endl;

    return 0;
}