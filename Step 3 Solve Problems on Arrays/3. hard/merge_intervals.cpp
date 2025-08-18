#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    ans.push_back(nums[0]);

    for(int i=1; i<n; i++){
      int currentLast = ans.back()[1];
      int first = nums[i][0];
      int second = nums[i][1];
      
      if(first <= currentLast && second >=currentLast){
        ans.back()[1]= second;
      }
      else if(first <= currentLast && second <=currentLast){
        continue;
      }
      else{
        ans.push_back(nums[i]);
      }
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
  Solution sol;
  vector<vector<int>> merged = sol.merge(intervals);
  for(const auto& interval : merged) {
    cout << "[" << interval[0] << "," << interval[1] << "] ";
  }
  cout << endl;
  return 0;
}