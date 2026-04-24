#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helperCanPartition(vector<int> &nums, int idx, int target, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(idx == 0) return (nums[idx] == target);
        
        if(dp[idx][target] != -1) return dp[idx][target];

        bool notTake = helperCanPartition(nums, idx-1, target, dp);
        bool take = false;
        if(nums[idx] <= target) 
            take = helperCanPartition(nums, idx-1, target - nums[idx], dp);

        return dp[idx][target] = (take || notTake);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 != 0) return false;

        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
        return helperCanPartition(nums, n-1, sum/2, dp);
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 5, 11, 5};  // example input

    if(obj.canPartition(nums))
        cout << "Can be partitioned into equal subset sum";
    else
        cout << "Cannot be partitioned into equal subset sum";

    return 0;
}