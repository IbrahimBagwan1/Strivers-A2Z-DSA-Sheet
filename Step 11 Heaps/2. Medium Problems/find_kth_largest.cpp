#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> ans; // max-heap
        for(int x: nums) ans.push(x);

        int k_max = INT_MIN;
        for(int i = 0; i < k; i++) {
            k_max = ans.top();
            ans.pop();
        }
        return k_max;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << k << "th largest element is: " << sol.findKthLargest(nums, k) << endl;

    vector<int> nums2 = {7, 10, 4, 3, 20, 15};
    k = 3;
    cout << k << "th largest element is: " << sol.findKthLargest(nums2, k) << endl;

    return 0;
}
