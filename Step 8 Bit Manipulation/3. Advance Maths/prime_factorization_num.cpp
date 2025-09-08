#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> primeFactors(vector<int>& queries) {
        vector<vector<int>> ans;

        for (int num : queries) {
            vector<int> temp;

            for (int i = 2; i * i <= num; i++) {
                while (num % i == 0) {
                    temp.push_back(i);
                    num /= i;
                }
            }
            if (num > 1) temp.push_back(num); // remaining prime
            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> queries = {2, 3, 4, 5, 6, 12, 18};

    vector<vector<int>> result = sol.primeFactors(queries);

    for (int i = 0; i < result.size(); i++) {
        cout << "Prime factors of " << queries[i] << ": ";
        for (int x : result[i]) cout << x << " ";
        cout << endl;
    }
    return 0;
}
