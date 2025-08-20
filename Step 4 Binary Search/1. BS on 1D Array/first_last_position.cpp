#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (lb == n) return { -1, -1 };
    if (nums[lb] != target) return { -1, -1 };
    if (lb == n - 1) return { lb, lb };
    int ub = lb;
    while (ub < n - 1 && nums[ub] == nums[ub + 1]) {
      ub++;
    }
    return { lb, ub };
  }
};

int main() {
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 8;
  Solution sol;
  vector<int> res = sol.searchRange(nums, target);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}