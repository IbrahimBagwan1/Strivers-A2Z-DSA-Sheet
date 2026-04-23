#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int recursiveMaxChoco(int i, int j1, int j2, vector<vector<vector<int>>> &dp, vector<vector<int>> &g, int m, int n){
        if(j1<0 || j1>=n || j2<0 || j2>=n){
            return -1e9;
        }

        if(i==m-1){
            if(j1 != j2) return g[i][j1] + g[i][j2];
            else return g[i][j1];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        // exploring all the paths.
        int maxi = -1e9;

        for(int p1= -1; p1<=1; p1++){
            for(int p2=-1; p2<=1; p2++){
                int value = 0;
                if(j1 == j2) value = g[i][j1];
                else value = g[i][j1] + g[i][j2];
                value += recursiveMaxChoco(i+1, j1+p1, j2+p2, dp, g, m, n);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }


    int maxChocolates(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int> (n, -1)));
        
        return recursiveMaxChoco(0, 0, n-1, dp, g, m, n);
    }
}; 


int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };

    int result = obj.maxChocolates(grid);
    cout << result;

    return 0;
}