// LeetCode 1752
#include <vector>
using namespace std;

class Solution {
public:
  bool check(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for (int i=0; i<2*n; i++){
      if(nums[i%n] <= nums[i+1 %n]) count++;
      else count =1;
      if(count==n) return true;
    }
    return n==1;  
  }
};

// Example usage
#include <iostream>
int main() {
  Solution sol;
  vector<int> nums = {3, 4, 5, 1, 2};
  cout << (sol.check(nums) ? "true" : "false") << endl;
  return 0;
}