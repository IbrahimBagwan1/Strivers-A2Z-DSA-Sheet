#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++){
      if(i>0 && nums[i]==nums[i-1]) continue;
      for(int j=i+1; j<n; j++){
        if(j!=i+1 && nums[j]==nums[j-1]) continue;
        int k = j+1;
        int l = n-1;
        
        while(k<l){
          long long sum = nums[i];
          sum+= nums[j];
          sum+= nums[k];
          sum+= nums[l];

          if(sum == target){
            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
            ans.push_back(temp);
            k++;
            l--;

            while(k<l && nums[k] == nums[k-1]) k++;
            while(k<l && nums[l] == nums[l+1]) l--;
          }
          else if(sum > target){
            l--;
          }
          else{
            k++;
          }
        }
      }
    }     
    return ans;   
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  int target = 0;
  vector<vector<int>> result = sol.fourSum(nums, target);

  for(const auto& quad : result) {
    for(int num : quad) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}