#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool helper(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        if(root1->val != root2->val) return false;

        bool first = helper(root1->left, root2->right);
        bool second = helper(root1->right, root2->left);
        return (first && second);
    }

    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
};

int main() {
    /*
       Example tree (symmetric):
               1
             /   \
            2     2
           / \   / \
          3   4 4   3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    if(sol.isSymmetric(root))
        cout << "Tree is symmetric" << endl;
    else
        cout << "Tree is not symmetric" << endl;

    return 0;
}
