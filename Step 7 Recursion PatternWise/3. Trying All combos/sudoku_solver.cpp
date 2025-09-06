#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidNum(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0; i<9; i++){
            // Check row
            if(board[row][i]==c) return false;

            // Check column
            if(board[i][col]==c) return false;

            // Check 3x3 sub-box
            if(board[3* (row/3) + i/3][3*(col/3) + i%3]==c) return false;
        }
        return true;
    }
    
    bool helperSudoku(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]== '.'){
                    for(char c = '1'; c<='9'; c++){
                        if(isValidNum(board, i, j, c)){
                            board[i][j] = c;

                            if(helperSudoku(board)==true){
                                return true;
                            } else {
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helperSudoku(board);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution solver;
    solver.solveSudoku(board);

    cout << "Solved Sudoku:\n";
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
