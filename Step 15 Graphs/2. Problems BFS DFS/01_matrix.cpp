#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> distanceMatrix(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<pair<int,int>, int>> q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    visited[i][j]=1;
                    q.push({{i,j}, 0});
                }
                else{
                    visited[i][j]=0;
                }
            }          
        }

        int drow[] = {-1, 1,  0, 0};
        int dcol[] = { 0, 0, -1, 1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            distanceMatrix[row][col]= steps;

            for(int i=0; i<4; i++){
                int nrow = row+drow[i]; 
                int ncol = col+dcol[i];

                if(nrow >=0 && nrow <m && ncol >=0 && ncol <n && !visited[nrow][ncol]){
                    q.push({{nrow, ncol}, steps+1});
                    visited[nrow][ncol]=1;
                }
            }

        }

        return distanceMatrix;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<vector<int>> mat1 = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> result1 = sol.updateMatrix(mat1);
    cout << "Test case 1:\n";
    for(auto& row : result1) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    
    // Test case 2
    vector<vector<int>> mat2 = {{0, 0}, {1, 1}, {1, 0}};
    vector<vector<int>> result2 = sol.updateMatrix(mat2);
    cout << "\nTest case 2:\n";
    for(auto& row : result2) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
