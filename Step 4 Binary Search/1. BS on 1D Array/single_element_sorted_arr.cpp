#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;

    while(left < right){
      int mid = left + (right - left) / 2;

      // ensure mid is even
      if(mid % 2 == 1) mid--;

      if(nums[mid] == nums[mid+1]){
        left = mid + 2;
      } else {
        right = mid;
      }
    }
    return nums[left];
  }
};

int main() {
  vector<int> nums = {1,1,2,2,3,4,4,5,5};
  Solution sol;
  cout << "Single non-duplicate element: " << sol.singleNonDuplicate(nums) << endl;
  return 0;
}