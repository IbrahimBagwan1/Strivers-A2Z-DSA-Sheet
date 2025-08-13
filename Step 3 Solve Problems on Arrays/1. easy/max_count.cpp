#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int maxCount = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] == 1) {
        count++;
        maxCount = max(count, maxCount);
      } else {
        count = 0;
      }
    }
    return maxCount;
  }
};

int main() {
  vector<int> nums;
  int n, val;
  cout << "Enter number of elements: ";
  cin >> n;
  cout << "Enter elements (0 or 1): ";
  for (int i = 0; i < n; ++i) {
    cin >> val;
    nums.push_back(val);
  }

  Solution sol;
  int result = sol.findMaxConsecutiveOnes(nums);
  cout << "Maximum consecutive ones: " << result << endl;
  return 0;
}