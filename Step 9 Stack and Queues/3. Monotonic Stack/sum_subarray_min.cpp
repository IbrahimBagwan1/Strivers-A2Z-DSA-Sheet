#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Previous Smaller Element distances
    vector<int> previousSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return left;
    }

    // Next Smaller Element distances
    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        return right;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = previousSmallerElement(arr);
        vector<int> nse = nextSmallerElement(arr);
        
        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long contrib = (1LL * arr[i] * pse[i] % MOD * nse[i] % MOD) % MOD;
            total = (total + contrib) % MOD;
        }
        return (int)total;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of Subarray Minimums = " << sol.sumSubarrayMins(arr) << endl;

    // You can test more cases
    vector<int> arr2 = {11, 81, 94, 43, 3};
    cout << "Sum of Subarray Minimums = " << sol.sumSubarrayMins(arr2) << endl;

    return 0;
}
