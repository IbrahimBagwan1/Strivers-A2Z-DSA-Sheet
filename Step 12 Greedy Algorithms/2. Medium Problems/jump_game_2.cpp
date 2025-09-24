#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int jumps = 0;

        while (right < n - 1) {
            int farthest = 0;
            for (int i = left; i <= right; i++) {
                farthest = max(farthest, nums[i] + i);
            }

            left = right + 1;
            right = farthest;
            jumps++;
        }
        return jumps;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {2, 3, 1, 1, 4};  
    vector<int> nums2 = {2, 3, 0, 1, 4};

    cout << "Minimum jumps (test case 1): " << obj.jump(nums1) << endl;
    cout << "Minimum jumps (test case 2): " << obj.jump(nums2) << endl;

    return 0;
}
