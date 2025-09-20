#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <algorithm> // For std::max

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // Initialize sums to 0
        int lsum = 0, rsum = 0;

        // Calculate the sum of the initial k cards from the left
        for(int i=0; i < k; i++){
            lsum += cardPoints[i];
        }
        
        // This is our first potential maximum score
        int maxSum = lsum;

        // Now, slide the window. For each step, remove one card from the
        // left side's end and add one card from the right side's end.
        int rIndex = n - 1;
        for(int i = k - 1; i >= 0; i--){
            // Remove the rightmost card from the left part
            lsum -= cardPoints[i];
            // Add the rightmost card from the original array
            rsum += cardPoints[rIndex];
            rIndex--;

            // Check if the new combination gives a better score
            maxSum = max(maxSum, lsum + rsum);
        }
        
        return maxSum;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> cardPoints1 = {1, 2, 3, 4, 5, 6, 1};
    int k1 = 3;
    cout << "Test Case 1:" << endl;
    cout << "Card Points: {1, 2, 3, 4, 5, 6, 1}, k = 3" << endl;
    cout << "Maximum Score: " << sol.maxScore(cardPoints1, k1) << endl; // Expected: 12
    cout << "--------------------" << endl;

    // Test Case 2
    vector<int> cardPoints2 = {100, 40, 17, 9, 73, 75};
    int k2 = 3;
    cout << "Test Case 2:" << endl;
    cout << "Card Points: {100, 40, 17, 9, 73, 75}, k = 3" << endl;
    cout << "Maximum Score: " << sol.maxScore(cardPoints2, k2) << endl; // Expected: 248
    
    return 0;
}