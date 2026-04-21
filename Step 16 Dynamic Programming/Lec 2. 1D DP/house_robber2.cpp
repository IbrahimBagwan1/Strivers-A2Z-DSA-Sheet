#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // This helper logic handles a linear range of houses
    int linearRob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int prev = nums[0];
        int beforeprev = 0;

        for (int i = 1; i < n; i++) {
            int pick = nums[i] + beforeprev;
            int notPick = prev;
            int result = max(pick, notPick);
            
            beforeprev = prev;
            prev = result;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Essential edge case for circular logic
        if (n == 0) return 0;

        // Create two sub-problems
        vector<int> firstRemoved, lastRemoved;
        for (int i = 0; i < n; i++) {
            if (i != 0) firstRemoved.push_back(nums[i]);
            if (i != n - 1) lastRemoved.push_back(nums[i]);
        }

        return max(linearRob(firstRemoved), linearRob(lastRemoved));
    }
};

int main() {
    Solution sol;

    // Test Case 1: Circular houses [2, 3, 2]
    // You can't rob house 1 and 3 together. Max is 3.
    vector<int> case1 = {2, 3, 2};
    cout << "Test Case 1 {2, 3, 2}: " << sol.rob(case1) << " (Expected: 3)" << endl;

    // Test Case 2: [1, 2, 3, 1]
    // Max is 4 (Rob house 1 & 3 OR 2 & 4)
    vector<int> case2 = {1, 2, 3, 1};
    cout << "Test Case 2 {1, 2, 3, 1}: " << sol.rob(case2) << " (Expected: 4)" << endl;

    // Test Case 3: [1, 2, 3]
    // Max is 3
    vector<int> case3 = {1, 2, 3};
    cout << "Test Case 3 {1, 2, 3}: " << sol.rob(case3) << " (Expected: 3)" << endl;

    return 0;
}