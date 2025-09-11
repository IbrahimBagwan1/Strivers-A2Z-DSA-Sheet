#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextGreater(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            int curr = nums[i % n];

            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if (!st.empty() && i < n) {
                nextGreater[i] = st.top();
            }

            st.push(curr);
        }

        return nextGreater;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
