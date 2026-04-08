#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;
public:

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

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), cmp);
    DisjointSet ds(n);
    int sum = 0;
    for(auto& e : edges) {
        if(!ds.find(e.u, e.v)) {
            ds.unionByRank(e.u, e.v);
            sum += e.w;
        }
    }
    return sum;
}

int main() {
    int n = 6;
    vector<Edge> edges = {
        {0,1,4},
        {0,2,4},
        {1,2,2},
        {1,3,5},
        {2,3,5},
        {2,4,9},
        {3,4,4},
        {4,5,6},
        {3,5,7}
    };
    int mst = kruskal(edges, n);
    cout << "MST weight: " << mst << endl;
    return 0;
}