#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int left = 0, ans = 1;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            // shrink window if ops exceed k
            while ((long long)nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 4};
    int k = 5;

    cout << "Max Frequency: " << sol.maxFrequency(nums, k) << endl;
    return 0;
}
