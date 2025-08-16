#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end()); 
    int n= nums.size();
    vector<vector<int>> ans;
    int i=0, j=1,k=n-1;
    for(i=0; i<n; i++){
      if(i>0 && nums[i] == nums[i-1]) continue;
      j=i+1;
      k=n-1;
      while(j<k){
        int sum = nums[i] + nums[j] + nums[k];
        if(sum == 0){
          vector<int> temp={nums[i], nums[j], nums[k]};
          ans.push_back(temp);
          j++;
          k--;
          while(j<k && nums[j]==nums[j-1]) j++;
          while(j<k && nums[k]==nums[k+1]) k--;
        } 
        if(sum > 0){
          k--;
        }
        else if( sum < 0){
          j++;
        }
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  Solution sol;
  vector<vector<int>> result = sol.threeSum(nums);
  for(const auto& triplet : result) {
    for(int num : triplet) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}