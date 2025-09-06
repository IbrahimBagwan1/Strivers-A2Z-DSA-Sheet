#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void helperPath(int i, int j, int n, vector<vector<int>> &grid, vector<string> &paths, string s){
        if(i==n-1 && j==n-1){
            paths.push_back(s);
            return ;
        }

        if(grid[i][j]==0) return;
        grid[i][j] = 0;

        // Down
        if(i<n-1 && grid[i+1][j]==1){
            helperPath(i+1, j, n, grid, paths, s+'D');
        }

        // Left
        if(j>0 && grid[i][j-1]==1){
            helperPath(i, j-1, n, grid, paths, s+'L');
        }

        // Right
        if(j<n-1 && grid[i][j+1]==1){
            helperPath(i, j+1, n, grid, paths, s+'R');
        }

        // Up
        if(i>0 && grid[i-1][j]==1){
            helperPath(i-1, j, n, grid, paths, s+'U');
        }

        grid[i][j]=1;
    }

    vector<string> findPath(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<string> paths;
        if(grid[0][0]==0) return paths;

        helperPath(0,0, n, grid, paths, "");
        return paths;
    }
};

int main() {
    int n;
    cout << "Enter grid size: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter grid values (0 or 1):" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }

    Solution obj;
    vector<string> result = obj.findPath(grid);

    if(result.empty()){
        cout << "No path exists!" << endl;
    } else {
        cout << "Paths:" << endl;
        for(string path : result){
            cout << path << endl;
        }
    }

    return 0;
}
