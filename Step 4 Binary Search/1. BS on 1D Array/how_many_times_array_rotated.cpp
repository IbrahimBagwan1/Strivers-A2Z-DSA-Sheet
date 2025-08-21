#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
  int findKRotation(vector<int> &nums)  {
    int n = nums.size();
    if(n == 1) return 0;
    int left = 0, right = n - 1;
    int mini = INT_MAX;
    int idx = -1;
    while(left <= right){
      int mid = left + (right - left) / 2;
      if(nums[mid] < mini){
        mini = nums[mid];
        idx = mid;
      }
      if(nums[left] <= nums[mid] && nums[mid] <= nums[right]){
        if(nums[left] < mini){
          mini = nums[left];
          idx = left;
        }
        break;
      }
      else if(nums[left] <= nums[mid]){
        left = mid + 1;
      }
      else if(nums[mid] <= nums[right]){
        right = mid - 1;
      }
    }
    return idx;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  cout << "Enter array elements: ";
  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    nums.push_back(x);
  }
  int rotations = sol.findKRotation(nums);
  cout << "Array is rotated " << rotations << " times." << endl;
  return 0;
}