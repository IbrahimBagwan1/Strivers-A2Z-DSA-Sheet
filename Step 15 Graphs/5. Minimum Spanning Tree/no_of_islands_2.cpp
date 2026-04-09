#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int visited[n][m];
        memset(visited, 0, sizeof visited);
        
        DisjointSet ds(n*m);
        
        vector<int> nIslands;
        int land = 0;
        
        int drow[] = {-1, 1,  0, 0};
        int dcol[] = { 0, 0, -1, 1};
        
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            
            if(visited[row][col]==1){
                nIslands.push_back(land);
                continue;
            }
            
            visited[row][col] =1;
            land++;
            
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow < n && nrow>=0 && ncol <m && ncol>=0 ){
                    if(visited[nrow][ncol] ==1){
                        int oldNode = row * m + col;
                        int newNode = nrow * m + ncol;
                        if(ds.findulp(oldNode) != ds.findulp(newNode)){
                            land--;
                            ds.unionBySize(oldNode, newNode);
                        }
                    }
                }
            }
            nIslands.push_back(land);
            
        }
        return nIslands;
        
    }
};

int main() {
    Solution sol;
    
    int n = 4, m = 5;
    vector<vector<int>> operators = {
        {1, 1}, {0, 1}, {3, 3}, {3, 4}
    };
    
    vector<int> result = sol.numOfIslands(n, m, operators);
    
    cout << "Number of islands after each operation: ";
    for (int island : result) {
        cout << island << " ";
    }
    cout << endl;
    
    return 0;
}