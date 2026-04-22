#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // solved using tabulation and space optimization.
        const long long MOD = 2 * 1e9;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        vector<int> prev(n+1, 0);

        for(int i=0; i<m; i++){
            vector<int> temp(n+1, 0);
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1) temp[j] = 0;

                else if(i==0 && j==0) temp[j] = 1;
                else{
                    long long up = 0, left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = temp[j-1];
                    temp[j] = (int)(up + left) ;
                }
            }
            prev = temp;
        }

        return prev[n-1];
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard grid with one obstacle in the middle
    // 0 0 0
    // 0 1 0
    // 0 0 0
    vector<vector<int>> grid1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << "Test Case 1: " << sol.uniquePathsWithObstacles(grid1) << " (Expected: 2)" << endl;

    // Test Case 2: Obstacle blocking a 2x2 grid
    // 0 1
    // 0 0
    vector<vector<int>> grid2 = {
        {0, 1},
        {0, 0}
    };
    cout << "Test Case 2: " << sol.uniquePathsWithObstacles(grid2) << " (Expected: 1)" << endl;

    // Test Case 3: Start point is an obstacle
    vector<vector<int>> grid3 = {
        {1, 0},
        {0, 0}
    };
    cout << "Test Case 3: " << sol.uniquePathsWithObstacles(grid3) << " (Expected: 0)" << endl;

    return 0;
}