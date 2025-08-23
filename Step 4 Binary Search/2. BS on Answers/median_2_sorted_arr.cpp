#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

    int n = n1 + n2;
    int left = 0, right = n1;
    int left_over = (n1 + n2 + 1) / 2;

    while(left <= right) {
      int mid1 = left + (right - left) / 2;
      int mid2 = left_over - mid1;
      int l1 = INT_MIN, l2 = INT_MIN;
      int r1 = INT_MAX, r2 = INT_MAX;
      if(mid1 < n1) r1 = nums1[mid1];
      if(mid2 < n2) r2 = nums2[mid2];
      if(mid1 > 0) l1 = nums1[mid1 - 1];
      if(mid2 > 0) l2 = nums2[mid2 - 1];

      if(l1 <= r2 && l2 <= r1) {
        if(n % 2 == 1) return max(l1, l2);
        return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
      }
      else if(l1 > r2) right = mid1 - 1;
      else left = mid1 + 1;
    }
    return 0;
  }
};

int main() {
  Solution sol;
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};
  cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

  nums1 = {1, 2};
  nums2 = {3, 4};
  cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

  return 0;
}