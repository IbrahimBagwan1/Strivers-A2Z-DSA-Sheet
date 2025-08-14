#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums, int k) {
    int n = nums.size();
    int right = 0;
    int left = 0;
    int sum = nums[0];
    int maxLen = 0;

    while (right < n) {
      while (sum > k && left <= right) {
        sum -= nums[left];
        left++;
      }
      if (sum == k) {
        maxLen = max(maxLen, right - left + 1);
      }
      right++;
      if (right < n) {
        sum += nums[right];
      }
    }

    return maxLen;
  }
};

int main() {
  int n, k;
  cout << "Enter number of elements and target sum k: ";
  cin >> n >> k;
  vector<int> nums(n);
  cout << "Enter array elements: ";
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  Solution sol;
  int result = sol.longestSubarray(nums, k);
  cout << "Length of longest subarray with sum " << k << " is: " << result << endl;
  return 0;
}