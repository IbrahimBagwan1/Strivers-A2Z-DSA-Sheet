#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& nums) {
    int maxprof=0;
    int n = nums.size();
    int mini =nums[0];

    for(int i=1; i<n; i++){
      int cost = nums[i] - mini;
      maxprof= max(cost, maxprof);
      
      mini = min(nums[i], mini);
    }
    return maxprof; 
  }
};

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  Solution sol;
  int profit = sol.maxProfit(prices);
  cout << "Maximum Profit: " << profit << endl;
  return 0;
}