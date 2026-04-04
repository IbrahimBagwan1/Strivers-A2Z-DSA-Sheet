#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m =  board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(board[i][j]=='O'){
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                }
            }
        }
        
        int drow[] = {-1, 1,  0, 0};
        int dcol[] = { 0, 0, -1, 1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow < m && nrow>=0 && ncol>=0 && ncol<n && board[nrow][ncol]=='O' && !visited[nrow][ncol]){
                    q.push({nrow, ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};

int main(){
    // Test case 1
    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'X'}
    };
    
    Solution sol1;
    sol1.solve(board1);
    
    cout << "Test case 1 result:" << endl;
    for(auto& row : board1){
        for(auto& ch : row){
            cout << ch << " ";
        }
        cout << endl;
    }
    
    // Test case 2
    vector<vector<char>> board2 = {
        {'X', 'O', 'X'},
        {'O', 'O', 'O'},
        {'X', 'O', 'X'}
    };
    
    Solution sol2;
    sol2.solve(board2);
    
    cout << "Test case 2 result:" << endl;
    for(auto& row : board2){
        for(auto& ch : row){
            cout << ch << " ";
        }
        cout << endl;
    }
    
    return 0;
}
