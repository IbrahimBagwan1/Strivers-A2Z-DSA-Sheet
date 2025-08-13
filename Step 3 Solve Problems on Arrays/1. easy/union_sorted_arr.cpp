#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n1 && j < n2) {
      if (nums1[i] <= nums2[j]) {
        if (ans.size() == 0 || ans.back() != nums1[i]) {
          ans.push_back(nums1[i]);
        }
        i++;
      } else {
        if (ans.size() == 0 || ans.back() != nums2[j]) {
          ans.push_back(nums2[j]);
        }
        j++;
      }
    }

    while (i < n1) {
      if (ans.size() == 0 || ans.back() != nums1[i]) {
        ans.push_back(nums1[i]);
      }
      i++;
    }
    while (j < n2) {
      if (ans.size() == 0 || ans.back() != nums2[j]) {
        ans.push_back(nums2[j]);
      }
      j++;
    }
    return ans;
  }
};

int main() {
  vector<int> nums1 = {1, 2, 4, 5, 6};
  vector<int> nums2 = {2, 3, 5, 7};
  Solution sol;
  vector<int> result = sol.unionArray(nums1, nums2);

  cout << "Union of sorted arrays: ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}