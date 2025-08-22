#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0;
    int right = n-1;

    while(left <= right){
      int mid = left + (right-left)/2;

      if(arr[mid]-(mid+1) < k){
        left = mid+1;
      }
      else{
        right = mid-1;
      }
    }
    return (right +1 +k);
  }
};

int main() {
  Solution sol;
  vector<int> arr = {2, 3, 4, 7, 11};
  int k = 5;
  cout << "The " << k << "th missing positive integer is: " << sol.findKthPositive(arr, k) << endl;
  return 0;
}