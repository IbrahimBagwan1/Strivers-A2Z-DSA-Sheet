#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
  int maximum(vector<int>& arr, int n) {
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
      maxi = max(maxi, arr[i]);
    }
    return maxi;
  }

  bool check_time(vector<int>& C, int A, int B, int time){
    int count = 0;
    int painters = 1;
    for(int i = 0; i < C.size(); i++){
      if(C[i] * B > time) return false;
      if(count + C[i] * B > time){
        painters++;
        count = C[i] * B;
        if(painters > A) return false;
      } else {
        count += C[i] * B;
      }
    }
    return true;
  }

  int paint(int A, int B, vector<int>& C) {
    int n = C.size();
    int left = maximum(C, n) * B;
    int right = 0;
    for(int i = 0; i < n; i++) right += C[i] * B;
    int final_ans = right;

    while(left <= right){
      int mid = left + (right - left) / 2;
      if(check_time(C, A, B, mid)){
        final_ans = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return final_ans % 10000003;
  }
};

int main() {
  int A, B, n;
  cout << "Enter number of painters (A), time per unit (B), and number of boards (n): ";
  cin >> A >> B >> n;
  vector<int> C(n);
  cout << "Enter board lengths:\n";
  for(int i = 0; i < n; i++) {
    cin >> C[i];
  }
  Solution sol;
  int result = sol.paint(A, B, C);
  cout << "Minimum time to paint all boards: " << result << endl;
  return 0;
}