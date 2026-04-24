#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:

    bool helpRecursiveIsSubsetSum(vector<int> &arr, int idx, int target, vector<vector<int>> & dp){
        if(target == 0) return true;

        if(idx == 0) return (arr[0] == target);

        if(dp[idx][target] != -1) return dp[idx][target];

        bool notTake = helpRecursiveIsSubsetSum(arr, idx-1, target, dp);

        bool take = false;
        if(arr[idx] <= target) 
            take = helpRecursiveIsSubsetSum(arr, idx-1, target - arr[idx], dp);

        return dp[idx][target] = (notTake || take);        
    }

    bool isSubsetSum(vector<int> arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return helpRecursiveIsSubsetSum(arr, n-1, target, dp);
    }
};

int main(){
    Solution obj;

    vector<int> arr = {1, 2, 3, 4};
    int target = 5;

    if(obj.isSubsetSum(arr, target))
        cout << "Subset with given sum exists";
    else
        cout << "Subset with given sum does not exist";

    return 0;
}