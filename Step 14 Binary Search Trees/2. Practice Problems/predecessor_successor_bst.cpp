#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  vector<int> findPreSuc(TreeNode* root, int key) {
    int pred = -1, succ = -1;
    TreeNode* cur = root;

    while(cur) {
      if(cur->data == key) {
        // check left subtree for predecessor
        if(cur->left) {
          TreeNode* temp = cur->left;
          while(temp->right) temp = temp->right;
          pred = temp->data;
        }
        // check right subtree for successor
        if(cur->right) {
          TreeNode* temp = cur->right;
          while(temp->left) temp = temp->left;
          succ = temp->data;
        }
        break;
      }
      else if(cur->data > key) {
        succ = cur->data; // possible successor
        cur = cur->left;
      }
      else {
        pred = cur->data; // possible predecessor
        cur = cur->right;
      }
    }

    return {pred, succ};
  }
};

int main() {
  // Example usage:
  TreeNode* root = new TreeNode(50);
  root->left = new TreeNode(30);
  root->right = new TreeNode(70);
  root->left->left = new TreeNode(20);
  root->left->right = new TreeNode(40);
  root->right->left = new TreeNode(60);
  root->right->right = new TreeNode(80);

  Solution sol;
  vector<int> result = sol.findPreSuc(root, 60);

  cout << "Predecessor: " << result[0] << endl;
  cout << "Successor: " << result[1] << endl;

  // Clean up memory (important to prevent memory leaks)
  delete root->left->left;
  delete root->left->right;
  delete root->right->left;
  delete root->right->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}