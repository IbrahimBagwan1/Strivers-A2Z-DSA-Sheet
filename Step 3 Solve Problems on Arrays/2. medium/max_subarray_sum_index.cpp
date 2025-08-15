#include<bits/stdc++.h>
using namespace std;

vector<int> maximum_sum(vector<int> &nums){
  int n = nums.size();
  int sum =0;
  int maxi = INT_MIN;
  vector<int> answer;
  int startans = 0, tempans=0, endans =0;
  
  for (int i = 0; i < n; i++){
    sum+=nums[i];
    if(sum > maxi){
      maxi = sum;
      startans = tempans;
      endans = i;
    }

    if(sum<0){
      sum=0;
      tempans = i+1;
    }
  } 

  for(int i=startans; i<=endans; i++){
    answer.push_back(nums[i]);
  }
  return answer;
}


int main(){
  vector<int> nums = {-2,-3,4,-1,-2,1,5,-3};
  cout<< "The Maximum Subarray sum is: ";
  vector<int> ans = maximum_sum(nums);
  for(auto ele: ans){
    cout<<ele<< " ";
  }
  return 0;
}