#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int prefix = 1;
    int suffix = 1;
    int n = nums.size();
    if (n == 1) return nums[0];
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
      prefix *= nums[i];
      maxi = max(prefix, maxi);
      suffix *= nums[n - i - 1];
      maxi = max(suffix, maxi);
      if (nums[i] == 0) prefix = 1;
      if (nums[n - i - 1] == 0) suffix = 1;
    }
    return maxi;
  }
};

int main() {
  vector<int> nums = {2, 3, -2, 4};
  Solution sol;
  cout << "Maximum product subarray: " << sol.maxProduct(nums) << endl;
  return 0;
}