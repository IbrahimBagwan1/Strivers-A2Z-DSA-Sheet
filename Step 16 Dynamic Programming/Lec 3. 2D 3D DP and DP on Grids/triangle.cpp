#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int helperMinPath(vector<vector<int>>& triangle, int i ,int j, int n, vector<vector<int>> &dp){
        if(i==n){
            return triangle[n][j];
        }
        
        if(dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + helperMinPath(triangle, i+1, j,  n, dp);
        int downRight = triangle[i][j] + helperMinPath(triangle, i+1, j+1,  n, dp);

        return dp[i][j] = min(downRight, down);

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        
        // Start with the last row values
        vector<int> prevRow = triangle[n-1];

        for (int i = n - 2; i >= 0; i--) {
            vector<int> currRow(i + 1);
            for (int j = 0; j <= i; j++) {
                // Min path for this cell is current value + min of two options below
                currRow[j] = triangle[i][j] + min(prevRow[j], prevRow[j+1]);
            }
            prevRow = currRow; // Move up
        }

        return prevRow[0];
    }

    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int m = triangle.size();

    //     vector<vector<int>> dp;

    //     for(int i=0; i<m-1; i++){
    //         vector<int> temp(i+1, -1);
    //         dp.push_back(temp);
    //     }
    //     dp.push_back(triangle[m-1]);

    //     // return helperMinPath(triangle, 0, 0, m-1, dp);

    //     // // lets do tabulation..

    //     for(int i=m-2; i>=0; i--){
    //         int n = triangle[i].size();
    //         for(int j=0; j<n; j++){
    //             int down = triangle[i][j] + dp[i+1][j];


    //             int downRight = triangle[i][j] + dp[i+1][j+1];
                
    //             dp[i][j] = min(down, downRight);
    //         }
    //     }

    //     return dp[0][0];
    // }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Triangle
    //    2
    //   3 4
    //  6 5 7
    // 4 1 8 3
    vector<vector<int>> triangle1 = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    cout << "Test Case 1: " << sol.minimumTotal(triangle1) << " (Expected: 11)" << endl;

    // Test Case 2: Triangle with single element
    vector<vector<int>> triangle2 = {{-10}};
    cout << "Test Case 2: " << sol.minimumTotal(triangle2) << " (Expected: -10)" << endl;

    // Test Case 3: Simple triangle
    vector<vector<int>> triangle3 = {
        {1},
        {2, 3}
    };
    cout << "Test Case 3: " << sol.minimumTotal(triangle3) << " (Expected: 3)" << endl;

    return 0;
}