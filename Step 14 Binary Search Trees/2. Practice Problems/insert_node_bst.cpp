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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* cur ;
    TreeNode* prev ;
    TreeNode* temp = new TreeNode();
    temp->val = val;
    temp->left =NULL;
    temp->right = NULL;
    if(root == NULL) return temp;
    prev = NULL;
    cur = root;
    while(cur){
      prev =cur;
      if(val > cur->val){
        cur =cur->right;
      }
      else{
        cur = cur->left;
      }
    }
    if(prev->val > val){
      prev->left = temp;
    }
    else{
      prev->right = temp;
    }
    return root;
  }
};

int main() {
  // Create a sample BST
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  Solution sol;
  root = sol.insertIntoBST(root, 5);

  // You can add code here to print or verify the BST after insertion
  // For example, an inorder traversal to check the order.

  return 0;
}