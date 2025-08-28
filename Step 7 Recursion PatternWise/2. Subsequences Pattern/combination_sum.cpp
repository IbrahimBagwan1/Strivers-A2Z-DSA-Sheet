#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> helperCombinationSum(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &temp, int idx, int n , int target){
        if (target == 0 || idx == n) { 
            if (target == 0) {
                ans.push_back(temp);
            }
            return ans;
        }
        if (candidates[idx] <= target) {
            temp.push_back(candidates[idx]);
            helperCombinationSum(ans, candidates, temp, idx, n, target - candidates[idx]);
            temp.pop_back();
        }

        helperCombinationSum(ans, candidates, temp, idx + 1, n, target);
        return ans;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        helperCombinationSum(ans, candidates, temp, 0, n, target);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << " are:\n";
    for (auto &comb : result) {
        cout << "[ ";
        for (auto num : comb) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
