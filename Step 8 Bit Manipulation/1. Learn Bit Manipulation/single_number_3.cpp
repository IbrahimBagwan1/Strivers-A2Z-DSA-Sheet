#include <bits/stdc++.h>
using namespace std;

class Solution {	
public:		
    vector<int> singleNumber(vector<int>& nums) {
        int totalXor = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalXor ^= nums[i];
        }

        // Isolate the rightmost set bit
        int firstSetBit = totalXor & -totalXor;

        int xor1 = 0, xor2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & firstSetBit) {
                xor1 ^= nums[i];
            } else {
                xor2 ^= nums[i];
            }
        }

        vector<int> ans = {xor1, xor2};
        sort(ans.begin(), ans.end());  // keep result sorted
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 1, 3, 2, 5};  // Example input
    vector<int> result = sol.singleNumber(nums);

    cout << "Two unique numbers are: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
