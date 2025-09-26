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
    int helper(TreeNode* root, int &maxi) {
        if (root == NULL) return 0;

        // Recursively get max path sum from left and right
        int leftSum = max(0, helper(root->left, maxi));   // ignore negatives
        int rightSum = max(0, helper(root->right, maxi)); // ignore negatives

        // Update maxi with the best path passing through this node
        maxi = max(maxi, leftSum + rightSum + root->val);

        // Return the best one-sided path sum upward
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; // handle all-negative case
        helper(root, maxi);
        return maxi;
    }
};

// Example usage
int main() {
    /*
            -10
            /  \
           9   20
              /  \
             15   7
    Expected maximum path sum = 42 (15 + 20 + 7)
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Path Sum = " << sol.maxPathSum(root) << endl;

    return 0;
}
