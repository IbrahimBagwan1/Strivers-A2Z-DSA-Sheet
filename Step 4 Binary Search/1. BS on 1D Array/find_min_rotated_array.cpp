#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    int left = 0; 
    int right = n-1;
    int mini = INT_MAX;
    while(left <= right){
      int mid = left + (right - left)/2;
      if(nums[mid] < mini) mini = nums[mid];  
      if(nums[left] <= nums[mid] && nums[mid] <= nums[right]){
        mini = min(nums[left], mini);
        return mini;
      }
      else if(nums[left] <= nums[mid]){
        left = mid+1;
      }
      else if(nums[mid] <= nums[right]){
        right = mid-1;
      }
    }
    return mini;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  cout << "Minimum element in rotated array: " << sol.findMin(nums) << endl;
  return 0;
}