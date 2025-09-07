#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIthBit(int n, int i) {
        return (n >> i) & 1;   // check if i-th bit is set
    }
};

int main() {
    Solution sol;

    int n = 13; // binary: 1101
    cout << "Number: " << n << " (binary 1101)\n";

    for (int i = 0; i < 4; i++) {
        cout << "Bit " << i << ": " 
             << (sol.checkIthBit(n, i) ? "SET" : "NOT SET") << endl;
    }

    return 0;
}
