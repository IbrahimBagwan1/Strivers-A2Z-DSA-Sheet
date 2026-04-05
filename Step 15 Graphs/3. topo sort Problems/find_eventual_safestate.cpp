#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // use concept of indegree, and topological sort.
        // first reverse the edges of the graph.
        int m = graph.size();

        vector<int> indegree(m, 0);
        vector<int> adj[m];
        for(int i=0; i<m; i++){
            for(int it: graph[i]    ){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> topo;
        for(int i=0; i<m; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        sort(topo.begin(), topo.end());
        return topo;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<vector<int>> graph1 = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> result1 = sol.eventualSafeNodes(graph1);
    cout << "Test case 1: ";
    for(int node : result1) cout << node << " ";
    cout << endl;
    
    // Test case 2
    vector<vector<int>> graph2 = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    vector<int> result2 = sol.eventualSafeNodes(graph2);
    cout << "Test case 2: ";
    for(int node : result2) cout << node << " ";
    cout << endl;
    
    // Test case 3
    vector<vector<int>> graph3 = {{},{0,2,3,4},{3},{4},{}};
    vector<int> result3 = sol.eventualSafeNodes(graph3);
    cout << "Test case 3: ";
    for(int node : result3) cout << node << " ";
    cout << endl;
    
    return 0;
}
