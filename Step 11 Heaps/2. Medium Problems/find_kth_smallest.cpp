#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> ans; // min-heap
        for(int x: nums) ans.push(x);

        int kSmall = INT_MAX;
        for(int i = 0; i < k; i++) {
            kSmall = ans.top();
            ans.pop();
        }
        return kSmall;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {7, 10, 4, 3, 20, 15};
    int k1 = 3;
    cout << k1 << "rd smallest element is: " << sol.findKthSmallest(nums1, k1) << endl;

    vector<int> nums2 = {3, 2, 1, 5, 6, 4};
    int k2 = 4;
    cout << k2 << "th smallest element is: " << sol.findKthSmallest(nums2, k2) << endl;

    return 0;
}
