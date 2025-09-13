#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top(); st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int element = st.top(); st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }
        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3}; // sample input
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;
    return 0;
}
