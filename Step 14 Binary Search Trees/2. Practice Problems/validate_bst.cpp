#include <iostream>

using namespace std;

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
  void inorder(TreeNode* root, TreeNode* &prev, bool &flag){
    if(root == NULL) return ;
    inorder(root->left, prev, flag);
    if(prev!=NULL){
      if( root->val <= prev->val ){
        flag = false;
        return ;
      }
    }
    prev = root;
    inorder(root->right, prev, flag);
  }
  bool isValidBST(TreeNode* root) {
    TreeNode* prev = NULL;
    bool flag =true;
    inorder(root, prev, flag);
    return flag;
  }
};

int main() {
  // Example usage:
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);

  Solution sol;
  bool isValid = sol.isValidBST(root);

  if (isValid) {
    cout << "The tree is a valid BST." << endl;
  } else {
    cout << "The tree is not a valid BST." << endl;
  }

  // Clean up memory (important to prevent memory leaks)
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}