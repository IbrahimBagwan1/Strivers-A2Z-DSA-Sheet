#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:

  int knapsack01(int idx, int capacity, vector<int> & weights, vector<int> & profits, vector<vector<int>> &dp){
    if(idx == 0 ){
      if(weights[idx] <= capacity)
        return profits[0];
      else return 0; 
    }
    if(dp[idx][capacity] != -1) return dp[idx][capacity];

    int notTake = knapsack01(idx-1, capacity, weights, profits, dp);

    int take =0;
    if(weights[idx] <= capacity) take = profits[idx] + knapsack01(idx-1, capacity-weights[idx], weights, profits, dp);

    return dp[idx][capacity] = max(take , notTake);
  }

};

int main(){
  Solution sol;
  vector<int> profits = {30, 40, 60};
  vector<int> weights = {3,  2,  4};
  int n = weights.size();
  int capacity = 7;
  // vector<vector<int>> dp(n, vector<int> (capacity+1, -1));
  // cout << sol.knapsack01(n-1, capacity, weights, profits, dp);

  vector<int> prev (capacity+1, 0);


  // now checking the tabulation form...

  for(int cap = weights[0]; cap <= capacity; cap++){
    prev[cap] = profits[0];
  }

  for(int i=1; i<n ;i++){
    
    for(int cap=capacity; cap>=0; cap--){

      int notTake = prev[cap];
      int take =0;
      if(weights[i] <= cap){
        take = profits[i] + prev[cap-weights[i]];
      }

      prev[cap] = max(take, notTake);
    }
  }

  cout<< prev[capacity];
  return 0;
}