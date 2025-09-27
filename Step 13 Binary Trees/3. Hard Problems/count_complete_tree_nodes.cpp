#include <iostream>

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
  int leftHeight(TreeNode* root){
    int count =0;
    while(root){
      count++;
      root = root->left;
    }
    return count;
  }

  int rightHeight(TreeNode* root){
    int count =0;
    while(root){
      count++;
      root = root->right;
    }
    return count;
  }

  int countNodes(TreeNode* root) {
    if(root == NULL) return 0;
    
    int leftHt = leftHeight(root);
    int rightHt = rightHeight(root);

    if(leftHt == rightHt){
      return (1 << leftHt )-1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};

int main() {
  // Create a sample complete binary tree
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);

  Solution sol;
  int nodeCount = sol.countNodes(root);

  std::cout << "Number of nodes in the complete binary tree: " << nodeCount << std::endl;

  // Clean up memory (important to avoid memory leaks)
  delete root->left->left;
  delete root->left->right;
  delete root->right->left;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}