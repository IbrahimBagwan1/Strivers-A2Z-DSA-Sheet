#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : data(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution{
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

    TreeNode* findNode(TreeNode* root, int start) {
      if(root == NULL) return NULL;
      if(root->data == start) return root;

      TreeNode* left = findNode(root->left, start);
      if(left) return left;

      return findNode(root->right, start);
    }



    int timeToBurnTree(TreeNode* root, int start){
      if(root == NULL) return 0;    
      unordered_map<TreeNode*, TreeNode*> mp;
      parents(mp, root);

      TreeNode* target = findNode(root, start);
      unordered_map<TreeNode*, bool> visited;

      queue<TreeNode*> q;
      q.push(target);
      visited[target] = true;
      int time=-1;

      while(!q.empty()){
        int size = q.size();
        time++;

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
      return time;
    }	
};

int main() {
  // Example usage:
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  Solution sol;
  int startNode = 2;
  int burnTime = sol.timeToBurnTree(root, startNode);

  cout << "Time to burn the tree starting from node " << startNode << ": " << burnTime << endl;

  return 0;
}