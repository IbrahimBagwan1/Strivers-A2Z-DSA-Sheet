#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // Standard modulo for subset counting problems to prevent integer overflow
    const int MOD = 1e9 + 7;

public:
    int helpRecursiveIsSubsetSum(vector<int> &arr, int idx, int target, vector<vector<int>> & dp) {
        // Base Case: Traverse all the way to index 0 to catch potential 0s in the array
        if (idx == 0) {
            // If target is 0 and the element is 0, we have 2 choices (take 0 or leave 0)
            if (target == 0 && arr[0] == 0) return 2;
            
            // If target is 0, or if we exactly hit the target with the 0th element
            if (target == 0 || target == arr[0]) return 1;
            
            return 0;
        } 

        if (dp[idx][target] != -1) return dp[idx][target];

        // Option 1: Do not take the current element
        int notTake = helpRecursiveIsSubsetSum(arr, idx - 1, target, dp) % MOD;

        // Option 2: Take the current element (if it's less than or equal to the remaining target)
        int take = 0;
        if (arr[idx] <= target) {
            take = helpRecursiveIsSubsetSum(arr, idx - 1, target - arr[idx], dp) % MOD;
        }

        // Store the result in DP table and return
        return dp[idx][target] = (notTake + take) % MOD;        
    }

    int perfectSum(vector<int>& arr, int K) {
        int n = arr.size();
        
        // Edge case: If the array is empty
        if (n == 0) return (K == 0) ? 1 : 0;

        vector<vector<int>> dp(n, vector<int>(K + 1, -1));
        return helpRecursiveIsSubsetSum(arr, n - 1, K, dp);
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Standard case
    vector<int> arr1 = {5, 2, 3, 10, 6, 8};
    int target1 = 10;
    cout << "Test Case 1 Output: " << sol.perfectSum(arr1, target1) << "\n"; 
    // Subsets: {10}, {5, 2, 3}, {2, 8} -> Expected Output: 3

    // Test Case 2: The "Zero Trap" case
    vector<int> arr2 = {0, 1};
    int target2 = 1;
    cout << "Test Case 2 Output: " << sol.perfectSum(arr2, target2) << "\n"; 
    // Subsets: {1}, {0, 1} -> Expected Output: 2

    // Test Case 3: Multiple zeros
    vector<int> arr3 = {0, 0, 0, 0, 0};
    int target3 = 0;
    cout << "Test Case 3 Output: " << sol.perfectSum(arr3, target3) << "\n"; 
    // Subsets: 2^5 -> Expected Output: 32

    return 0;
}