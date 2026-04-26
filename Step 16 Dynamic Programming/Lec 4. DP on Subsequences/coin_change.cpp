#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int knapsack01(int idx, int capacity, vector<int> & weights, vector<vector<int>> &dp){

        if(idx == 0){
            if(capacity % weights[0] == 0)
                return capacity / weights[0];
            else return 1e8; 
        }

        if(dp[idx][capacity] != 1e8) return dp[idx][capacity];

        int notTake = knapsack01(idx-1, capacity, weights, dp);

        int take =1e8;
        if(weights[idx] <= capacity) take = 1 + knapsack01(idx, capacity-weights[idx], weights, dp);

        return dp[idx][capacity] = min(take , notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1, 1e8));
        // int minCoins = knapsack01(n-1, amount, coins, dp);
        // return  (minCoins == 1e8) ? -1 : minCoins;


        // require tabulation approach...
        for(int i=0; i<=amount; i++) {
            if((i % coins[0])==0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }
        for(int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }

        for(int i=1; i<n; i++){
            for(int amt=1; amt<=amount; amt++){
                int notTake = dp[i-1][amt];

                int take =1e9;
                if(coins[i] <= amt) take = 1 + dp[i][amt-coins[i]];

                dp[i][amt] = min(take , notTake);
            }
        }

        int minCoins = dp[n-1][amount];
        return  (minCoins == 1e9) ? -1 : minCoins; 
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Standard case
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Test Case 1 (coins = [1, 2, 5], amount = 11): ";
    cout << sol.coinChange(coins1, amount1) << " coins" << endl; 
    // Expected Output: 3 (5 + 5 + 1)

    // Test Case 2: Impossible case
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test Case 2 (coins = [2], amount = 3): ";
    cout << sol.coinChange(coins2, amount2) << " coins" << endl; 
    // Expected Output: -1

    // Test Case 3: Zero amount case
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Test Case 3 (coins = [1], amount = 0): ";
    cout << sol.coinChange(coins3, amount3) << " coins" << endl; 
    // Expected Output: 0

    return 0;
}