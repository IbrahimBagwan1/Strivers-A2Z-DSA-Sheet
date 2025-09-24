#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int sum = 1;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }

            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += down;
                i++;
                down++;
            }

            if (down > peak) {
                sum += (down - peak);
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;

    vector<int> ratings1 = {1, 0, 2};
    cout << "Minimum candies for {1, 0, 2}: " << sol.candy(ratings1) << endl;

    vector<int> ratings2 = {1, 2, 2};
    cout << "Minimum candies for {1, 2, 2}: " << sol.candy(ratings2) << endl;

    vector<int> ratings3 = {1, 3, 4, 5, 2};
    cout << "Minimum candies for {1, 3, 4, 5, 2}: " << sol.candy(ratings3) << endl;

    return 0;
}
