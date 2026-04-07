#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;
public:

    DisjointSet(int n) {
        parent.resize(n+1, 0);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findulp(int n) {
        if (n == parent[n])
            return n;
        return parent[n] = findulp(parent[n]);
    }

    bool find(int u, int v) {
        int ulp_u = findulp(u);
        int ulp_v = findulp(v);
        return (ulp_u == ulp_v);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findulp(u);
        int ulp_v = findulp(v);
        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findulp(u);
        int ulp_v = findulp(v);
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main() {
    int n = 7;
    DisjointSet ds(n);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);

    cout << "After unionByRank operations:\n";
    cout << "find(1, 3): " << (ds.find(1, 3) ? "connected" : "not connected") << '\n';
    cout << "find(1, 4): " << (ds.find(1, 4) ? "connected" : "not connected") << '\n';

    ds.unionByRank(3, 4);
    cout << "find(1, 5): " << (ds.find(1, 5) ? "connected" : "not connected") << '\n';

    DisjointSet ds2(n);
    ds2.unionBySize(1, 2);
    ds2.unionBySize(3, 4);
    ds2.unionBySize(2, 4);

    cout << "\nAfter unionBySize operations:\n";
    cout << "find(1, 3): " << (ds2.find(1, 3) ? "connected" : "not connected") << '\n';
    cout << "find(5, 6): " << (ds2.find(5, 6) ? "connected" : "not connected") << '\n';

    return 0;
}
