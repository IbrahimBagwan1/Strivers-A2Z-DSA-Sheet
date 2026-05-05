#include<iostream>
#include<vector>
using namespace std;


class Solution {
private:
    int N;
public:
    int recursive(int idx, int buy , int total, const vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(idx == N || total==0) return 0;
        
        if(dp[idx][buy][total] != -1) return dp[idx][buy][total];
        int profit = 0;
        if(buy){
            profit = max (-prices[idx] + recursive(idx+1, 0, total, prices, dp), 
                            0 + recursive(idx+1, 1, total, prices, dp)); 
        }
        else {
            profit = max (prices[idx] + recursive(idx+1, 1, total-1, prices, dp), 
                            0 + recursive(idx+1, 0, total, prices, dp)); 
        }

        return dp[idx][buy][total]  = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        N=n;
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return recursive(0, 1, k, prices, dp);

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        
        for(int idx=n-1; idx>=0; idx--){
            for(int buy =0; buy<=1; buy++){
                for(int total=1; total<=k; total++){
                    int profit = 0;
                    if(buy){
                        profit = max (-prices[idx] + dp[idx+1][0][total] , 
                                          0        + dp[idx+1][1][total] ); 
                    }
                    else {
                        profit = max (prices[idx] + dp[idx+1][1][total-1] , 
                                          0       + dp[idx+1][0][total] ); 
                    }

                    dp[idx][buy][total]  = profit;
                }
            }
        }
        return dp[0][1][k];
    }
    
};


int main(){
    Solution obj;

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int k = 2;

    int result = obj.maxProfit(k, prices);

    cout << result;

    return 0;
}