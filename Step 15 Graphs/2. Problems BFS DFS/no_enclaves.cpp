#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (board[i][j] == 1) {
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
        }

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow < m && nrow >= 0 && ncol >= 0 && ncol < n &&
                    board[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0 && board[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<vector<int>> board1 = {{1, 1, 1, 1, 1},
                                  {1, 0, 1, 0, 1},
                                  {1, 0, 1, 0, 1},
                                  {1, 0, 1, 0, 1},
                                  {1, 1, 1, 1, 1}};
    cout << "Test case 1: " << sol.numEnclaves(board1) << endl;
    
    // Test case 2
    vector<vector<int>> board2 = {{0, 0, 0, 1, 1},
                                  {0, 1, 1, 1, 0},
                                  {0, 1, 0, 1, 0},
                                  {1, 1, 0, 0, 0}};
    cout << "Test case 2: " << sol.numEnclaves(board2) << endl;
    
    return 0;
}
