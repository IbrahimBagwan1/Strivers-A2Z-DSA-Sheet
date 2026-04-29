#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int i , int j, string & word1, string & word2, vector<vector<int>> & dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            return helper(i-1, j-1, word1, word2, dp);
        }

        return dp[i][j] =  min(
            1 + helper(i,j-1,word1, word2, dp),
            min(1 + helper(i-1,j,word1, word2, dp),
                1 + helper(i-1,j-1,word1, word2, dp))
        );
    }

    int minDistance(string word1, string word2) {   
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int i=0; i<=m; i++) dp[0][i] = i;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){

                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] =  min(1 +dp[i][j-1],
                        min(1 + dp[i-1][j], 1 + dp[i-1][j-1])
                    );
                }
            }
        }

        return dp[n][m];
    }   
};

int main() {
    Solution obj;

    string word1 = "horse";
    string word2 = "ros";

    int result = obj.minDistance(word1, word2);

    cout << "Minimum Edit Distance: " << result << endl;

    return 0;
}