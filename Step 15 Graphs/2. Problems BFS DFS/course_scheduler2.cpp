#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int node, vector<int> & visited, vector<int> & pathVisited, vector<int> &topoSearch, vector<int> prerequisites[]){
        visited[node]=1;
        pathVisited[node]=1;

        for(int it : prerequisites[node]){
            if(!visited[it]){
                if(dfs(it, visited, pathVisited, topoSearch, prerequisites)==false) return false;
            }
            else if(pathVisited[it]) return false;
        }
        pathVisited[node]=0;
        topoSearch.push_back(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        vector<int> adj[numCourses];
        for(auto &edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> topoSearch;
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(i, visited, pathVisited, topoSearch, adj)==false) return {};
            }
        }
        reverse(topoSearch.begin(), topoSearch.end());
        return topoSearch;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int numCourses1 = 4;
    vector<vector<int>> prerequisites1 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> result1 = sol.findOrder(numCourses1, prerequisites1);
    cout << "Test Case 1: ";
    for(int course : result1) cout << course << " ";
    cout << endl;
    
    // Test Case 2
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}};
    vector<int> result2 = sol.findOrder(numCourses2, prerequisites2);
    cout << "Test Case 2: ";
    for(int course : result2) cout << course << " ";
    cout << endl;
    
    // Test Case 3
    int numCourses3 = 3;
    vector<vector<int>> prerequisites3 = {{1, 0}, {1, 2}, {0, 1}};
    vector<int> result3 = sol.findOrder(numCourses3, prerequisites3);
    cout << "Test Case 3: ";
    if(result3.empty()) cout << "Cycle Detected!";
    else for(int course : result3) cout << course << " ";
    cout << endl;
    
    return 0;
}
