#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int recursivePartition(vector<int> & arr, int k, int i, int end, vector<int> &dp){
        if(i == end) return 0;
        
        if(dp[i] != -1) return dp[i];

        int maxElement = 0; // Tracks the largest element in the current window
        int maxTotalSum = 0; // Tracks the best overall sum we can get

        for(int idx=1; idx<=k; idx++){
            if(i+idx > end) continue;

            // Update the maximum element in the current partition
            maxElement = max(maxElement, arr[i+idx-1]);

            // FIX: The next recursive call must start at (i + idx)
            int cost =  (maxElement * idx) +
                        recursivePartition(arr, k, i + idx, end, dp);
            
            maxTotalSum = max(maxTotalSum, cost);
        }
        return dp[i] = maxTotalSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);

        return recursivePartition(arr, k, 0, n, dp);    
    }
};

int main() {
    Solution solver;
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    int result = solver.maxSumAfterPartitioning(arr, k);
    cout << "Maximum sum after partitioning: " << result << endl; // Output: 84

    return 0;
}