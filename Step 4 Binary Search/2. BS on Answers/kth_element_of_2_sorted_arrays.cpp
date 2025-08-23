#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
  int kthElement(vector<int> &nums1, vector<int>& nums2, int k) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    if(n1 > n2) return kthElement(nums2, nums1, k);

    int left = max(0, k - n2);
    int right = min(k, n1);

    while(left <= right) {
      int mid1 = left + (right - left) / 2;
      int mid2 = k - mid1;

      int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
      int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
      int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
      int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;

      if(l1 <= r2 && l2 <= r1) {
        return max(l1, l2);
      } else if(l1 > r2) {
        right = mid1 - 1;
      } else {
        left = mid1 + 1;
      }
    }
    return 0;
  }
};

int main() {
  Solution sol;
  vector<int> nums1 = {2, 3, 6, 7, 9};
  vector<int> nums2 = {1, 4, 8, 10};
  int k = 5;
  cout << "The " << k << "th element is: " << sol.kthElement(nums1, nums2, k) << endl;
  return 0;
}