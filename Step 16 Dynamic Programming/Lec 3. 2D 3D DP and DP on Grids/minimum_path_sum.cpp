#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:            

    // [[1,3,1],[1,5,1],[4,2,1]]
    int helperMinPath(vector<vector<int>>& grid, int i ,int j, int m , int n, vector<vector<int>> &dp){
        if(i==m && j==n){
            return grid[m][n];
        }
        if(i>m || j>n) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];

        int right = grid[i][j] + helperMinPath(grid, i, j+1, m, n, dp);
        int down = grid[i][j] + helperMinPath(grid, i+1, j, m, n, dp);

        return dp[i][j] = min(right, down);

    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        // return helperMinPath(grid, 0, 0, m-1, n-1, dp);

        // solving using tabulation...

        // dp[0][0] =grid[0][0];

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(i==0 && j==0) continue;
        //         int right = grid[i][j]; 

        //         if(i-1 >= 0) right += dp[i-1][j];
        //         else right += 1e9;

        //         int down = grid[i][j]; 
        //         if(j-1 >= 0) down += dp[i][j-1] ;
        //         else down += 1e9;

        //         dp[i][j] = min(right, down);

        //     }
        // }

        // return dp[m-1][n-1];

        // // solved using space optimization...
        
        vector<int> prev(n, 0);
        
        for(int i=0; i<m; i++){
            vector<int> temp(n, 0);

            for(int j=0; j<n; j++){
                if(i==0 && j==0) {
                    temp[0] = grid[0][0];
                    continue;
                }

                int right = grid[i][j]; 

                if(i-1 >= 0) right += prev[j];
                else right += 1e9;

                int down = grid[i][j]; 
                if(j-1 >= 0) down += temp[j-1];
                else down += 1e9;

                temp[j] = min(right, down);

            }
            prev = temp;
        }
        
        return prev[n-1];
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard 3x3 Grid
    vector<vector<int>> grid1 = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    // Path: 1 -> 3 -> 1 -> 1 -> 1 = 7
    cout << "Test Case 1: " << sol.minPathSum(grid1) << " (Expected: 7)" << endl;

    // Test Case 2: 2x3 Grid
    vector<vector<int>> grid2 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    // Path: 1 -> 2 -> 3 -> 6 = 12
    cout << "Test Case 2: " << sol.minPathSum(grid2) << " (Expected: 12)" << endl;

    // Test Case 3: Single row
    vector<vector<int>> grid3 = {{1, 2, 3}};
    cout << "Test Case 3: " << sol.minPathSum(grid3) << " (Expected: 6)" << endl;

    return 0;
}