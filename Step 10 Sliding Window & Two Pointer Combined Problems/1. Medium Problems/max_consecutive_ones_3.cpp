#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int zeros = 0, maxLen = 0;
        int n = nums.size();

        while (right < n) {
            if (nums[right] == 0) zeros++;

            while (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements (0s and 1s): ";
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << "Enter k: ";
    cin >> k;

    int result = sol.longestOnes(nums, k);
    cout << "Longest subarray length with at most " << k << " zeros: " << result << endl;

    return 0;
}
