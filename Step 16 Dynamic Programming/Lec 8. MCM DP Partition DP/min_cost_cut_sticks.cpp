#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Your Solution class goes here
class Solution {
public:
    int recursiveMinCost(vector<int>& cuts, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int minCost = 1e9;

        for(int idx = i; idx <= j; idx++){
            int cost = cuts[j+1] - cuts[i-1] + 
                       recursiveMinCost(cuts, i, idx-1, dp) +
                       recursiveMinCost(cuts, idx+1, j, dp);

            minCost = min(minCost, cost);
        }
        return dp[i][j] = minCost;        
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size(); 
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        
        return recursiveMinCost(cuts, 1, c, dp);    
    }
};

int main() {
    Solution solver;

    // Test Case: Stick of length 7 with cuts at 1, 3, 4, 5
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};

    int result = solver.minCost(n, cuts);

    // Expected output for this case is 16
    cout << "The minimum cost to cut the stick is: " << result << endl;

    return 0;
}