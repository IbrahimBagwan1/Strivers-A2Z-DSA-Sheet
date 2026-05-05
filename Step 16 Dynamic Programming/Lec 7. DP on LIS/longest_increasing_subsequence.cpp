#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int helperLis(int idx, int prevIndex, int n, vector<int> & nums, vector<vector<int>> &dp){
        if(idx == n) return 0;
        
        if(dp[idx][prevIndex+1] != -1) return dp[idx][prevIndex+1];
        int pick = 0;
        
        if(prevIndex == -1 || nums[idx] > nums[prevIndex]){
            pick = 1 + helperLis(idx+1, idx, n, nums, dp);
        }
        
        int notpick = 0 + helperLis(idx+1, prevIndex, n, nums, dp);

        return dp[idx][prevIndex+1] = max(pick, notpick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return helperLis(0, -1, n, nums, dp);
    }    
};


int main(){
    Solution sol;
    vector<int> arr = {10,9,2,5,3,7,101,18};
    cout<< sol.lengthOfLIS(arr);
    return 0;
}
