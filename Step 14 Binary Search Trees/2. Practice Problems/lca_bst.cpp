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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;
    if(root == p || root == q ) return root;

    if(root->val < p->val && root->val < q->val){
      return lowestCommonAncestor(root->right, p,q);
    }
    if(root->val > p->val && root->val > q->val){
      return lowestCommonAncestor(root->left, p, q);
    }
    return root;
  }
};

int main() {
  // Create a sample BST
  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);

  Solution sol;

  // Find LCA of nodes with values 2 and 8
  TreeNode* p = root->left; // Node with value 2
  TreeNode* q = root->right; // Node with value 8
  TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
  std::cout << "LCA of 2 and 8: " << lca->val << std::endl; // Expected: 6

  // Find LCA of nodes with values 2 and 4
  p = root->left; // Node with value 2
  q = root->left->right; // Node with value 4
  lca = sol.lowestCommonAncestor(root, p, q);
  std::cout << "LCA of 2 and 4: " << lca->val << std::endl; // Expected: 2

  // Clean up memory (important to avoid memory leaks)
  // (Note: A more robust solution would use a recursive or iterative approach to delete the entire tree)
  delete root->left->right->left;
  delete root->left->right->right;
  delete root->left->right;
  delete root->left->left;
  delete root->right->left;
  delete root->right->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}