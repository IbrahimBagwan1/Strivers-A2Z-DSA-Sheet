#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = nums1.size();
    priority_queue<tuple<int,int,int>> maxHeap;
    set<pair<int,int>> visited;

    sort(nums1.begin(), nums1.end(), greater<int>());
    sort(nums2.begin(), nums2.end(), greater<int>());

    int maxSum = nums1[0] + nums2[0];
    maxHeap.push({maxSum, 0, 0});  
    visited.insert({0,0});
    vector<int> sumCombinations;

    while(k-- && !maxHeap.empty()){
      auto [maxSum, i, j] = maxHeap.top();
      maxHeap.pop();
      sumCombinations.push_back(maxSum);

      if(i+1 < n && !visited.count({i+1,j})){
        maxSum = nums1[i+1] + nums2[j];
        maxHeap.push({maxSum, i+1, j});   
        visited.insert({i+1,j});
      }
      
      if(j+1 < n && !visited.count({i,j+1})){
        maxSum = nums1[i] + nums2[j+1];
        maxHeap.push({maxSum, i, j+1});  
        visited.insert({i,j+1});
      }
    }

    return sumCombinations;
  }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    vector<int> result = sol.maxSumCombinations(nums1, nums2, k);
    for(int val : result) cout << val << " ";
    return 0;
}