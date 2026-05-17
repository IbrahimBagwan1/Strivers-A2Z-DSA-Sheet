#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }
        return maxArea;
    }

    void convertBarMatrix(vector<vector<int>>& barmatrix, vector<vector<char>>& matrix, int n, int m) {
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[j][i] != '0') {
                    barmatrix[j][i] = (matrix[j][i] - '0') + sum;
                    sum += (matrix[j][i] - '0');
                } else {
                    barmatrix[j][i] = 0;
                    sum = 0;
                }
            }
        }
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> barMatrix(n, vector<int>(m, 0));
        convertBarMatrix(barMatrix, matrix, n, m);

        int maxRec = 0;
        for (int i = 0; i < n; i++) {
            maxRec = max(maxRec, largestRectangleArea(barMatrix[i]));
        }
        return maxRec;
    }
};

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    Solution solution;
    int result = solution.maximalRectangle(matrix);
    cout << "Maximum rectangle area: " << result << '\n';
    return 0;
}
