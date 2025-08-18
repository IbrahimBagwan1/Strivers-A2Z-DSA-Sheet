#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int dup = -1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == nums[i + 1]) dup = nums[i];
      sum += nums[i];
    }
    sum -= dup;

    int totalSum = n * (n + 1) / 2;
    return {dup, (totalSum - sum)};
  }
};

int main() {
  Solution sol;
  vector<int> nums = {4, 3, 6, 2, 1, 1};
  vector<int> result = sol.findMissingRepeatingNumbers(nums);
  cout << "Repeating: " << result[0] << ", Missing: " << result[1] << endl;
  return 0;
}