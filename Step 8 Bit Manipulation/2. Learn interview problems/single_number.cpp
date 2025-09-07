#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        for(int i = 0; i < n; i++) {
            xorr ^= nums[i];
        }
        return xorr;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.singleNumber(nums);
    cout << "The single number is: " << result << endl;

    return 0;
}
