#include <iostream>
using namespace std;

class Solution {
public:
  int GCD(int n1, int n2) {
    int r = 0;
    while (n2 != 0) {
      r = n1 % n2;
      n1 = n2;
      n2 = r;
    }
    return n1;
  }
};

int main() {
  Solution sol;
  int a, b;
  cout << "Enter two numbers: ";
  cin >> a >> b;
  int result = sol.GCD(a, b);
  cout << "GCD of " << a << " and " << b << " is " << result << endl;
  return 0;
}