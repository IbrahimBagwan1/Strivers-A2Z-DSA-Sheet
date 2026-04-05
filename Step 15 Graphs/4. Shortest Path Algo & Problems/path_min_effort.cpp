#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> distance(m, vector<int> (n, 1e9));
                //   up dn  lf  rt 
        int drow[] = {1,-1, 0, 0};
        int dcol[] = {0, 0,-1, 1};

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> q;

            //  effort  i,j
        q.push({0,{0,0}});
        distance[0][0]=0;

        while(!q.empty()){
            int d = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

            if(row==m-1 && col==n-1) return d;

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
            
                if(nrow >=0 && ncol >=0 && nrow<m && ncol<n ){
                    int newdist = max(abs(grid[nrow][ncol] - grid[row][col]), d);
                    
                    if(newdist < distance[nrow][ncol]){
                        distance[nrow][ncol] = newdist;
                        q.push({newdist, {nrow, ncol}});
                    }
                }
            }
        }        

        return distance[m-1][n-1];
    }
};

int main() {
    int m = 3, n = 3;
    vector<vector<int>> grid = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    Solution sol;
    cout << sol.minimumEffortPath(grid) << endl;
    return 0;
}