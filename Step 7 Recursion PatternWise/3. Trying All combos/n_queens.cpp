#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> grid;
    vector<vector<string>> result;
    
    bool canPlace(int row, int col, int n){
        for(int i=0; i<row; i++){
            if(grid[i][col] == 'Q') return false;
        }

        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(grid[i][j]=='Q') return false;
        }

        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(grid[i][j]=='Q') return false;
        }
        return true;
    }

    void f(int row, int n){
        if(row == n){
            vector<string> temp;
            for(int i=0; i<n; i++){
                string res;
                for(int j=0; j<n; j++){
                    res += grid[i][j];
                }
                temp.push_back(res);
            }
            result.push_back(temp);
            return;
        }
        for(int col=0; col<n; col++){
            if(canPlace(row, col, n)){
                grid[row][col] = 'Q';
                f(row+1, n);
                grid[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        grid.resize(n, vector<char>(n, '.'));
        f(0, n);
        return result;
    }
};

int main() {
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    Solution sol;
    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << "\n\n";
    for (int k = 0; k < solutions.size(); k++) {
        cout << "Solution " << k+1 << ":\n";
        for (string row : solutions[k]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
