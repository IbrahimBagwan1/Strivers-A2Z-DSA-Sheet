#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n-1;
    int ans = -1;
    while(left<=right){
      int mid = left + (right-left)/2;
      if(nums[mid]==target) {
        return mid;
      }
      else if(nums[left]== nums[mid] && nums[mid]==nums[right]){
        left++;
        right--;
      }
      else if(nums[left] <= nums[mid]){
        if(nums[left] <= target && target <= nums[mid]){
          right = mid-1;
        }
        else{
          left = mid+1;
        }
      }
      else if(nums[mid] <= nums[right]){
        if(nums[mid] <= target && target<= nums[right]){
          left = mid+1;
        }
        else{
          right = mid-1;
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {4,5,6,7,0,1,2};
  int target = 0;
  int index = sol.search(nums, target);
  cout << "Index of target " << target << " is: " << index << endl;
  return 0;
}