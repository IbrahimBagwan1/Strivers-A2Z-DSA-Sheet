#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helperSubarraysWithDistinct(vector<int>& nums, int k){
        int n = nums.size();
        int left=0; 
        int right=0;
        int maxCount=0;
        map<int,int> mp;

        while(right<n){
            mp[nums[right]]++;
            
            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }

            maxCount += (right-left+1);
            right++;
        }
        return maxCount;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helperSubarraysWithDistinct(nums, k) - helperSubarraysWithDistinct(nums, k-1); 
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,2,1,2,3};
    int k = 2;

    cout << "Number of subarrays with exactly " << k 
         << " distinct integers: " 
         << sol.subarraysWithKDistinct(nums, k) << endl;

    return 0;
}
