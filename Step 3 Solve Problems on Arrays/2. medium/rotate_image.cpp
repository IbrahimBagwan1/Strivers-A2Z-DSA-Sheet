#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& nums) {
    int n= nums.size();

    // step 1; do the transpose
    for(int i =0; i<n; i++){
      for(int j=i+1; j<n; j++){
        if(i==j) continue;
        else {
          int temp = nums[i][j];
          nums[i][j] = nums[j][i];
          nums[j][i] = temp;
        }
      }
    }

    // step 2; do the reverse of the rows
    for(int i=0; i<n; i++){
      reverse(nums[i].begin(), nums[i].end());
    }
  }
};

int main() {
  vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  Solution sol;
  sol.rotate(matrix);

  cout << "Rotated Matrix:" << endl;
  for(const auto& row : matrix) {
    for(int val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
  return 0;
}