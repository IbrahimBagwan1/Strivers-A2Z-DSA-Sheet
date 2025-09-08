#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n  = nums.size();
        vector<vector<int>> ans;
        int subsets = 1 << n; // total number of subsets = 2^n

        for (int i = 0; i < subsets; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {  // check if j-th bit is set
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};  // example input
    vector<vector<int>> result = sol.subsets(nums);

    cout << "All subsets:\n";
    for (auto& subset : result) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}\n";
    }

    return 0;
}
