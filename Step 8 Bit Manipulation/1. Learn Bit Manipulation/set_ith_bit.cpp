#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int setBit(int n, int i) {
      int ith = 1;
      ith = ith<< i;
      return (n | (ith));
    }
};

int main() {
    Solution sol;

    int n = 13; // binary: 1101
    cout<<n<<endl;
    n = sol.setBit(n, 1);
    cout<<n<<endl;

    return 0;
}
