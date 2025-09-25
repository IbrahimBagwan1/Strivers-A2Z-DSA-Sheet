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
    int maxDiameter(TreeNode* root, int &dia) {
        if (root == NULL) return 0;
        int left = maxDiameter(root->left, dia);
        int right = maxDiameter(root->right, dia);

        dia = max(dia, left + right);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int dia = 0;
        maxDiameter(root, dia);
        return dia;
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

    cout << "Diameter of Binary Tree: " << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}
