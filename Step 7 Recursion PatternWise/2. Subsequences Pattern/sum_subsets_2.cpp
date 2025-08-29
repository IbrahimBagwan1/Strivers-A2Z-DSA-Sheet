#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helperSubsetsSums(vector<int> &nums, vector<int> &temp, int n , int idx, vector<vector<int>> &ans){
        ans.push_back(temp);
        for(int i=idx; i<n; i++){
            if(i!=idx && nums[i]==nums[i-1]) continue; 
            temp.push_back(nums[i]);
            helperSubsetsSums(nums, temp, n, i+1 , ans); // FIXED (i+1)
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        helperSubsetsSums(nums, temp, n, 0, ans);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1,2,2}; // Example input
    vector<vector<int>> result = obj.subsetsWithDup(nums);

    cout << "Subsets:\n";
    for(auto &subset : result){
        cout << "[ ";
        for(int x : subset) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
