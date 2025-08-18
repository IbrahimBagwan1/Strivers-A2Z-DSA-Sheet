#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
  int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> mp;
        int xorr=0;
        mp[xorr]++;
        for (int i = 0; i < n; i++) {
            xorr ^= nums[i];
            int x = xorr ^ k;
            count += mp[x];
            mp[xorr]++;
        }
        return count;
    }
};


int main() {
  vector<int> nums = {4, 2, 2, 6, 4};
  int k = 6;

  Solution sol;
  int result = sol.subarraysWithXorK(nums, k);
  cout << result << endl;
  return 0;
}