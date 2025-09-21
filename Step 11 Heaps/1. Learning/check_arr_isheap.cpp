#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHeap(vector<int>& nums) {
        int n = nums.size();

        for(int i = 1; i < n; i++) {
            if(nums[(i-1)/2] > nums[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<int> heap1 = {1, 3, 5, 7, 9, 6};
    vector<int> heap2 = {10, 9, 8, 7, 6, 5};

    cout << "heap1 is a min-heap? " << (sol.isHeap(heap1) ? "Yes" : "No") << endl;
    cout << "heap2 is a min-heap? " << (sol.isHeap(heap2) ? "Yes" : "No") << endl;

    return 0;
}
