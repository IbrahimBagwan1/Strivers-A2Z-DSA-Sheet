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
  // dp[0] = 0;
  // dp[1] = 1;
  cout << sol.fibo(n, dp);  

  return 0;

}