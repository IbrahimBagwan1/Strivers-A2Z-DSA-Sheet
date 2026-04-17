#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helperClimberStairs(int n, vector<int> &dp){
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n] != -1) return dp[n];
        return dp[n] = helperClimberStairs(n-1, dp) + helperClimberStairs(n-2, dp);
    }

    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);

        // return helperClimberStairs(n, dp);

        // optimized Solution;
        if(n==1) return 1;
        if(n==2) return 2;

        int prev =1;
        int next =2;
        int solu = 3;
        for(int i=3; i<=n; i++){
            solu = prev + next;
            prev = next;
            next = solu;
        }
        return solu;

    }
};

int main() {
    Solution sol;
    int n = 5;
    cout << "Number of ways to climb " << n << " stairs: " << sol.climbStairs(n) << endl;
    return 0;
}
