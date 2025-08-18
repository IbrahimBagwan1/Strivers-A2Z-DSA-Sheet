#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int subarraysWithXorK(vector<int> &nums, int k) {
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
      int xorr = 0;
      for (int j = i; j < n; j++) {
        xorr ^= nums[j];
        if (xorr == k) count++;
      }
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