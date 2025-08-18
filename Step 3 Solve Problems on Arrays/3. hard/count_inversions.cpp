#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  long long int numberOfInversions(vector<int> nums) {
    long long int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] > nums[j]) count++;
      }
    }
    return count;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {8, 4, 2, 1};
  cout << "Number of inversions: " << sol.numberOfInversions(nums) << endl;
  return 0;
}