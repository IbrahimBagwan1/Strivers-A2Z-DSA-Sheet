#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // For std::max

// It's generally better practice to use std:: prefix instead of this,
// but using it here as requested.
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();

        // A queue for BFS. Stores {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        int countFresh = 0;

        // Find all initial rotten oranges and count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
                if (grid[i][j] == 1) {
                    countFresh++;
                }
            }
        }
        
        // If there are no fresh oranges to begin with, no time is needed.
        if (countFresh == 0) return 0;

        int time = 0;
        // Delta arrays for navigating neighbors (Up, Right, Down, Left)
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int rottedCount = 0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            // Check all 4 adjacent cells
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check for valid, fresh orange neighbor
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                    // Mark it as rotten
                    grid[nrow][ncol] = 2;
                    // Push it to the queue with incremented time
                    q.push({{nrow, ncol}, t + 1});
                    rottedCount++;
                }
            }
        }
        
        // If the number of oranges we rotted matches the initial fresh count, return the time
        if (rottedCount == countFresh) {
            return time;
        }

        // Otherwise, some oranges were unreachable
        return -1;
    }
};

// Main function to run the code
int main() {
    // Create an instance of the Solution class
    Solution sol;

    // Example 1: All oranges can rot
    vector<vector<int>> grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << "Grid 1:" << endl;
    int result1 = sol.orangesRotting(grid1);
    cout << "Time to rot all oranges: " << result1 << endl; // Expected output: 4

    cout << "--------------------------" << endl;

    // Example 2: An orange is unreachable
    vector<vector<int>> grid2 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << "Grid 2:" << endl;
    int result2 = sol.orangesRotting(grid2);
    cout << "Time to rot all oranges: " << result2 << endl; // Expected output: -1
    
    cout << "--------------------------" << endl;

    // Example 3: No fresh oranges
    vector<vector<int>> grid3 = {{2, 2, 2}, {2, 2, 2}};
    cout << "Grid 3:" << endl;
    int result3 = sol.orangesRotting(grid3);
    cout << "Time to rot all oranges: " << result3 << endl; // Expected output: 0

    return 0;
}