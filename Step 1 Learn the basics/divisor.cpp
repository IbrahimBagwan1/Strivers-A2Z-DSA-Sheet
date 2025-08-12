#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> divisors(int n) {
    vector<int> li;
    for(int i = 1; i <= n; i++) {
      if(n % i == 0) li.push_back(i);
    }
    return li;
  }
};

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;
  Solution sol;
  vector<int> result = sol.divisors(n);
  cout << "Divisors of " << n << " are: ";
  for(int d : result) {
    cout << d << " ";
  }
  cout << endl;
  return 0;
}