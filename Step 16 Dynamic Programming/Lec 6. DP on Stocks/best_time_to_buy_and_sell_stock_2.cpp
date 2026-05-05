#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution{
public:
    int dpHelper(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(idx == prices.size()){
            return 0;
        }

        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit;
        if(buy){
            profit = max(-prices[idx] + dpHelper(idx+1, 0, prices, dp), dpHelper(idx+1, 1, prices, dp)); 
        }
        else{
            profit = max(prices[idx] + dpHelper(idx+1, 1, prices, dp), dpHelper(idx+1, 0, prices, dp));
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // return dpHelper(0, 1, prices, dp);

        // working for tabulation.
        dp[n][0] = dp[n][1] = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                int profit=0;
                if(j){
                    profit = max(-prices[i] + dp[i+1][0] , dp[i+1][1]); 
                    
                }
                else{
                    profit = max(prices[i] + dp[i+1][1] ,dp[i+1][0]);
                }

                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};

int main(){
  Solution sol;
  vector<int> arr = {7,1,5,3,6,4};
  cout << sol.maxProfit(arr);
  return 0;
}