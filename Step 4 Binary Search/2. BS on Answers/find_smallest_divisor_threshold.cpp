#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
  int maximum(vector<int>& bloomDay, int n) {
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
      maxi = max(bloomDay[i], maxi);
    }
    return maxi;
  }

  int divisor_check(vector<int>& nums, int div){
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
      sum += ceil(double(nums[i]) / double(div));
    }
    return sum;
  }

  int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    int right = maximum(nums, n);
    int left = 1;
    int ans = -1;
    while(left <= right){
      int mid = left + (right - left) / 2;
      if(divisor_check(nums, mid) <= threshold){
        ans = mid;
        right = mid - 1;
      }
      else{
        left = mid + 1;
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 2, 5, 9};
  int threshold = 6;
  Solution sol;
  int result = sol.smallestDivisor(nums, threshold);
  cout << "Smallest Divisor: " << result << endl;
  return 0;
}