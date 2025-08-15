#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      int i=0;
      int n=nums.size();
      vector<int> ans(n);
      int j=0;
      int k=1;
      for(int i=0; i<n; i++){
          if(nums[i]>0){
              ans[j] = nums[i];
              j+=2;
          }
          else{
              ans[k] = nums[i];
              k+=2;
          }
      } 
      return ans;
    }
};
int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter the elements (equal number of positive and negative): ";
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  Solution sol;
  vector<int> result = sol.rearrangeArray(nums);

  cout << "Rearranged array: ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}