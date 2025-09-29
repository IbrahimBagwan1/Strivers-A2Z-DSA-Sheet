#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* findMin(TreeNode* root) {
      if(root == NULL) return NULL;
      TreeNode* cur = root;
      while(cur->left != NULL) {
        cur = cur->left;
      }
      return cur;
    }
    
    TreeNode* findMax(TreeNode* root) {
      if(root == NULL) return NULL;
      TreeNode* cur = root;
      while(cur->right != NULL) {
        cur = cur->right;
      }
      return cur;
    }
};

int main() {
    // Build sample BST:
    //        8
    //       / \
    //      3   10
    //     / \     \
    //    1   6     14
    //       / \    /
    //      4   7  13

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    Solution sol;

    TreeNode* minNode = sol.findMin(root);
    TreeNode* maxNode = sol.findMax(root);

    if(minNode) cout << "Minimum value in BST: " << minNode->val << endl;
    if(maxNode) cout << "Maximum value in BST: " << maxNode->val << endl;

    return 0;
}
