#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
      sum += nums[i];
    }
    int fullSum = (n * (n + 1)) / 2;
    return fullSum - sum;
  }
};

int main() {
  vector<int> nums = {3, 0, 1}; // Example input
  Solution sol;
  int missing = sol.missingNumber(nums);
  cout << "Missing number is: " << missing << endl;
  return 0;
}