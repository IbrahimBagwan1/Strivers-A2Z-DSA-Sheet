#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int helperCoins(int n, int amount, vector<int> & coins, vector<vector<int>> &dp){
        if(amount ==0 ){
            return 1;
        }

        if(n==0){
            if(amount % coins[0] == 0) return 1;
            return 0;
        }

        if(dp[n][amount] != -1) return dp[n][amount];

        int notTake = helperCoins(n-1, amount, coins, dp);
        int take =  0;
        if(coins[n] <= amount){
            take = helperCoins(n, amount-coins[n], coins, dp);
        }

        return dp[n][amount] = take + notTake; 
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return helperCoins(n-1, amount, coins, dp);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 5;
    cout << "Test Case 1 (coins = [1, 2, 5], amount = 5): ";
    cout << sol.change(amount1, coins1) << " ways" << endl;
    // Expected Output: 4 (5, 2+2+1, 2+1+1+1, 1+1+1+1+1)

    // Test Case 2: Impossible case
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test Case 2 (coins = [2], amount = 3): ";
    cout << sol.change(amount2, coins2) << " ways" << endl;
    // Expected Output: 0

    // Test Case 3: Zero amount
    vector<int> coins3 = {10};
    int amount3 = 0;
    cout << "Test Case 3 (coins = [10], amount = 0): ";
    cout << sol.change(amount3, coins3) << " ways" << endl;
    // Expected Output: 1 (1 way to make 0 amount: use 0 coins)

    return 0;
}