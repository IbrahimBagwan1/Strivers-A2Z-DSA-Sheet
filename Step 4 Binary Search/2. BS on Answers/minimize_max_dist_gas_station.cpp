#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int number_gas_station(vector<int> &arr, long double dist) {
    int stations = 0;
    for (int i = 1; i < arr.size(); i++) {
      long double segment = arr[i] - arr[i - 1];
      stations += int(segment / dist);
    }
    return stations;
  } 

  long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    long double left = 0, right = 0;
    for (int i = 0; i < n - 1; i++)
      right = max(right, (long double)(arr[i + 1] - arr[i]));

    long double diff = 1e-6;
    while (right - left > diff) {
      long double mid = left + (right - left) / 2.0;
      int count = number_gas_station(arr, mid);
      if (count > k)
        left = mid;
      else
        right = mid;
    }
    return right;
  }
};

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6 ,7, 8, 9, 10}; // Example input
  int k = 1; // Number of additional stations

  Solution sol;
  cout << fixed;
  cout.precision(6);
  cout << sol.minimiseMaxDistance(arr, k) << endl;

  return 0;
}