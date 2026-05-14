#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:

    int func(int i, int j,
             vector<int> &nums,
             vector<vector<int>> &dp){

        if(i == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int minimum = 1e9;

        for(int k = i; k < j; k++){

            int steps =
                (nums[i-1] * nums[k] * nums[j]) +
                func(i, k, nums, dp) +
                func(k+1, j, nums, dp);

            minimum = min(steps, minimum);
        }

        return dp[i][j] = minimum;
    }

    int matrixMultiplication(vector<int>& nums){

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return func(1, n-1, nums, dp);
    }
};

int main(){

    Solution obj;

    vector<int> nums = {10, 20, 30, 40, 50};

    cout << obj.matrixMultiplication(nums);

    return 0;
}