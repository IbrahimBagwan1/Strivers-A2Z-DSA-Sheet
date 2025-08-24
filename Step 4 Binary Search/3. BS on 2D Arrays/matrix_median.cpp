#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count_less(vector<vector<int>>&matrix, int n, int m, int x) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin();
        }
        return count;
    }
    
    int findMedian(vector<vector<int>>&matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = INT_MAX;
        int right = INT_MIN;

        for (int i = 0; i < n; i++) {
            left = min(matrix[i][0], left);
            right = max(matrix[i][m-1], right);
        }

        int req = (m * n) / 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            int sumequals = count_less(matrix, n, m, mid);

            if (sumequals <= req) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};

int main() {
    // 🔹 Hardcoded matrix (each row is sorted)
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    Solution sol;
    int median = sol.findMedian(matrix);

    cout << "Median of matrix is: " << median << endl;
    return 0;
}
