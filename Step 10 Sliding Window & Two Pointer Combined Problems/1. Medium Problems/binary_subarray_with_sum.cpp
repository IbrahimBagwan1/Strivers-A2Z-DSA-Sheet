#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helpernumSubarraysWithSum(vector<int>& nums, int goal){
        if(goal < 0) return 0;    
        int r = 0, l = 0; 
        int n = nums.size();
        int sum = 0, count = 0;

        while(r < n){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);  // ✅ corrected
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helpernumSubarraysWithSum(nums, goal) - helpernumSubarraysWithSum(nums, goal-1); 
    }
};

int main() {
    Solution sol;

    // Hardcoded test
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    int ans = sol.numSubarraysWithSum(nums, goal);
    cout << "Result: " << ans << endl;  // Expected: 4

    return 0;
}
