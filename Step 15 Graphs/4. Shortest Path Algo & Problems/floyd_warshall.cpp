#include <bits/stdc++.h>

using namespace std;

// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &matrix) {
        // Code here
        int m = matrix.size();
        int n = matrix[0].size();

        for(int k=0; k<m; k++){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if (matrix[i][k] < 1e8 && matrix[k][j] < 1e8) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }     

        return ;
    }
};

int main() {
    Solution sol;
    
    // First hardcoded input
    vector<vector<int>> mat1 = {
        {0, 5, 100000000},
        {100000000, 0, 3},
        {100000000, 100000000, 0}
    };
    
    sol.floydWarshall(mat1);
    
    cout << "After Floyd-Warshall for mat1:" << endl;
    for(auto &row : mat1) {
        for(int val : row) {
            if(val == 100000000) cout << "INF ";
            else cout << val << " ";
        }
        cout << endl;
    }
    
    // Second hardcoded input
    vector<vector<int>> mat2 = {
        {0, 1, 100000000},
        {100000000, 0, 1},
        {1, 100000000, 0}
    };
    
    sol.floydWarshall(mat2);
    
    cout << "After Floyd-Warshall for mat2:" << endl;
    for(auto &row : mat2) {
        for(int val : row) {
            if(val == 100000000) cout << "INF ";
            else cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}