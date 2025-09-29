#include <iostream>
#include <vector>
#include <climits>
#include <functional>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
  TreeNode* helper(vector<int>& preorder, int &i, int bound) {
    if(i== preorder.size() || preorder[i] > bound) return NULL;

    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = helper(preorder, i, root->val);
    root->right = helper(preorder, i, bound);
    return root;
  }
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i =0;
    return helper(preorder, i, INT_MAX);
  }
};

int main() {
  Solution sol;
  vector<int> preorder = {8,5,1,7,10,12};
  TreeNode* root = sol.bstFromPreorder(preorder);
  
  function<void(TreeNode*)> inorder = [&](TreeNode* root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
  };

  inorder(root);
  cout << endl;
  return 0;
}