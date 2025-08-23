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

  bool check_pages(vector<int>& nums, int m, int pages) {
    int cnt = 1, sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > pages) return false;
      if (sum + nums[i] > pages) {
        cnt++;
        sum = nums[i];
        if (cnt > m) return false;
      } else {
        sum += nums[i];
      }
    }
    return true;
  }

  int findPages(vector<int>& nums, int m) {
    int n = nums.size();
    if (m > n) return -1;
    int left = minimum(nums, n);
    int right = maximum_sum(nums, n);
    int final_ans = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (check_pages(nums, m, mid)) {
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
  vector<int> books = {25, 46, 28, 49, 24};
  int students = 4;
  Solution sol;
  int result = sol.findPages(books, students);
  cout << "Minimum number of pages: " << result << endl;
  return 0;
}