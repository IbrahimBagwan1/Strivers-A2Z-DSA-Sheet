#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
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

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = previousSmallerElement(arr);
        vector<int> nse = nextSmallerElement(arr);
        
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += 1LL * arr[i] * pse[i] * nse[i];
        }
        return total;
    }

    // Previous Greater Element distances
    vector<int> previousGreaterElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return left;
    }

    // Next Greater Element distances
    vector<int> nextGreaterElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        return right;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = previousGreaterElement(arr);
        vector<int> nse = nextGreaterElement(arr);
        
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += 1LL * arr[i] * pse[i] * nse[i];
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};
    
    cout << "Sum of Subarray Minimums: " << sol.sumSubarrayMins(nums) << endl;
    cout << "Sum of Subarray Maximums: " << sol.sumSubarrayMaxs(nums) << endl;
    cout << "Sum of Subarray Ranges (Max - Min): " << sol.subArrayRanges(nums) << endl;

    return 0;
}
