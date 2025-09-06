#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void searchString(vector<vector<char>>& board, string word, int i, int j, int n, int m, int idx, bool &check) {
        if (idx == word.length()) {
            check = true;
            return;
        }

        // Temporarily mark the current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Move Right
        if (j < m - 1 && board[i][j + 1] == word[idx]) {
            searchString(board, word, i, j + 1, n, m, idx + 1, check);
        }

        // Move Left
        if (j > 0 && board[i][j - 1] == word[idx]) {
            searchString(board, word, i, j - 1, n, m, idx + 1, check);
        }

        // Move Up
        if (i > 0 && board[i - 1][j] == word[idx]) {
            searchString(board, word, i - 1, j, n, m, idx + 1, check);
        }

        // Move Down
        if (i < n - 1 && board[i + 1][j] == word[idx]) {
            searchString(board, word, i + 1, j, n, m, idx + 1, check);
        }

        // Restore the cell (backtrack)
        board[i][j] = temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool check = false;

        for (int i = 0; i < n && !check; i++) {
            for (int j = 0; j < m && !check; j++) {
                if (board[i][j] == word[0]) {
                    searchString(board, word, i, j, n, m, 1, check);
                }
            }
        }
        return check;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    Solution sol;
    if (sol.exist(board, word)) {
        cout << "Word exists in the board\n";
    } else {
        cout << "Word does not exist in the board\n";
    }

    return 0;
}
