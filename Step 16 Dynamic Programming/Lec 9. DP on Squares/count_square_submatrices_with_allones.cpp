#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();

        // dp[i][j] stores the size of the largest square whose bottom-right corner is at (i, j)
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int sum = 0;

        // Initialize first column
        for(int i = 0; i < n; i++){
            dp[i][0] = matrix[i][0];
            sum += dp[i][0];
        } 

        // Initialize first row (starting from j=1 to avoid double counting dp[0][0])
        for(int j = 1; j < m; j++){
            dp[0][j] = matrix[0][j];
            sum += dp[0][j];
        }

        // Fill the DP table
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    // Check the DP table for the minimum of the three adjacent squares
                    int place = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                    dp[i][j] = place + 1;
                    sum += dp[i][j];
                }
            }
        }

        return sum;
    }
};

int main() {
    // Instantiate the solution class
    Solution solution;

    // Define a sample test case
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };

    // Output the matrix for visual reference
    cout << "Input Matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Call the function and print the result
    int totalSquares = solution.countSquares(matrix);
    cout << "\nTotal number of squares with all ones: " << totalSquares << endl;

    return 0;
}