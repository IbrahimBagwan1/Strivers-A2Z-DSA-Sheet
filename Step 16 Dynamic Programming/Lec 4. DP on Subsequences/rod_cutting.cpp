#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    
    int helper(vector<int> & price, int remLength, int idx, vector<vector<int>> &dp){
        // Base case: If we only have pieces of length 1, we must take 'remLength' pieces.
        if(idx == 0){
            return (price[0] * remLength); 
        }
        
        if(dp[idx][remLength] != -1) return dp[idx][remLength];

        int notTake = helper(price, remLength, idx-1, dp);

        // The length of the current piece is its index + 1
        int length = idx + 1;

        int take = 0;
        if(length <= remLength) {
            // Keep idx the same because we can make multiple cuts of the same length
            take = price[idx] + helper(price, remLength - length, idx, dp);
        }
        
        return dp[idx][remLength] = max(take, notTake);
    }

    int rodCutting(vector<int> price, int n) {
        int numPieces = price.size(); 
        
        // FIX: The DP array must have 'numPieces' rows to safely access index 'numPieces - 1'
        vector<vector<int>> dp(numPieces, vector<int> (n + 1, -1));
        
        // Start from the last index
        return helper(price, n, numPieces - 1, dp);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    // Lengths: 1  2  3  4   5   6   7   8
    // Prices:  1  5  8  9  10  17  17  20
    vector<int> price1 = {1, 5, 8, 9, 10, 17, 17, 20};
    int n1 = 8;
    cout << "Test Case 1 (Rod Length = 8): ";
    cout << sol.rodCutting(price1, n1) << " max profit" << endl;
    // Expected Output: 22 (Cut into two pieces of length 2 and one piece of length 6)

    // Test Case 2: Best to cut into all length 1 pieces
    vector<int> price2 = {3, 5, 8, 9, 10, 17, 17, 20};
    int n2 = 8;
    cout << "Test Case 2 (Rod Length = 8): ";
    cout << sol.rodCutting(price2, n2) << " max profit" << endl;
    // Expected Output: 24 (8 pieces of length 1, each worth 3)

    return 0;
}