#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());

        int n = bt.size();
        int sum = 0;
        int finalSum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += bt[i];
            finalSum += sum;
        }

        return finalSum / n;  // Average waiting time
    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> bt(n);
    cout << "Enter burst times: ";
    for (int i = 0; i < n; i++) {
        cin >> bt[i];
    }

    long long result = s.solve(bt);
    cout << "Average waiting time = " << result << endl;

    return 0;
}
