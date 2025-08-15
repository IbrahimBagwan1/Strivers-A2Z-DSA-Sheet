#include<bits/stdc++.h>
using namespace std;

int maximum_sum(vector<int> &nums){
  int n = nums.size();
  int sum =0;
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++){
    sum+=nums[i];
    if(sum > maxi){
      maxi = sum;
    }

    if(sum<0){
      sum=0;
    }
    cout<<" Iteration "<<i<<" The Sum is: "<<sum<<endl;
  }
  return maxi;
}


int main(){
  vector<int> nums = {-2,-3,4,-1,-2,1,5,-3};
  cout<< "The Maximum Subarray sum is: "<<maximum_sum(nums);
  return 0;
}