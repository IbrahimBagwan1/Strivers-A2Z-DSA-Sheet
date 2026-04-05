#include <bits/stdc++.h>
using namespace std;

vector<int> kahnAlgo(vector<vector<int>>& adj, int n){
  vector<int> indegree(n, 0);


  for(int i=0; i<n; i++){
    for(int it: adj[i]){
      indegree[it]++;
    }
  }

  queue<int> q;

  for(int i=0; i<n; i++){
    if(indegree[i]==0){
      q.push(i);
    }
  }
  vector<int> topo;

  while(!q.empty()){
    int node = q.front();
    q.pop();
    topo.push_back(node);

    for(int i=0; i<adj[node].size(); i++){
      indegree[adj[node][i]]--;
      if(indegree[adj[node][i]]==0){
        q.push(adj[node][i]);
      }
    }
  }

  return topo;

}


int main() {
    // Test case 1: Simple chain 0 -> 1 -> 2
    int n1 = 3;
    vector<vector<int>> adj1 = {{1}, {2}, {}};
    vector<int> res1 = kahnAlgo(adj1, n1);
    cout << "Test 1: ";
    for (int x : res1) cout << x << " ";
    cout << (res1.size() == n1 ? "Success" : "Fail") << endl;

    // Test case 2: Multiple dependencies 0 -> 1, 0 -> 2, 1 -> 3, 2 -> 3
    int n2 = 4;
    vector<vector<int>> adj2 = {{1, 2}, {3}, {3}, {}};
    vector<int> res2 = kahnAlgo(adj2, n2);
    cout << "Test 2: ";
    for (int x : res2) cout << x << " ";
    cout << (res2.size() == n2 ? "Success" : "Fail") << endl;

    // Test case 3: Single node, no edges
    int n3 = 1;
    vector<vector<int>> adj3 = {{}};
    vector<int> res3 = kahnAlgo(adj3, n3);
    cout << "Test 3: ";
    for (int x : res3) cout << x << " ";
    cout << (res3.size() == n3 ? "Success" : "Fail") << endl;

    // Test case 4: Cycle 0 -> 1 -> 0
    int n4 = 2;
    vector<vector<int>> adj4 = {{1}, {0}};
    vector<int> res4 = kahnAlgo(adj4, n4);
    cout << "Test 4: ";
    for (int x : res4) cout << x << " ";
    cout << (res4.size() == n4 ? "Success" : "Fail") << endl;

    // Test case 5: Complex graph
    int n5 = 5;
    vector<vector<int>> adj5 = {{1, 2}, {3}, {3, 4}, {}, {}};
    vector<int> res5 = kahnAlgo(adj5, n5);
    cout << "Test 5: ";
    for (int x : res5) cout << x << " ";
    cout << (res5.size() == n5 ? "Success" : "Fail") << endl;

    return 0;
}