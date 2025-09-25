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
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);

        if (abs(left - right) > 1) {
            return -1; // not balanced
        }
        if (left == -1 || right == -1) return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return (height(root) == -1) ? false : true;
    }
};

// Helper function to build a sample balanced tree
TreeNode* buildBalancedTree() {
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

// Helper function to build an unbalanced tree
TreeNode* buildUnbalancedTree() {
    /*
           1
          /
         2
        /
       3
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;

    TreeNode* balancedRoot = buildBalancedTree();
    TreeNode* unbalancedRoot = buildUnbalancedTree();

    cout << "Is Balanced Tree 1? " << (sol.isBalanced(balancedRoot) ? "Yes" : "No") << endl;
    cout << "Is Balanced Tree 2? " << (sol.isBalanced(unbalancedRoot) ? "Yes" : "No") << endl;

    return 0;
}
