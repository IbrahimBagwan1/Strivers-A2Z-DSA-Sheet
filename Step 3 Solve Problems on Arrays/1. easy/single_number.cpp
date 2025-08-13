#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int xorr = 0;
    for (int num : nums) {
      xorr ^= num;
    }
    return xorr;
  }
};

int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elements: ";
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  Solution sol;
  int result = sol.singleNumber(nums);
  cout << "The single number is: " << result << endl;
  return 0;
}