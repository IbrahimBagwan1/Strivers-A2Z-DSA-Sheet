#include <bits/stdc++.h>
using namespace std;

class Solution {
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

        // Changed 'false' to '0' since this is an integer addition, not a boolean flag
        int take = 0;
        if(arr[idx] <= target) {
            take = helpRecursiveIsSubsetSum(arr, idx-1, target - arr[idx], dp);
        }

        return dp[idx][target] = (notTake + take);        
    }

    int countPartitions(int n, int diff, vector<int>& arr) {
        int sizeArr = arr.size();
        int totalSum = 0;
        for(int i=0; i<sizeArr; i++) totalSum += arr[i];

        // If total sum minus diff is negative or odd, valid partition isn't possible
        if((totalSum-diff<0) || (totalSum-diff)%2) return 0; // Returning 0 instead of false for int return type
        
        vector<vector<int>> dp(sizeArr, vector<int> ((totalSum-diff)/2+1, -1));
        return helpRecursiveIsSubsetSum(arr, sizeArr-1, ((totalSum-diff)/2), dp);
    }
};

int main() {
    // 1. Create an instance of the Solution class
    Solution sol;
    
    // 2. Define a test case
    // Example: We want to partition the array such that the difference between the two subsets is exactly 3.
    vector<int> arr = {5, 2, 6, 4};
    int diff = 3;
    int n = arr.size();
    
    // 3. Call the function and store the result
    int result = sol.countPartitions(n, diff, arr);
    
    // 4. Print the result
    cout << "Array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << "\nTarget Difference: " << diff << endl;
    cout << "Number of valid partitions: " << result << endl;

    return 0;
}