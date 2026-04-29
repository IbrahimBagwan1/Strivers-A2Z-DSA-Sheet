#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int i , int j, string &s, string &t, vector<vector<int>> & dp){
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = helper(i-1, j-1, s, t, dp) + helper(i-1,j, s,t, dp);
        }
        else {
            return dp[i][j] = helper(i-1, j, s, t, dp);
        }
    }

    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<double>> dp(n1+1, vector<double> (n2+1, 0));

        for(int i=0; i<=n1; i++) dp[i][0] = 1;

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){

                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        } 

        return (int)dp[n1][n2];
    }
};

int main() {
    Solution obj;

    string s = "babgbag";
    string t = "bag";

    int result = obj.numDistinct(s, t);

    cout << "Number of distinct subsequences: " << result << endl;

    return 0;
}