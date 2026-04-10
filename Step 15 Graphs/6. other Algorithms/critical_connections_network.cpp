#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer=1;

    void dfs(int node, int parent, vector<int> &visited, vector<int> adj[], int tin[], int low[], vector<vector<int>> &critical){
        visited[node] =1;
        tin[node] = low[node] =timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(visited[it] ==0){
                dfs(it, node, visited, adj, tin, low, critical);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]){
                    critical.push_back({it, node});
                }
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> visited(n, 0);
        vector<int> adj[n];

        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }        

        int tin[n];
        int tlow[n];
        vector<vector<int>> critical;
        dfs(0, -1, visited, adj, tin, tlow, critical);
        return critical;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    int n1 = 4;
    vector<vector<int>> connections1 = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> result1 = sol.criticalConnections(n1, connections1);
    
    cout << "Test case 1: Critical connections in network of " << n1 << " computers:" << endl;
    for(auto conn : result1) {
        cout << "[" << conn[0] << "," << conn[1] << "] ";
    }
    cout << endl << endl;
    
    // Test case 2
    int n2 = 6;
    vector<vector<int>> connections2 = {{0,1},{0,2},{1,2},{2,3},{3,4},{4,5},{5,3}};
    vector<vector<int>> result2 = sol.criticalConnections(n2, connections2);
    
    cout << "Test case 2: Critical connections in network of " << n2 << " computers:" << endl;
    for(auto conn : result2) {
        cout << "[" << conn[0] << "," << conn[1] << "] ";
    }
    cout << endl;
    
    return 0;
}
