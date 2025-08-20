#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    return lb;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 3, 5, 6};
  int target = 5;
  cout << "Insert position for " << target << " is: " << sol.searchInsert(nums, target) << endl;

  target = 2;
  cout << "Insert position for " << target << " is: " << sol.searchInsert(nums, target) << endl;

  target = 7;
  cout << "Insert position for " << target << " is: " << sol.searchInsert(nums, target) << endl;

  return 0;
}