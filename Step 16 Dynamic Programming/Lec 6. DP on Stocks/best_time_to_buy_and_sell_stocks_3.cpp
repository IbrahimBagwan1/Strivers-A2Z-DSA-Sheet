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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // N=n;
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return recursive(0, 1, 2, prices, dp);

        // tabulation.
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        // base cases.
        // for(int i=0; i<2; i++){
        //     for(int j=0; j<3; j++){
        //         dp[n][i][j] =0;
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<2; j++){
        //         dp[i][j][0] = 0;
        //     }
        // }


        for(int idx=n-1; idx>=0; idx--){
            for(int buy =0; buy<=1; buy++){
                for(int total=1; total<=2; total++){
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
        return dp[0][1][2];
    }
};


int main(){
  Solution sol;
  vector<int> arr = {7,1,5,3,6,4};
  cout << sol.maxProfit(arr);
  return 0;
}