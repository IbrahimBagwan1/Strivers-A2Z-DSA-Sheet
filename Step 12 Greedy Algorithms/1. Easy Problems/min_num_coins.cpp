#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MinimumCoins(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e9); // large number = infinity
        dp[0] = 0; // base case

        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (c <= i) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        return (dp[amount] == 1e9) ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Example 1: " << sol.MinimumCoins(coins1, amount1) << endl;
    // Expected: 3 (11 = 5 + 5 + 1)

    // Example 2
    vector<int> coins2 = {2, 5};
    int amount2 = 3;
    cout << "Example 2: " << sol.MinimumCoins(coins2, amount2) << endl;
    // Expected: -1 (can't make 3 from 2 and 5)

    // Example 3 (extra)
    vector<int> coins3 = {1, 3, 4};
    int amount3 = 6;
    cout << "Example 3: " << sol.MinimumCoins(coins3, amount3) << endl;
    // Expected: 2 (6 = 3 + 3)

    return 0;
}
