#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helperSubsetsSums(vector<int> &nums, vector<int> &ans, int n , int idx, int sum){
        if(idx == n){
            ans.push_back(sum);
            return;
        }
        sum += nums[idx];
        helperSubsetsSums(nums, ans, n, idx+1, sum);
        sum -= nums[idx];
        helperSubsetsSums(nums, ans, n, idx+1, sum);
    }

    vector<int> subsetSums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        helperSubsetsSums(nums, ans, n, 0, 0);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3}; // Example input
    vector<int> result = obj.subsetSums(nums);

    cout << "Subset sums: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
