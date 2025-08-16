#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums, int target) {
    int count =0;
    int n = nums.size();
    int sum =0;
    map<int,int> mp;
    
    mp[0]=1;    

    for(int i=0; i<n; i++){
      sum += nums[i];
      int k=sum - target ;
      count+= mp[k];            
      mp[sum]++;
    }
    return count;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, -2, 2, 1};
  int target = 3;
  Solution sol;
  cout << sol.subarraySum(nums, target) << endl;
  return 0;
}