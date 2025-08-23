#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
  int maximum_sum(vector<int>& arr, int n) {
    int sumi = 0;
    for (int i = 0; i < n; i++) {
      sumi += arr[i];
    }
    return sumi;
  }

  int minimum(vector<int>& arr, int n) {
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
      mini = min(mini, arr[i]);
    }
    return mini;
  }

  bool check_subarray(vector<int>& nums, int m, int capacity) {
    int cnt = 1, sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > capacity) return false;
      if (sum + nums[i] > capacity) {
        cnt++;
        sum = nums[i];
        if (cnt > m) return false;
      } else {
        sum += nums[i];
      }
    }
    return true;
  }

  int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    if (k > n) return -1;
    int left = minimum(nums, n);
    int right = maximum_sum(nums, n);
    int final_ans = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (check_subarray(nums, k, mid)) {
        final_ans = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }    
    return final_ans;
  }
};

int main() {
  int n, k;
  cout << "Enter number of elements and k: ";
  cin >> n >> k;
  vector<int> nums(n);
  cout << "Enter array elements: ";
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  Solution sol;
  int result = sol.splitArray(nums, k);
  cout << "Minimum largest sum after splitting: " << result << endl;
  return 0;
}