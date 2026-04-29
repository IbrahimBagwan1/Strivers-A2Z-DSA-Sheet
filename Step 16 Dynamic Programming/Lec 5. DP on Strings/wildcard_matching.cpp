#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(int i ,int j, string & s, string & p, vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;

        if(j>=0 && i<0){
            for(int k=0; k<=j; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = helper(i-1, j-1, s, p, dp);
        }

        else if(p[j] == '*'){
            return dp[i][j] = helper(i-1, j, s, p, dp) || helper(i, j-1, s, p, dp); 
        }
        else {        
            return dp[i][j] = false;
        }
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        dp[0][0] = 1;
        
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            } else {
                dp[0][j] = 0;
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1]; 
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1]; 
                }
                else {        
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    Solution obj;

    string s = "adceb";
    string p = "*a*b";

    bool result = obj.isMatch(s, p);

    if(result)
        cout << "Pattern matches the string" << endl;
    else
        cout << "Pattern does NOT match the string" << endl;

    return 0;
}