#include <bits/stdc++.h>
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
    int helperHeight(TreeNode* root, int ht) {
        if (root == NULL) {
            return ht;
        }
        int leftHt = helperHeight(root->left, ht + 1);
        int rightHt = helperHeight(root->right, ht + 1);
        return max(leftHt, rightHt);
    }

    int maxDepth(TreeNode* root) {
        return helperHeight(root, 0);
    }
};

// Helper function to build a sample tree
TreeNode* buildTree() {
    /*
           1
          / \
         2   3
        / \
       4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildTree();

    cout << "Maximum Depth of Tree: " << sol.maxDepth(root) << endl;

    return 0;
}
