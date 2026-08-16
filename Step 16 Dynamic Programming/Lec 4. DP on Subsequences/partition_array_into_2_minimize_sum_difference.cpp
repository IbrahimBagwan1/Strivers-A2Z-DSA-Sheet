#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<vector<int>> left(n + 1);
        vector<vector<int>> right(n + 1);

        // Generate all subsets
        for (int mask = 0; mask < (1 << n); mask++) {
            int sumL = 0;
            int sumR = 0;
            int cntL = 0;
            int cntR = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sumL += nums[i];
                    cntL++;
                    sumR += nums[n + i];
                    cntR++;
                } else {
                    sumL -= nums[i];
                    sumR -= nums[n + i];
                }
            }
            left[cntL].push_back(sumL);
            right[cntR].push_back(sumR);
        }

        // Sort right side
        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int answer = INT_MAX;

        // Try every possible number of elements from left
        for (int i = 0; i <= n; i++) {
            // i elements from left
            // n-i elements from right
            for (int x : left[i]) {
                int target = -x;
                auto it = lower_bound(
                    right[n - i].begin(),
                    right[n - i].end(),
                    target
                );
                // Candidate 1
                if (it != right[n - i].end()) {
                    answer = min(answer, abs(x + *it));
                }
                // Candidate 2
                if (it != right[n - i].begin()) {
                    --it;
                    answer = min(answer, abs(x + *it));
                }
            }
        }
        return answer;
    }
};

int main() {

    Solution sol;

    // Example 1
    vector<int> nums = {3, 9, 7, 3};

    int answer = sol.minimumDifference(nums);

    cout << "Minimum difference = " << answer << endl;

    return 0;
}