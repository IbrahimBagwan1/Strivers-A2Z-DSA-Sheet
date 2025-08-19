#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right) {
      int mid = left + (right - left) / 2;

      if(nums[mid] == target) {
        return mid; // target found
      } else if(nums[mid] < target) {
        left = mid + 1; // move right
      } else {
        right = mid - 1; // move left
      }
    }

    return -1; // target not found
  }
};

int main() {
  vector<int> nums = {1, 3, 5, 7, 9, 11};
  int target = 7;

  Solution sol;
  int index = sol.search(nums, target);

  if(index != -1) {
    cout << "Target found at index: " << index << endl;
  } else {
    cout << "Target not found." << endl;
  }

  return 0;
}