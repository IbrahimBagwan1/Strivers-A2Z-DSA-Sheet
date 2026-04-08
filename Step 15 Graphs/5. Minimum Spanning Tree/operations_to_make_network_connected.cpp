#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank, size;

    DisjointSet(int n) {
        parent.resize(n+1, 0);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);

        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findulp(int n){
        if(n == parent[n]) return n;
        return parent[n] = findulp(parent[n]);
    }

    bool find(int u, int v) {
        int ulp_u = findulp(u);
        int ulp_v = findulp(v);
        return (ulp_u==ulp_v);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findulp(u);
        int ulp_v = findulp(v);
        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findulp(u);
        int ulp_v = findulp(v);
        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int cntExtra = 0;

        for(auto it: connections){
            int u = it[0];
            int v = it[1];

            if(ds.findulp(u) == ds.findulp(v)){
                cntExtra++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }

        int cntNC = 0;

        for(int i=0; i<n ; i++){
            if(ds.parent[i] == i) cntNC++;
        }

        int ans = cntNC-1;

        if(cntExtra >= ans ) return ans;
        return -1;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    
    Solution sol;
    int result = sol.makeConnected(n, connections);
    
    cout << "Minimum operations needed: " << result << endl;
    
    return 0;
}
