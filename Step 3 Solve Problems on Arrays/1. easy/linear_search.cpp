#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int linearSearch(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] == target) return i;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {5, 3, 8, 4, 2};
  int target = 4;
  int index = sol.linearSearch(nums, target);
  if(index != -1) {
    cout << "Element found at index: " << index << endl;
  } else {
    cout << "Element not found." << endl;
  }
  return 0;
}