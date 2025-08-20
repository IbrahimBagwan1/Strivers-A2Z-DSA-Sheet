#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int countOccurrences(const vector<int>& arr, int target) {
    int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    return ub - lb;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
  int target = 2;
  cout << "Count of " << target << " is: " << sol.countOccurrences(arr, target) << endl;
  return 0;
}