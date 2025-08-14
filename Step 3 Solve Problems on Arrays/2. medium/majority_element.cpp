#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int el = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); i++) {
      if (count == 0) el = nums[i];

      if (nums[i] == el) count++;
      else count--;
    }
    return el;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  cout << "Majority Element: " << sol.majorityElement(nums) << endl;
  return 0;
}