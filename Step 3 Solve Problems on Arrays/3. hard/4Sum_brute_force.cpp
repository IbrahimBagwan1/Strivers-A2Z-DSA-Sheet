#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0; i<n-3; i++){
      for(int j=i+1; j<n-2; j++){
        for(int k=j+1; k<n-1; k++){
          for(int l=k+1; l<n; l++){
            long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];
            if(sum == target){
              vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
              sort(temp.begin() , temp.end());
              st.insert(temp);
            }
          }
        }
      }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
  }
};

int main() {
  vector<int> nums = {
            2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
  int target = 8;
  Solution sol;
  vector<vector<int>> result = sol.fourSum(nums, target);
  for(const auto& quad : result) {
    for(int num : quad) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}