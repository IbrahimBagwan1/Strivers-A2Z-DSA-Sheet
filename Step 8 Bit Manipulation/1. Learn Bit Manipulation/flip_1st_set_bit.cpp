#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int flipFirstSetBit(int n) {
      return (n & n-1);
    }
};

int main() {
    Solution sol;

    int n = 12; // binary: 1101
    cout<<n<<endl;
    n = sol.flipFirstSetBit(n);
    cout<<n<<endl;

    return 0;
}
