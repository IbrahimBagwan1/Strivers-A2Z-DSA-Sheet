#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        int maxIdx = 0;
        for (int i = 0; i < n - 1; i++) {
            int canGo = i + nums[i];

            if (nums[i] == 0 && i >= maxIdx) return false;

            if (maxIdx < canGo) {
                maxIdx = canGo;
            }
        }

        return maxIdx >= n - 1;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    cout << "Test case 1: " << (obj.canJump(nums1) ? "true" : "false") << endl;
    cout << "Test case 2: " << (obj.canJump(nums2) ? "true" : "false") << endl;

    return 0;
}
