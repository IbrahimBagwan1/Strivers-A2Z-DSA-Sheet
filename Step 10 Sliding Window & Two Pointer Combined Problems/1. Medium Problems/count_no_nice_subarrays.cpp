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
            sum += nums[r] % 2;   // ✅ counts odds
            while(sum > goal){
                sum -= nums[l] % 2;
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helpernumSubarraysWithSum(nums, k) - helpernumSubarraysWithSum(nums, k-1); 
    }
};

int main() {
    Solution sol;

    // Hardcoded test
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    int ans = sol.numberOfSubarrays(nums, k);
    cout << "Result: " << ans << endl;  // Expected: 2

    return 0;
}
