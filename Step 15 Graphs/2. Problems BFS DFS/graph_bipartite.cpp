#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, int col, vector<int> & color,  vector<vector<int>>& graph){
        color[node] = col;

        for(auto it: graph[node]){
            if(color[it]==-1){
                if(dfs(it, !col, color, graph)==false) return false;
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();

        vector<int> color(m, -1);
        
        for(int i=0; i<m; i++){
            if(color[i]==-1){
                if(dfs(i, 0, color, graph)==false) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // Hardcoded input 1: Bipartite graph (complete bipartite K_{3,3})
    vector<vector<int>> graph1 = {{3,4,5},{3,4,5},{3,4,5},{0,1,2},{0,1,2},{0,1,2}};
    cout << "Graph 1 is bipartite: " << (sol.isBipartite(graph1) ? "true" : "false") << endl;
    
    // Hardcoded input 2: Not bipartite (odd cycle C5)
    vector<vector<int>> graph2 = {{1},{0,2},{1,3},{2,4},{3,0}};
    cout << "Graph 2 is bipartite: " << (sol.isBipartite(graph2) ? "true" : "false") << endl;
    
    // Hardcoded input 3: Complex graph with multiple components, some bipartite, overall not (contains odd cycle)
    vector<vector<int>> graph3 = {{1,2},{0,2,3},{0,1,3,4},{1,2,5},{2,5,6},{3,4,7},{4,7},{5,6,8},{7,9},{8,10},{9,11},{10,11}}; // This has an odd cycle in later parts
    cout << "Graph 3 is bipartite: " << (sol.isBipartite(graph3) ? "true" : "false") << endl;
    
    return 0;
}