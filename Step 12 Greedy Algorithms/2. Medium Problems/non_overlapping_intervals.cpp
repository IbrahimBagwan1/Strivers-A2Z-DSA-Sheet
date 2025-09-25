#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];  // sort by end time
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end(), cmp);

        int count = 1; // keep the first interval
        int lastEndTime = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastEndTime) {
                count++;  
                lastEndTime = intervals[i][1]; 
            }
        }

        return n - count;  // remove the rest
    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter intervals (start end):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    int result = s.eraseOverlapIntervals(intervals);
    cout << "Minimum intervals to remove = " << result << endl;

    return 0;
}
