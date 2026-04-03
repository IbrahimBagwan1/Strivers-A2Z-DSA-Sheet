#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool runDfs(int node, vector<int> & visited, vector<int> adjList[], vector<int> &pathVisited){
        visited[node]=1;
        pathVisited[node]=1;

        for(int vertex : adjList[node]){
            if(!visited[vertex]){
                if(runDfs(vertex, visited, adjList, pathVisited)) return true;
            }
            else if(pathVisited[vertex]){
                return true;
            } 
        }
        pathVisited[node]=0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjList[numCourses];
        int n = numCourses;
        for(auto edge : prerequisites){
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        for(int i=0; i<n; i++){
            if(runDfs(i, visited, adjList, pathVisited)) return false;
        }

        return true;
    }
};

int main(){
    Solution obj;
    
    // Test case 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1,0}};
    cout << "Test 1: " << (obj.canFinish(numCourses1, prerequisites1) ? "true" : "false") << endl;
    
    // Test case 2
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1,0}, {0,1}};
    cout << "Test 2: " << (obj.canFinish(numCourses2, prerequisites2) ? "true" : "false") << endl;
    
    return 0;
}