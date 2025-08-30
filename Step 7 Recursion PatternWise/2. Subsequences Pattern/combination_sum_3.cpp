#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helperCombinationSum3(vector<vector<int>> &ans, vector<int> &temp, int k, int n, int idx){
        if(k == 0){
            if(n == 0) ans.push_back(temp);
            return;
        }
        for(int i = idx; i <= 9; i++){
            if(i > n) break;
            temp.push_back(i);
            helperCombinationSum3(ans, temp, k-1, n-i, i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helperCombinationSum3(ans, temp, k, n, 1);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    if(!(cin >> k >> n)) return 0;

    Solution sol;
    auto res = sol.combinationSum3(k, n);

    for(const auto &comb : res){
        cout << "[";
        for(size_t i = 0; i < comb.size(); ++i){
            if(i) cout << ",";
            cout << comb[i];
        }
        cout << "]\n";
    }

    return 0;
}
