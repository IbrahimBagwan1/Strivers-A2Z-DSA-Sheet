#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    vector<int> temp(n);
    for (int i = 0; i < k; i++) {
      temp[i] = nums[n - k + i];
    }
    for (int i = 0; i < n - k; i++) {
      temp[k + i] = nums[i];
    }
    for (int i = 0; i < n; i++) {
      nums[i] = temp[i];
    }
  }
};

int main() {
  int n, k;
  cout << "Enter size of array: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter array elements: ";
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cout << "Enter k (number of rotations): ";
  cin >> k;

  Solution sol;
  sol.rotate(nums, k);

  cout << "Rotated array: ";
  for (int i = 0; i < n; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}