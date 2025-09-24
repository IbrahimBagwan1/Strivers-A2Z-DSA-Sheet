#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure) {
        int n = Arrival.size();
        vector<pair<int,int>> trains;

        for (int i = 0; i < n; i++) {
            trains.push_back({Arrival[i], 0});   // 0 = arrival
            trains.push_back({Departure[i], 1}); // 1 = departure
        }

        // lambda syntax
        sort(trains.begin(), trains.end(), [](auto &a, auto &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        int count = 0, maxCount = 0;
        for (auto &ele : trains) {
            if (ele.second == 0) count++;  // arrival
            else count--;                  // departure
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

int main() {
    Solution sol;

    vector<int> Arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> Departure = {910, 1200, 1120, 1130, 1900, 2000};

    cout << "Minimum platforms required = "
         << sol.findPlatform(Arrival, Departure) << endl;

    return 0;
}
