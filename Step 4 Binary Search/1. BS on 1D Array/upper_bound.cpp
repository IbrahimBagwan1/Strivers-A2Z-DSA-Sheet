#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int upperbound(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    int ans  = right;
    while(left <= right) {
      mid = left + (right - left) / 2;
      if(nums[mid] > target){
        ans = mid;
        right = mid-1; 
      }
      else{
        left = mid+1;
      }
    }
    return ans;
  }

};

int main() {
  vector<int> nums = {1, 3, 5, 7, 9, 11};
  int target = 6;

  Solution sol;
  int index = sol.upperbound(nums, target);

  if(index != -1) {
    cout << "Target found at index: " << index << endl;
  } else {
    cout << "Target not found." << endl;
  }

  return 0;
}