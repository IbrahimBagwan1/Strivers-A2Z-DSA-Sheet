#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int helperNinjaTraining(vector<vector<int>> & matrix, int n, int last){
        if(n == 0){
            int maxi = 0;
            for(int i=0; i<3; i++){
                if(i != last){
                    maxi = max(maxi, matrix[0][i]);
                }
            }
            return maxi;
        }

        int maximumPoints = 0;
        for(int i=0; i<3; i++){
            if(i != last){
                int points = matrix[n][i] + helperNinjaTraining(matrix, n-1, i);
                maximumPoints = max(points, maximumPoints);
            }
        }
        return maximumPoints;

    }

    int helperNinjaTrainingMemo(vector<vector<int>> & matrix, int n, int last, vector<vector<int>> &dp){
        if(n == 0){
            int maxi = 0;
            for(int i=0; i<3; i++){
                if(i != last){
                    maxi = max(maxi, matrix[0][i]);
                }
            }
            return maxi;
        }
        if(dp[n][last] != -1) return dp[n][last];

        int maximumPoints = 0;
        for(int i=0; i<3; i++){
            if(i != last){
                int points = matrix[n][i] + helperNinjaTrainingMemo(matrix, n-1, i, dp);
                maximumPoints = max(points, maximumPoints);
            }
        }
        return dp[n][last] = maximumPoints;

    }


    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int> (4, -1));
        // return helperNinjaTraining(matrix, n-1, 3);
        return helperNinjaTrainingMemo(matrix, n-1, 3, dp); // memoization.
    }
};

int main() {
    Solution sol;

    // Test Case 1
    // Days: 3, Activities: 3
    vector<vector<int>> training1 = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    };
    /*
      Possible path for max points:
      Day 2: index 0 (3 points)
      Day 1: index 2 (1 point) - cannot take 0 again
      Day 0: index 2 (5 points)
      Result: 3 + 1 + 5 = 11? No, wait:
      Day 2: index 1 (3) -> Day 1: index 0 (3) -> Day 0: index 2 (5) = 11.
    */
    cout << "Test Case 1: " << sol.ninjaTraining(training1) << " (Expected: 11)" << endl;

    // Test Case 2
    vector<vector<int>> training2 = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    // Expected: 90 + 50 + 70 = 210
    cout << "Test Case 2: " << sol.ninjaTraining(training2) << " (Expected: 210)" << endl;

    // Test Case 3
    vector<vector<int>> training3 = {
        {18, 11, 19},
        {4, 13, 7},
        {1, 8, 13}
    };
    cout << "Test Case 3: " << sol.ninjaTraining(training3) << " (Expected: 45)" << endl;

    return 0;
}