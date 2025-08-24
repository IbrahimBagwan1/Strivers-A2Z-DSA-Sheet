#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans = {1, 1};
        int n = mat.size();
        int m = mat[0].size();

        int left = 0;
        int right = m - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int maxVal = -1;
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (maxVal < mat[i][mid]) {
                    maxVal = mat[i][mid];
                    idx = i;
                }
            }

            int left_elem = (mid - 1 >= 0) ? mat[idx][mid - 1] : -1;
            int right_elem = (mid + 1 < m) ? mat[idx][mid + 1] : -1;

            if (mat[idx][mid] > right_elem && mat[idx][mid] > left_elem) {
                return {idx, mid};
            } else if (mat[idx][mid] < left_elem) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    // Matrix with boundary elements = -1
    vector<vector<int>> mat = {
        {-1, -1, -1, -1, -1},
        {-1, 10,  8, 10, -1},
        {-1, 14, 13, 12, -1},
        {-1, 15,  9, 11, -1},
        {-1, -1, -1, -1, -1}
    };

    Solution sol;
    vector<int> peak = sol.findPeakGrid(mat);

    cout << "Peak element at index: (" << peak[0] << ", " << peak[1] << ")\n";
    cout << "Peak value: " << mat[peak[0]][peak[1]] << endl;

    return 0;
}
