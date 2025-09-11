#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lMax = 0, rMax = 0, r = n - 1, l = 0;
        int totalWater = 0;

        while (l <= r) {
            if (height[l] <= height[r]) {
                if (lMax > height[l]) {
                    totalWater += lMax - height[l];
                } else {
                    lMax = height[l];
                }
                l++;
            } else {
                if (rMax > height[r]) {
                    totalWater += rMax - height[r];
                } else {
                    rMax = height[r];
                }
                r--;
            }
        }
        return totalWater;
    }
};

int main() {
    Solution sol;
    vector<int> height = {4, 2, 0, 3, 2, 5}; // Example input
    cout << "Trapped Water = " << sol.trap(height) << endl;
    return 0;
}
