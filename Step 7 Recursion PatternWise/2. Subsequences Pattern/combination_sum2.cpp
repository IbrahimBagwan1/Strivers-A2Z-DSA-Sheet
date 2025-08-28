#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> helperCombination(vector<vector<int>> &ans, vector<int>& candidates, vector<int> &temp, int idx, int n ,  int target, int currentSum) {
        if(idx == n){
            if(currentSum == target){
                ans.push_back(temp);
            }
            return ans;
        }
        currentSum += candidates[idx];
        temp.push_back(currentSum);
        helperCombination(ans, candidates, temp, idx+1, n, target, currentSum);
        
        temp.pop_back();
        currentSum -= candidates[idx];
        helperCombination(ans, candidates, temp, idx+1, n, target, currentSum);
        return ans;
    
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        ans = helperCombination(ans, candidates, temp, 0, n, target, 0);
        return ans;
    }
};