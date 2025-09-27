#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  void parents(unordered_map<TreeNode*, TreeNode*> &mp, TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
      TreeNode* node = q.front(); q.pop();
      if(node->left){
        mp[node->left] = node;
        q.push(node->left);
      }
      if(node->right){
        mp[node->right] = node;
        q.push(node->right);
      }
    }
  }

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> mp;
    parents(mp, root);

    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int dist=0;

    while(!q.empty()){
      int size = q.size();
      if(dist++ == k) break;

      for(int i=0; i<size; i++){
        TreeNode* node = q.front(); q.pop();

        if(node->left && !visited[node->left]){
          q.push(node->left);
          visited[node->left] = true;
        }
        if(node->right && !visited[node->right]){
          q.push(node->right);
          visited[node->right] = true;
        }

        if(mp[node] && !visited[mp[node]]){
          q.push(mp[node]);
          visited[mp[node]] = true;
        }
      }

    }
    vector<int> traversal;
    while(!q.empty()){
      traversal.push_back(q.front()->val);
      q.pop();
    }
    return traversal;
  }
};

int main() {
  // Create a sample binary tree
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  // Target node
  TreeNode* target = root->left; // Node with value 5

  // Distance k
  int k = 2;

  // Create a Solution object
  Solution sol;

  // Find nodes at distance k from the target node
  vector<int> result = sol.distanceK(root, target, k);

  // Print the result
  cout << "Nodes at distance " << k << " from target node (" << target->val << "): ";
  for (int val : result) {
    cout << val << " ";
  }
  cout << endl;

  // Clean up memory (important to avoid memory leaks)
  // (Add code to delete all nodes in the tree if needed)

  return 0;
}