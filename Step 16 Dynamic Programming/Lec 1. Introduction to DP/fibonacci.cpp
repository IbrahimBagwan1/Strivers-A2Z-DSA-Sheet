// Tabulation = bottom up method, gotowards the results from bottom to top.
// Recursion = top down approach.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
  long long fibo(int n, vector<long long> &dp){
    if(n<=0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];

    return dp[n]= fibo(n-1, dp)+fibo(n-2, dp);
  }
};


int main(){
  Solution sol;
  long long n =  6;
  cout << "Enter the number for Fibonacci: ";
  cin>> n;

  vector<long long> dp(n+1, -1);
  cout << sol.fibo(n, dp);  // recursive solution.
  cout << "\n";
  // tabulation solution.
  dp[0] = 0;
  dp[1] = 1;
  
  for(int i=2; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  cout << dp[n];
  cout << "\n";
  // T.C = O(N)
  // S.C = O(N)

  // optimizing tabulation space.
  int prev = dp[0];
  int next = dp[1];
  int solu=1;
  for(int i=2; i<=n; i++){
    solu = prev + next;
    prev = next;
    next = solu;
  }
  cout << solu;
        //  f(0)   f(1)
// solu     prev   next  index 
//  1        0       1     1 
//  1        1       1     2 
//  2        1       2     3
//  3        2       3     4
//  5        3       5     5


  return 0;

}