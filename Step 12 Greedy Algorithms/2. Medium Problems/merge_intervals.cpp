#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        // Sort intervals by start time
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            int currentLast = ans.back()[1];
            int first = nums[i][0];
            int second = nums[i][1];

            if (first <= currentLast && second >= currentLast) {
                // Overlapping: extend the last interval
                ans.back()[1] = second;
            } 
            else if (first <= currentLast && second <= currentLast) {
                // Fully covered: skip this interval
                continue;
            } 
            else {
                // No overlap: add new interval
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> nums(n, vector<int>(2));
    cout << "Enter intervals (start end):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0] >> nums[i][1];
    }

    vector<vector<int>> result = s.merge(nums);

    cout << "Merged intervals: ";
    for (auto &interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
