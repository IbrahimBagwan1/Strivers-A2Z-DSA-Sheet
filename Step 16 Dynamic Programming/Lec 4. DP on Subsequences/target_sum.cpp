#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int helperTargetSum(int n, vector<int> & nums, int target, int sum, vector<vector<int>> & dp){
        // base case.
        if(n==0){
            if(nums[0]+sum == target && sum-nums[0] == target) return 2;
            else if(nums[0]+sum == target) return 1;
            else if(sum-nums[0] == target) return 1;
            return 0;
        }
        // dp case
        if(dp[n][sum] != -1) return dp[n][sum];
        // recursive case.
        int addPlus = helperTargetSum(n-1, nums, target, sum+nums[n], dp);

        int addMinus = helperTargetSum(n-1, nums, target, sum-nums[n], dp); 

        // return statement.
        return dp[n][sum] = addPlus + addMinus;
    }

public:
    int helpRecursiveIsSubsetSum(vector<int> &arr, int idx, int target, vector<vector<int>> & dp){
        if(idx == 0){
            if(arr[0] == 0 && target == 0){
                return 2;
            }
            else if(target==0 || arr[0]==target) return 1;
            else return 0;
        } 

        if(dp[idx][target] != -1) return dp[idx][target];

        int notTake = helpRecursiveIsSubsetSum(arr, idx-1, target, dp);

        int take = false;
        if(arr[idx] <= target) 
            take = helpRecursiveIsSubsetSum(arr, idx-1, target - arr[idx], dp);

        return dp[idx][target] = (notTake + take);        
    }

    int countPartitions(int n, int diff, vector<int>& arr) {
        int sizeArr = arr.size();
        int totalSum = 0;
        for(int i=0; i<sizeArr; i++) totalSum += arr[i];

        if((totalSum-diff<0) || (totalSum-diff)%2) return false;
        vector<vector<int>> dp(sizeArr, vector<int> ((totalSum-diff)/2+1, -1));
        return helpRecursiveIsSubsetSum(arr, sizeArr-1, ((totalSum-diff)/2), dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return helperTargetSum(n-1, nums, target, 0, dp);

        return countPartitions(n, target, nums);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    cout << "Test Case 1 (nums = [1, 1, 1, 1, 1], target = 3): ";
    cout << sol.findTargetSumWays(nums1, target1) << " ways" << endl;
    // Expected Output: 5

    // Test Case 2: Single element
    vector<int> nums2 = {1};
    int target2 = 1;
    cout << "Test Case 2 (nums = [1], target = 1): ";
    cout << sol.findTargetSumWays(nums2, target2) << " ways" << endl;
    // Expected Output: 1

    // Test Case 3: Includes zeros (Tricky case for subset sum)
    vector<int> nums3 = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    int target3 = 1;
    cout << "Test Case 3 (nums = [0, 0, 0, 0, 0, 0, 0, 0, 1], target = 1): ";
    cout << sol.findTargetSumWays(nums3, target3) << " ways" << endl;
    // Expected Output: 256

    return 0;
}