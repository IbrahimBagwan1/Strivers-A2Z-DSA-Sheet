#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int uniquePaths(int m, int n) { 
        // Note: Using a 2D array dp[m][n]
        int dp[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // Base case: Only one way to reach any cell in the first row or column
                if(i==0 || j==0) dp[i][j]=1;
                
                // DP transition: Ways to reach current = ways from top + ways from left
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;

    // Test Case 1: 3x7 grid
    int m1 = 3, n1 = 7;
    cout << "Test Case 1 (3x7): " << sol.uniquePaths(m1, n1) << " (Expected: 28)" << endl;

    // Test Case 2: 3x2 grid
    int m2 = 3, n2 = 2;
    cout << "Test Case 2 (3x2): " << sol.uniquePaths(m2, n2) << " (Expected: 3)" << endl;

    // Test Case 3: 1x1 grid
    int m3 = 1, n3 = 1;
    cout << "Test Case 3 (1x1): " << sol.uniquePaths(m3, n3) << " (Expected: 1)" << endl;

    return 0;
}