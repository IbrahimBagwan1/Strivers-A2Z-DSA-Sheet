#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int helperRob(vector<int> &nums, int n, vector<int> &dp){
        if(n<0) return 0;
        if(n==0) return nums[n];
        if(dp[n]!=-1) return dp[n];

        int pick = nums[n] + helperRob(nums, n-2, dp);
        int notPick = helperRob(nums, n-1, dp);

        return dp[n] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1, -1);
        // return helperRob(nums, n-1, dp);

        // tabulation
        // dp[0] = nums[0];
        // int neg = 0;

        // for(int i=1; i<n; i++){
        //     int pick;
        //     if(i-2 >= 0){
        //         pick = nums[i] + dp[i-2];
        //     }
        //     else{
        //         pick = nums[i] + neg;
        //     }
        //     int notPick = dp[i-1];
        //     dp[i] = max(pick , notPick);
        // }

        // return dp[n-1];

        // space optimization
        if (n == 0) return 0; // Added safety for empty input
        int prev =nums[0];
        int beforeprev = 0;

        for(int i=1; i<n; i++){
            int  pick = nums[i];
            if(i-2 >= 0){
                pick += beforeprev;
            }
            int notPick = prev;
            int result = max(pick , notPick);
            
            beforeprev = prev;
            prev = result;
        }
        return prev;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    vector<int> case1 = {1, 2, 3, 1};
    cout << "Test Case 1 {1, 2, 3, 1}: " << sol.rob(case1) << " (Expected: 4)" << endl;

    // Test Case 2: Max sum with non-adjacent
    vector<int> case2 = {2, 7, 9, 3, 1};
    cout << "Test Case 2 {2, 7, 9, 3, 1}: " << sol.rob(case2) << " (Expected: 12)" << endl;

    // Test Case 3: Alternating large values
    vector<int> case3 = {10, 1, 1, 10};
    cout << "Test Case 3 {10, 1, 1, 10}: " << sol.rob(case3) << " (Expected: 20)" << endl;

    return 0;
}