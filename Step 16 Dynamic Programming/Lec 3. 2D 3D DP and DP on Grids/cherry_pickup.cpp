#include <bits/stdc++.h>
using namespace std;

// LeetCode 741 - Cherry Pickup

class Solution {
public:

    int helper(int r1, int c1, int r2,
               vector<vector<int>>& grid,
               vector<vector<vector<int>>>& dp,
               int n) {

        // Since both paths have taken the same number of steps:
        // r1 + c1 = r2 + c2
        int c2 = r1 + c1 - r2;

        // Out of bounds
        if (r1 >= n || c1 >= n ||
            r2 >= n || c2 >= n) {
            return -1e9;
        }

        // Thorn
        if (grid[r1][c1] == -1 ||
            grid[r2][c2] == -1) {
            return -1e9;
        }

        // Reached destination
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }

        // Already calculated
        if (dp[r1][c1][r2] != -1) {
            return dp[r1][c1][r2];
        }

        // Collect cherries from current cells
        int current = grid[r1][c1];

        // If both are on different cells, count both
        if (r1 != r2 || c1 != c2) {
            current += grid[r2][c2];
        }

        int best = -1e9;

        // 0 = Down
        // 1 = Right
        //
        // Both paths have 2 choices:
        // Down/Down
        // Down/Right
        // Right/Down
        // Right/Right

        for (int move1 = 0; move1 <= 1; move1++) {
            for (int move2 = 0; move2 <= 1; move2++) {

                int nr1 = r1;
                int nc1 = c1;

                int nr2 = r2;
                int nc2 = c2;

                // Move path 1
                if (move1 == 0)
                    nr1++;
                else
                    nc1++;

                // Move path 2
                if (move2 == 0)
                    nr2++;
                else
                    nc2++;

                best = max(
                    best,
                    helper(nr1, nc1, nr2, grid, dp, n)
                );
            }
        }

        return dp[r1][c1][r2] = current + best;
    }


    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                n,
                vector<int>(n, -1)
            )
        );

        int ans = helper(0, 0, 0, grid, dp, n);

        return max(0, ans);
    }
};


int main() {

    Solution sol;

    // -------------------------------
    // Test Case 1
    // LeetCode 741
    // Expected Output: 5
    // -------------------------------

    vector<vector<int>> grid1 = {
        {0, 1, -1},
        {1, 0, -1},
        {1, 1, 1}
    };

    cout << "Test Case 1: "
         << sol.cherryPickup(grid1) << endl;


    // -------------------------------
    // Test Case 2
    // LeetCode 741
    // Expected Output: 0
    // -------------------------------

    vector<vector<int>> grid2 = {
        {1, 1, -1},
        {1, -1, 1},
        {-1, 1, 1}
    };

    cout << "Test Case 2: "
         << sol.cherryPickup(grid2) << endl;


    return 0;
}