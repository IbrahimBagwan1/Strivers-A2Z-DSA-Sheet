#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> & visited, vector<vector<char>>& grid){
        int m = grid.size(); // no of rows
        int n = grid[0].size(); // no of cols
        queue<pair<int,int>> q;
        q.push({row, col});
        visited[row][col]=1;

        int drow[]= {-1, 1, 0, 0};
        int dcol[]= { 0, 0,-1, 1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >=0 && ncol>=0 && nrow<m && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); // no of rows
        int n = grid[0].size(); // no of cols

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    bfs(i,j, visited, grid);
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution sol;
    int ans = sol.numIslands(grid);
    cout << "Number of islands: " << ans << endl;
    return 0;
}