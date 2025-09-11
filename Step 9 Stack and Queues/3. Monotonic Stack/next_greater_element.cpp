#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp; // element -> next greater
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        vector<int> result;
        for (int num : nums1) {
            result.push_back(mp[num]);
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = sol.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
