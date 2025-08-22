#include <iostream>
#include <vector>
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
  int maximum_sum(vector<int>& bloomDay, int n) {
    int sumi = 0;
    for (int i = 0; i < n; i++) {
      sumi += bloomDay[i];
    }
    return sumi;
  }

  int capacity_check(vector<int>& weights, int capacity){
    int count = 0;
    int days = 1;
    for(int i = 0; i < weights.size(); i++){
      if(count + weights[i] > capacity){
        days++;
        count = weights[i];
      }
      else{
        count += weights[i];
      }
    }
    return days;
  }

  int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int left = maximum(weights, n);
    int right = maximum_sum(weights, n);
    int ans = right;

    while(left <= right){
      int mid = left + (right - left) / 2;
      int cal_day = capacity_check(weights, mid);
      if(cal_day <= days){
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
  Solution sol;
  vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
  int days = 5;
  int result = sol.shipWithinDays(weights, days);
  cout << "Minimum capacity to ship packages within " << days << " days: " << result << endl;
  return 0;
}