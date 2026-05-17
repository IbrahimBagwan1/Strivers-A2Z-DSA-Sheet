#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int solve(int i, int j, const string& s, vector<vector<int>>& dp) {
        // Base Case: Single character expression
        if (i == j) {
            return s[i] == 't' ? 1 : 0;
        }

        // Return cached result if already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        char op = s[i]; // The operator for this entire range [i, j]
        
        // We gather the results of all sub-expressions inside the parentheses
        vector<bool> subResults;
        
        int start = i + 2; // Skip the operator and the opening '('
        int pBalance = 0;   // To keep track of nested parentheses pairs
        
        // Scan the inner components from (i+2) up to (j-1)
        for (int k = i + 2; k < j; ++k) {
            if (s[k] == '(') pBalance++;
            else if (s[k] == ')') pBalance--;
            
            // A comma at balance 0 means we found the boundary of a sub-expression
            if (s[k] == ',' && pBalance == 0) {
                subResults.push_back(solve(start, k - 1, s, dp));
                start = k + 1; // Next sub-expression starts after the comma
            }
        }
        // Don't forget to evaluate the very last sub-expression in the block
        subResults.push_back(solve(start, j - 1, s, dp));

        // Evaluate according to the operator 'op'
        bool finalResult;
        if (op == '!') {
            finalResult = !subResults[0];
        } else if (op == '&') {
            finalResult = true;
            for (bool res : subResults) {
                if (!res) {
                    finalResult = false;
                    break;
                }
            }
        } else { // op == '|'
            finalResult = false;
            for (bool res : subResults) {
                if (res) {
                    finalResult = true;
                    break;
                }
            }
        }

        return dp[i][j] = (finalResult ? 1 : 0);
    }

    bool parseBoolExpr(string expression) {
        int n = expression.size();
        // dp[i][j] will store -1 (unvisited), 0 (false), or 1 (true)
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, expression, dp) == 1;
    }
};

int main() {
    Solution solver;
    string expr = "|(&(t,f,t),!(t))";
    
    if (solver.parseBoolExpr(expr)) {
        cout << "The expression evaluates to: true" << endl;
    } else {
        cout << "The expression evaluates to: false" << endl;
    }
    return 0;
}