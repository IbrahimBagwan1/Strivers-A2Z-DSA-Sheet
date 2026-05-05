#include<iostream>
#include<vector>
using namespace std;


class Solution {
private:
    int N;

public:
    int recursive(int idx, int buy, const vector<int> &prices, vector<vector<int>> &dp){
        if(idx >= N ) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if(buy){
            profit = max (-prices[idx] + recursive(idx+1, 0, prices, dp), 
                            0 + recursive(idx+1, 1, prices, dp)); 
        }
        else {
            profit = max (prices[idx] + recursive(idx+2, 1, prices, dp), 
                            0 + recursive(idx+1, 0, prices, dp)); 
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        N=n;
        vector<vector<int>> dp(n, (vector<int>(2, -1)));
        return recursive(0, 1, prices, dp);
    }
};


int main(){
  Solution sol;
  vector<int> arr = {7,1,5,3,6,4};
  cout << sol.maxProfit(arr);
  return 0;
}