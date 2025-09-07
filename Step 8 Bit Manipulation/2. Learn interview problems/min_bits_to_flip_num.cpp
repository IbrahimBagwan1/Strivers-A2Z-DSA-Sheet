#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = start ^ goal;
        return __builtin_popcount(count);
    }
};

int main() {
    Solution sol;
    int start, goal;

    cout << "Enter start number: ";
    cin >> start;
    cout << "Enter goal number: ";
    cin >> goal;

    int flips = sol.minBitFlips(start, goal);
    cout << "Minimum bit flips required: " << flips << endl;

    return 0;
}
