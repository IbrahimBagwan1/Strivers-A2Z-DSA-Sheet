#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
  public:
    int maxLen(vector<int>& nums) {
      int n = nums.size();
      int sum = 0, maxi = 0;
      map<int, int> mp;
      for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (sum == 0) {
          maxi = i + 1;
        } else {
          if (mp.find(sum) != mp.end()) {
            maxi = max(maxi, i - mp[sum]);
          } else {
            mp[sum] = i;
          }
        }
      }
      return maxi;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    Solution sol;
    int result = sol.maxLen(nums);
    cout << "Length of largest subarray with sum 0: " << result << endl;
    return 0;
}