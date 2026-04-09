#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1); // Initialize size to 1, not 0
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findulp(int n) {
        if (n == parent[n]) return n;
        return parent[n] = findulp(parent[n]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findulp(u);
        int ulp_v = findulp(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DisjointSet ds(n);

        unordered_map<string,int> mp;

        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }
                else{
                    ds.unionBySize(mp[accounts[i][j]], i);
                }
            }
        }

        vector<vector<string>> mergedAccounts;
        vector<string> mergedMail[n];

        for(auto it : mp){
            int ultiParent = ds.findulp(it.second);
            string mail = it.first;
            mergedMail[ultiParent].push_back(mail);
        }

        for(int i=0; i<n; i++){
            if(mergedMail[i].size() == 0) continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }
            mergedAccounts.push_back(temp);
        }

        return mergedAccounts;
    }
};

int main() {
    Solution sol;
    
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "john00@mail.com", "john_newyork@mail.com"}
    };
    
    vector<vector<string>> result = sol.accountsMerge(accounts);
    
    cout << "Merged Accounts:\n";
    for (const auto& account : result) {
        for (int i = 0; i < account.size(); i++) {
            cout << account[i];
            if (i < account.size() - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
