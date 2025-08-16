#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int n) {
    vector<vector<int>> ans;

    for(int i=0; i<n; i++){
      vector<int> a(i+1,1);
      ans.push_back(a);
      for(int j=1; j<i; j++){
        ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
      }
    }
    return ans;
  }
};

int main() {
  int n;
  cout << "Enter number of rows for Pascal's Triangle: ";
  cin >> n;

  Solution sol;
  vector<vector<int>> triangle = sol.generate(n);

  for(const auto& row : triangle) {
    for(int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}