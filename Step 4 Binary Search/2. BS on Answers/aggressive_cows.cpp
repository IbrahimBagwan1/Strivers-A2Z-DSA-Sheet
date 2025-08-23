#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
  int maximum(vector<int>& arr, int n) {
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
      maxi = max(arr[i], maxi);
    }
    return maxi;
  }

  int find_md(vector<int> &arr, int k , int dist){
    int first = arr[0];
    int dup = k;
    k--;
    for(int i = 1; i < arr.size(); i++){
      if(arr[i] - first >= dist){
        k--;
        first = arr[i];
      }
    }
    return dup - k;
  }

  int aggressiveCows(vector<int> &arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = maximum(arr, n);
    int final_ans = 0;

    while(left <= right){
      int mid = left + (right - left) / 2;
      int ans = find_md(arr, k, mid); 
      if(ans >= k){
        final_ans = mid;
        left = mid + 1;
      }
      else{
        right = mid - 1;
      }
    }
    return final_ans;
  }
};

int main() {
  int n = 5, k = 2;
  vector<int> arr = {4, 2, 1, 3, 6};

  // Uncomment below to use custom input
  // cin >> n >> k;
  // arr.resize(n);
  // for(int i = 0; i < n; i++) {
  //   cin >> arr[i];
  // }

  Solution sol;
  cout << sol.aggressiveCows(arr, k) << endl;
  return 0;
}