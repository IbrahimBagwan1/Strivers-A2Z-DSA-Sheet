#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& nums) {
        int n = nums.size();
        vector<int> nextSmaller(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            int current = nums[i];

            // Pop all greater or equal elements
            while (!st.empty() && st.top() >= current) {
                st.pop();
            }

            // If stack not empty, top is the next smaller
            if (!st.empty()) {
                nextSmaller[i] = st.top();
            }

            // Push current element
            st.push(current);
        }

        return nextSmaller;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 8, 5, 2, 25};
    vector<int> result = sol.nextSmallerElements(nums);

    cout << "Next Smaller Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
